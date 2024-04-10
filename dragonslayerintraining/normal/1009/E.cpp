#include <cstdio>
#include <stdint.h>

const int64_t MOD=998244353;

int64_t modpow(int64_t base,int64_t exp){
  int64_t ac=1;
  for(;exp>0;exp>>=1){
    if(exp&1) ac=ac*base%MOD;
    base=base*base%MOD;
  }
  return ac;
}

int64_t as[1000006];

int64_t inv2[1000006];

int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&as[i]);
  }
  inv2[0]=1;
  inv2[1]=modpow(2,MOD-2);
  for(int64_t i=2;i<=N;i++){
    inv2[i]=inv2[i-1]*inv2[1]%MOD;
  }
  int64_t ac=0;
  int64_t sum=0;
  for(int64_t i=0;i<N;i++){
    int64_t add=inv2[i+1]*as[i];
    ac=(ac+add)%MOD;
    sum=(sum+ac+add)%MOD;
    //printf("AT %I64d: %I64d\n",i,(ac+add)%MOD);
  }
  printf("%I64d\n",sum*modpow(2,N-1)%MOD);
  return 0;
}