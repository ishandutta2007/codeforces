#include <iostream>
#include <stdint.h>

const int64_t MOD=1e9+7;

int64_t must[11];

int64_t dp[11][101];

int64_t inverse[101];
int64_t factorial[101];
int64_t invfactorial[101];

int main(){
  inverse[1]=1;
  for(int64_t i=2;i<=100;i++){
    inverse[i]=((MOD-inverse[MOD%i])*(MOD/i))%MOD;
  }
  factorial[0]=1;
  invfactorial[0]=1;
  for(int64_t i=1;i<=100;i++){
    factorial[i]=(factorial[i-1]*i)%MOD;
    invfactorial[i]=(invfactorial[i-1]*inverse[i])%MOD;
  }
  int64_t N;
  std::cin>>N;
  for(int64_t i=0;i<10;i++){
    std::cin>>must[i];
  }
  must[10]=must[0];
  dp[0][0]=1;
  for(int64_t d=1;d<10;d++){
    //digit #10 is zero
    for(int64_t i=0;i<=N;i++){
      for(int64_t use=must[d];use<=i;use++){
	dp[d][i]+=dp[d-1][i-use]*factorial[i]%MOD*invfactorial[use]%MOD*invfactorial[i-use]%MOD;
	dp[d][i]%=MOD;
      }
    }
  }
  for(int64_t i=0;i<=N;i++){
    for(int64_t use=must[10];use<i;use++){
      dp[10][i]+=dp[10-1][i-use]*factorial[i-1]%MOD*invfactorial[use]%MOD*invfactorial[i-use-1]%MOD;
      dp[10][i]%=MOD;
    }
  }
  int64_t ways=0;
  for(int64_t i=0;i<=N;i++){
    ways+=dp[10][i];
  }
  std::cout<<ways%MOD<<std::endl;
  return 0;
}