#include <cstdio>

int N,X,Y;

int main(){
  scanf("%d %d %d",&N,&X,&Y);
  if(X>Y){
    printf("%d\n",N);
    return 0;
  }
  int cnt=0;
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    cnt+=(A<=X);
  }
  printf("%d\n",(cnt+1)/2);
  return 0;
}