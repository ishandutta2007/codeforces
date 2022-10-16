#include <iostream>

int N,A,B,C;

int dp[5000];

int main(){
  std::cin>>N>>A>>B>>C;
  for(int i=1;i<=N;i++){
    dp[i]=-1e9;
    if(i>=A){
      dp[i]=std::max(dp[i],dp[i-A]+1);
    }
    if(i>=B){
      dp[i]=std::max(dp[i],dp[i-B]+1);
    }
    if(i>=C){
      dp[i]=std::max(dp[i],dp[i-C]+1);
    }
  }
  std::cout<<dp[N]<<std::endl;
  return 0;
}