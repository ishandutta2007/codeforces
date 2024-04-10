#include <iostream>
#include <stdint.h>

const int64_t MOD=1e9+7;

int64_t S1[100000];
int64_t S2[100000];
int64_t N,M;

int64_t invM;

int64_t calc(int64_t i){
  if(i==N) return 0;
  if(S1[i]&&S2[i]){
    if(S1[i]==S2[i]) return calc(i+1);
    else return S1[i]>S2[i];
  }else if(S1[i]){
    return (calc(i+1)+S1[i]-1)*invM%MOD;
  }else if(S2[i]){
    return (calc(i+1)+M-S2[i])*invM%MOD;
  }else{
    return (calc(i+1)+M*(M-1)/2%MOD*invM%MOD)*invM%MOD;
  }
}

int64_t modpow(int64_t base,int64_t exp){
  int64_t ac=1;
  for(;exp>0;exp>>=1){
    if(exp&1) ac=(ac*base)%MOD;
    base=(base*base)%MOD;
  }
  return ac;
}

int main(){
  std::cin>>N>>M;
  invM=modpow(M,MOD-2);
  for(int64_t i=0;i<N;i++){
    std::cin>>S1[i];
  }
  for(int64_t i=0;i<N;i++){
    std::cin>>S2[i];
  }
  std::cout<<calc(0)<<std::endl;
  return 0;
}