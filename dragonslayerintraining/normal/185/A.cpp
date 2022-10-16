#include <iostream>
#include <stdint.h>

const int64_t MOD=1000000007;

int main(){
  int64_t N;
  std::cin>>N;
  int64_t ac=1,base=2;
  for(int k=0;k<60;k++){
    if(N&(1LL<<k)){
      ac*=base;
      ac%=MOD;
    }
    base=base*base;
    base%=MOD;
  }
  std::cout<<ac*(ac+1)/2%MOD<<std::endl;
  return 0;
}