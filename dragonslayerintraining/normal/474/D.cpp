#include <iostream>

const int MOD=1e9+7;

int dp[100001];

int main(){
  int T,K;
  std::cin>>T>>K;
  dp[0]=1;
  for(int i=1;i<=100000;i++){
    dp[i]=(dp[i-1]+((i>=K)?dp[i-K]:0))%MOD;
  }
  for(int i=1;i<=100000;i++){
    dp[i]=(dp[i]+dp[i-1])%MOD;
  }
  while(T-->0){
    int A,B;
    std::cin>>A>>B;
    std::cout<<(MOD+dp[B]-dp[A-1])%MOD<<std::endl;
  }
  return 0;
}