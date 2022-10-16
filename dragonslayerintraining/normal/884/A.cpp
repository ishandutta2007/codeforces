#include <cstdio>

int main(){
  int N,T;
  scanf("%d %d",&N,&T);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    T-=(86400-A);
    if(T<=0){
      printf("%d\n",i+1);
      return 0;
    }
  }
  return 0;
}