#include <iostream>

const long long MOD=1000000007;

long long N;
long long as[1000];

long long dp[40000];
long long copy[40000];

int main(){
  long long N;
  std::cin>>N;
  for(long long i=0;i<N;i++){
    std::cin>>as[i];
  }
  long long total=0;
  for(long long i=0;i<N;i++){
    dp[20000]++;
    for(long long j=0;j<40000;j++){
      copy[j]=0;
      if(j>=as[i]){
	copy[j]=(copy[j]+dp[j-as[i]])%MOD;
      }
      if(j<40000-as[i]){
	copy[j]=(copy[j]+dp[j+as[i]])%MOD;
      }
    }
    for(long long j=0;j<40000;j++){
      dp[j]=copy[j];
    }
    total=(total+dp[20000])%MOD;
  }
  std::cout<<total<<std::endl;
  return 0;
}