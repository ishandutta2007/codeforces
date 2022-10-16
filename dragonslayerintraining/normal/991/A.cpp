#include <cstdio>

int main(){
  int A,B,C,N;
  scanf("%d %d %d %d",&A,&B,&C,&N);
  int X=N-A-B+C;
  if(C>A||C>B||X<=0){
    printf("-1\n");
  }else{
    printf("%d\n",X);
  }
  return 0;
}