#include <cstdio>

bool leap(int Y){
  return (Y%400==0)||((Y%4==0)&&(Y%100!=0));
}

int main(){
  int Y;
  scanf("%d",&Y);
  int Z=Y;
  int sum=0;
  do{
    sum+=leap(Y)?366:365;
    Y++;
  }while(sum%7!=0||leap(Y)!=leap(Z));
  printf("%d\n",Y);
}