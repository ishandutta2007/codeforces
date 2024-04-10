#include <iostream>
#include <stdint.h>

const int64_t MOD=1e9+7;

int64_t dp[1000];
int64_t N;

int64_t query(int64_t lim){
  dp[0]=1;
  for(int64_t i=1;i<=N;i++){
    dp[i]=0;
    for(int64_t k=1;k<=lim&&k<=i;k++){
      dp[i]=(dp[i]+dp[i-k])%MOD;
    }
  }
  return dp[N];
}

int main(){
  int64_t K,D;
  std::cin>>N>>K>>D;
  std::cout<<(MOD+query(K)-query(D-1))%MOD<<std::endl;
  return 0;
}