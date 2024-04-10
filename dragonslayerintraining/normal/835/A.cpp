#include <cstdio>

int S,V1,V2,T1,T2;

int main(){
  scanf("%d %d %d %d %d",&S,&V1,&V2,&T1,&T2);
  int time1=T1*2+S*V1;
  int time2=T2*2+S*V2;
  if(time1<time2){
    printf("First\n");
  }else if(time1>time2){
    printf("Second\n");
  }else{
    printf("Friendship\n");
  }
  return 0;
}