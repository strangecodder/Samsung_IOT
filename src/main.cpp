#include <mbed.h>

DigitalIn buttonS1(A2);
DigitalIn buttonS2(A3);
DigitalIn buttonS3(D3);
DigitalIn buttonS4(D6);
 
DigitalOut rele(A0);
DigitalOut led(LED1);

int password = 3442;

int pressButton()
{  
  if(buttonS1==0){
      printf("%s","1");
      return 1;
  } if(buttonS2==0){
      printf("%s","2");
      return 2;
  } if(buttonS3==0){
      printf("%s","3");
      return 3;
  } if(buttonS4==0){
      printf("%s","4");
      return 4;
  }
}

bool passwordVerification(string userPassword)
{
  int check = stoi(userPassword);
  if (check==password)
  {
    return true;
  } 
  else{
    return false;
    }
}

int main() {
  printf("%s","Введите пароль: ");
  while(1)
  {
    string userPassword;
    for(int i = 0; i<3;i++)
    {
      userPassword+=pressButton();
    }
     if(passwordVerification(userPassword))
     {
      int i = 0;
      rele = 1;
      while (i <= 10000)
      {
        led = !led;
        thread_sleep_for(1000);
        i += 1000;
      }
      rele = 1;
      thread_sleep_for(10000);
      rele = 0;
     }else{
      printf("%s", "Неверный пароль, введите его ещё раз");
     }
  }
}