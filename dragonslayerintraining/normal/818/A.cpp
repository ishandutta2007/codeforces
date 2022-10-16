#include <iostream>
#include <stdint.h>

int main(){
  int64_t N,K;
  std::cin>>N>>K;
  int64_t D=N/2/(K+1);
  std::cout<<D<<" "<<K*D<<" "<<N-(K+1)*D<<std::endl;
  return 0;
}