#include <iostream>

int main(){
  int N;
  std::cin>>N;
  int dp[4]={0,0,0,0};
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    if(A==1){
      dp[0]++,dp[2]++;
    }else{
      dp[1]++,dp[3]++;
    }
    for(int k=1;k<4;k++){
      dp[k]=std::max(dp[k],dp[k-1]);
    }
  }
  std::cout<<dp[3]<<std::endl;
  return 0;
}