#include <iostream>
#include <stdint.h>

const int64_t MOD=1e9+7;

int64_t K,PA,PB;
int64_t FA,FB;
int64_t dp[1001][1001];
int64_t E=0;

int64_t modpow(int64_t base,int64_t exp){
  int64_t ac=1;
  for(;exp>0;exp>>=1){
    if(exp&1){
      ac=(ac*base)%MOD;
    }
    base=(base*base)%MOD;
  }
  return ac;
}

int64_t inverse(int64_t X){
  return modpow(X,MOD-2);
}

int main(){
  std::cin>>K>>PA>>PB;
  FA=PA*inverse(PA+PB)%MOD;
  FB=PB*inverse(PA+PB)%MOD;
  dp[1][0]=1;
  for(int64_t a=1;a<K;a++){
    for(int64_t ab=0;ab<K;ab++){
      dp[a+1][ab]=(dp[a+1][ab]+dp[a][ab]*FA)%MOD;
      if(ab+a<K){
	dp[a][ab+a]=(dp[a][ab+a]+dp[a][ab]*FB)%MOD;
      }else{
	E=(E+dp[a][ab]*FB%MOD*(ab+a))%MOD;
      }
    }
  }
  for(int64_t ab=0;ab<K;ab++){
    E=(E+dp[K][ab]*(ab+K+PA*inverse(PB)%MOD))%MOD;
  }
  std::cout<<E<<std::endl;
  return 0;
}