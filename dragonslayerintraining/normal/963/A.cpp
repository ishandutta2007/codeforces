#include <cstdio>
#include <stdint.h>

const int64_t MOD=1e9+9;

int64_t ss[100000];

int64_t modpow(int64_t base,int64_t exp){
  int64_t ac=1;
  for(;exp>0;exp>>=1){
    if(exp&1){
      ac=ac*base%MOD;
    }
    base=base*base%MOD;
  }
  return ac;
}

int64_t inverse(int64_t x){
  return modpow(x,MOD-2);
}

int main(){
  int64_t N,A,B,K;
  scanf("%I64d %I64d %I64d %I64d",&N,&A,&B,&K);
  N++;
  for(int64_t i=0;i<K;i++){
    char c;
    scanf(" %c",&c);
    ss[i]=(c=='+')?1:(MOD-1);
    //printf("S[%I64d]=%I64d\n",i,ss[i]);
  }
  int64_t C=B*inverse(A)%MOD;
  int64_t D=modpow(C,K);
  int64_t sumD=(D==1)?(N/K):(modpow(D,N/K)-1)*inverse(D-1)%MOD;
  int64_t sumS=0;
  int64_t powC=1;
  for(int64_t i=0;i<K;i++){
    sumS=(sumS+ss[i]*powC)%MOD;
    powC=powC*C%MOD;
  }
  printf("%I64d\n",modpow(A,N-1)*sumS%MOD*sumD%MOD);
  return 0;
}