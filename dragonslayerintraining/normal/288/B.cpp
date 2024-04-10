#include <cstdio>
#include <stdint.h>

const int64_t MOD=1e9+7;

int64_t modpow(int64_t base,int64_t exp){
  int64_t ac=1;
  for(int64_t k=0;k<30;k++){
    if(exp&(1<<k)){
      ac=(ac*base)%MOD;
    }
    base=(base*base)%MOD;
  }
  return ac;
}

int main(){
  int64_t N,K;
  scanf("%I64d %I64d",&N,&K);
  printf("%I64d\n",(modpow(K,K-1)*modpow(N-K,N-K))%MOD);
}