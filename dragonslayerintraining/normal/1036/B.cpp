#include <cstdio>
#include <stdint.h>

int main(){
  int64_t Q;
  scanf("%I64d",&Q);
  while(Q-->0){
    int64_t N,M,K;
    scanf("%I64d %I64d %I64d",&N,&M,&K);
    if(N>K||M>K){
      printf("-1\n");
    }else{
      printf("%I64d\n",K-(K+N)%2-(K+M)%2);
    }
  }
  return 0;
}