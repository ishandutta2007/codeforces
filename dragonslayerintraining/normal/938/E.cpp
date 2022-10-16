#include <cstdio>
#include <map>
#include <stdint.h>

const int64_t MOD=1e9+7;

std::map<int64_t,int64_t> map;

int64_t modpow(int64_t base,int64_t exp){
  int64_t ac=1;
  for(;exp>0;exp>>=1){
    if(exp&1) ac=ac*base%MOD;
    base=base*base%MOD;
  }
  return ac;
}

int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=0;i<N;i++){
    int64_t A;
    scanf("%I64d",&A);
    map[-A]++;
  }
  int64_t size=0;
  int64_t res=0;
  for(auto it:map){
    size+=it.second;
    if(it!=*map.begin()){
      res=(res+(-it.first*it.second%MOD)*modpow(size,MOD-2)%MOD);
    }
  }
  for(int64_t i=1;i<=N;i++){
    res=(res*i)%MOD;
  }
  printf("%I64d\n",res);
  return 0;
}