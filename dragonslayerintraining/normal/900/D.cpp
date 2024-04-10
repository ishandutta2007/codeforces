#include <iostream>
#include <vector>
#include <algorithm>
#include <stdint.h>

const int64_t MOD=1e9+7;

int64_t mod_pow(int64_t base,int64_t exp){
  int64_t ac=1;
  for(;exp>0;exp>>=1){
    if(exp&1){
      ac=ac*base%MOD;
    }
    base=base*base%MOD;
  }
  return ac;
}

std::vector<int64_t> factors;
std::vector<int64_t> cnt;

int main(){
  int64_t X,Y;
  std::cin>>X>>Y;
  if(Y%X!=0){
    std::cout<<0<<std::endl;
    return 0;
  }
  Y/=X;
  for(int64_t i=1;i<=Y/i;i++){
    if(Y%i==0){
      factors.push_back(i);
      if(i*i<Y){
	factors.push_back(Y/i);
      }
    }
  }
  std::sort(factors.begin(),factors.end());  
  cnt.resize(factors.size());
  for(int64_t i=0;i<factors.size();i++){
    cnt[i]=mod_pow(2,factors[i]-1);
    for(int64_t j=0;j<i;j++){
      if(factors[i]%factors[j]==0){
	cnt[i]=(cnt[i]+MOD-cnt[j])%MOD;
      }
    }
    //std::cout<<factors[i]<<" "<<cnt[i]<<std::endl;
  }
  std::cout<<cnt.back()<<std::endl;
  return 0;
}