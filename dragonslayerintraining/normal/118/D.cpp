#include <iostream>

const int MOD=100000000;

long long dp[103][103][13][13];

int main(){
  int N1,N2,K1,K2;
  std::cin>>N1>>N2>>K1>>K2;
  for(int n1=0;n1<=N1;n1++){
    for(int n2=0;n2<=N2;n2++){
      for(int k1=0;k1<=K1;k1++){
	for(int k2=0;k2<=K2;k2++){
	  if((n1==0)&&(n2==0)&&(k1==0)&&(k2==0)){
	    dp[n1][n2][k1][k2]=1;
	  }
	  dp[n1+1][n2][k1+1][0]+=dp[n1][n2][k1][k2];
	  dp[n1+1][n2][k1+1][0]%=MOD;
	  dp[n1][n2+1][0][k2+1]+=dp[n1][n2][k1][k2];
	  dp[n1][n2+1][0][k2+1]%=MOD;
	}
      }
    }
  }
  long long total=0;
  for(int k1=0;k1<=K1;k1++){
    total+=dp[N1][N2][k1][0];
    total%=MOD;
  }
  for(int k2=0;k2<=K2;k2++){
    total+=dp[N1][N2][0][k2];
    total%=MOD;
  }
  std::cout<<total<<std::endl;
  return 0;
}