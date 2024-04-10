#include <iostream>
#include <iomanip>

double dp[21][40];

int main(){
  std::string A,B;
  std::cin>>A>>B;
  int shift=0;
  for(char c:A){
    shift+=(c=='+')-(c=='-');
  }
  dp[0][20]=1;
  for(int i=0;i<B.size();i++){
    for(int k=1;k<40;k++){
      if(B[i]=='?'){
	dp[i+1][k]=(dp[i][k-1]+dp[i][k+1])/2;
      }else if(B[i]=='+'){
	dp[i+1][k]=dp[i][k-1];
      }else{
	dp[i+1][k]=dp[i][k+1];
      }
    }
  }
  std::cout<<std::fixed<<std::setprecision(10)<<dp[B.size()][20+shift]<<std::endl;
  return 0;
}