#include <iostream>
#include <stdint.h>

int main(){
  int64_t N,M;
  std::cin>>N>>M;
  int64_t ac=1;
  int64_t base=3;
  for(int64_t k=0;k<31;k++){
    if(N&(1LL<<k)){
      ac=(ac*base)%M;
    }
    base=(base*base)%M;
  }
  std::cout<<(ac+M-1)%M<<std::endl;
}