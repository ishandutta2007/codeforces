#include <iostream>
#include <algorithm>

struct citem{
  int t,c;
}items[2000];

long long dp[2001];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>items[i].t>>items[i].c;
  }
  dp[0]=0;
  for(int j=1;j<=N;j++){
    dp[j]=1e18;
  }
  for(int i=0;i<N;i++){
    for(int j=N;j>=0;j--){
      int index=std::min(j+items[i].t+1,N);
      dp[index]=std::min(dp[index],dp[j]+items[i].c);
    }
  }
  std::cout<<dp[N]<<std::endl;
  return 0;
}