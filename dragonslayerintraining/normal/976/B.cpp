#include <cstdio>
#include <stdint.h>

int main(){
  int64_t N,M,K;
  scanf("%I64d %I64d %I64d",&N,&M,&K);
  if(K<N){
    printf("%I64d 1\n",K+1);
  }else{
    K-=N;
    if(K%(2*(M-1))<M-1){
      printf("%I64d %I64d\n",N-K/(M-1),K%(M-1)+2);
    }else{
      printf("%I64d %I64d\n",N-K/(M-1),M-K%(M-1));
    }
  }
  return 0;
}