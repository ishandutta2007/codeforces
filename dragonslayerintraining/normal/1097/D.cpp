#include <cstdio>
#include <stdint.h>
#include <map>

const int64_t MOD=1e9+7;

int64_t N,K;

std::map<int64_t,int64_t> factors;

int64_t dp[10005][55];

int64_t inv[10005]={1,1};

void factorize(){
  int64_t num=N;
  for(int64_t i=2;i*i<=N;i++){
    if(num%i==0){
      while(num%i==0){
	factors[i]++;
	num/=i;
      }
    }
  }
  if(num>1){
    factors[num]++;
  }
}

int main(){
  for(int i=2;i<=10000;i++){
    inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
  }
  scanf("%I64d %I64d",&N,&K);
  factorize();
  int64_t ans=1;
  for(auto it:factors){
    int64_t prime=it.first;
    int64_t exp=it.second;
    //fprintf(stderr,"%I64d^%I64d\n",prime,exp);
    dp[0][0]=1;
    for(int64_t i=1;i<=exp;i++){
      dp[0][i]=dp[0][i-1]*prime%MOD;
    }
    for(int64_t k=1;k<=K;k++){
      int64_t sum=0;
      for(int64_t i=0;i<=exp;i++){
	sum=(sum+dp[k-1][i])%MOD;
	dp[k][i]=sum*inv[i+1]%MOD;
      }
    }
    ans=ans*dp[K][exp]%MOD;
  }
  printf("%I64d\n",ans);
  return 0;
}