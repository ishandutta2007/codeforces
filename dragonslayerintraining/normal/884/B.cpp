#include <cstdio>

int main(){
  int N,X;
  scanf("%d %d",&N,&X);
  X-=(N-1);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    X-=A;
  }
  if(X==0){
    printf("YES\n");
  }else{
    printf("NO\n");
  }
  return 0;
}