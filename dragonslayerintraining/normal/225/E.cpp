#include <iostream>
#include <vector>
#include <stdint.h>

int64_t mersenne[40]={2,3,5,7,13,17,19,31,61,89,107,127,521,607,1279,2203,2281,3217,4253,4423,9689,9941,11213,19937,21701,23209,44497,86243,110503,132049,216091,756839,859433,1257787,1398269,2976221,3021377,6972593,13466917,20996011};

int64_t power(int64_t base,int64_t exp,int64_t mod){
  int64_t ac=1;
  for(int k=0;k<30;k++){
    if(exp&(1<<k)){
      ac=(ac*base)%mod;
    }
    base=(base*base)%mod;
  }
  return ac;
}

int main(){
  int N;
  std::cin>>N;
  std::cout<<power(2,mersenne[N-1]-1,1e9+7)-1<<std::endl;
  return 0;
}