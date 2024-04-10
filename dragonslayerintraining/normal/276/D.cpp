#include <iostream>
#include <stdint.h>

int main(){
  int64_t L,R;
  std::cin>>L>>R;
  for(int k=61;k>=0;k--){
    if((L^R)&(1LL<<k)){
      std::cout<<((1LL<<(k+1))-1)<<std::endl;
      return 0;
    }
  }
  std::cout<<0<<std::endl;
  return 0;
}