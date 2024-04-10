#include <cstdio>
#include <algorithm>
#include <stdint.h>

const int64_t MOD=1e9+7;

int64_t dp[3001][3001];
int64_t ps[3001];

int64_t modpow(int64_t base,int64_t exp){
  int64_t ac=1;
  for(;exp>0;exp>>=1){
    if(exp&1) ac=ac*base%MOD;
    base=base*base%MOD;
  }
  return ac;
}

int main(){
  int64_t N,D;
  scanf("%I64d %I64d",&N,&D);
  D--;
  for(int64_t i=1;i<N;i++){
    scanf("%I64d",&ps[i]);
    ps[i]--;
  }
  for(int64_t i=0;i<=N;i++){
    std::fill(dp[i],dp[i]+N+1,1);
  }
  for(int64_t i=N-1;i>0;i--){
    int64_t ac=0;
    for(int64_t k=0;k<=N;k++){
      ac=(ac+dp[i][k])%MOD;
      dp[ps[i]][k]=dp[ps[i]][k]*ac%MOD;
    }
  }
  for(int64_t k=1;k<=N;k++){
    dp[0][k]=(dp[0][k]+dp[0][k-1])%MOD;
  }
  /*
  for(int64_t i=0;i<=N;i++){
    printf("dp[0][%I64d]=%I64d\n",i,dp[0][i]);
  }
*/
  int64_t ans=0;
  for(int64_t j=0;j<=N;j++){
    int64_t num=1,den=1;
    for(int64_t i=0;i<=N;i++){
      if(i==j) continue;
      num=(num*(D-i+MOD))%MOD;
      den=(den*(j-i+MOD))%MOD;
    }
    //printf("ADD %I64d*%I64d/%I64d\n",dp[0][j],num,den);
    ans=(ans+dp[0][j]*num%MOD*modpow(den,MOD-2))%MOD;
  }
  printf("%I64d\n",ans);
  return 0;
}