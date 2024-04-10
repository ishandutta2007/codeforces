#include <iostream>

int dp[101][101];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(i==0||j==0){
	dp[i][j]=1;
      }else{
	dp[i][j]=dp[i-1][j]+dp[i][j-1];
      }
    }
  }
  std::cout<<dp[N-1][N-1]<<std::endl;
  return 0;
}