#include <iostream>
#include <stdint.h>

int64_t cnt[10];
int64_t dp[11][100];

int64_t pascal[101][101];

int64_t solve(){
  for(int64_t i=10-1;i>=0;i--){
    std::fill(dp[i],dp[i]+100,0);
  }
  dp[10][0]=1;
  for(int64_t i=10-1;i>=0;i--){
    if(cnt[i]==0){
      for(int64_t d=0;d<100;d++){
	dp[i][d]=dp[i+1][d];
      }
    }else{
      for(int64_t add=1;add<=cnt[i];add++){
	for(int64_t d=add+!i;d<100;d++){
	  dp[i][d]+=dp[i+1][d-add]*pascal[d-add-!i][add];
	}
      }
    }
    /*
    for(int64_t d=0;d<100;d++){
      if(dp[i][d]){
	printf("dp[%d][%d]=%d\n",i,d,dp[i][d]);
      }
    }
    */
  }
  int64_t total=0;
  for(int64_t d=0;d<100;d++){
    total+=dp[0][d];
  }
  return total;
}

int main(){
  for(int64_t i=0;i<=100;i++){
    pascal[i][0]=1;
    pascal[0][i]=1;
  }
  for(int64_t i=1;i<=100;i++){
    for(int64_t j=1;j<=100;j++){
      pascal[i][j]=pascal[i-1][j]+pascal[i][j-1];
    }
  }
  std::string N;
  std::cin>>N;
  for(char c:N){
    cnt[c-'0']++;
  }
  std::cout<<solve()<<std::endl;
  return 0;
}