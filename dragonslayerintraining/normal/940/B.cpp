#include <iostream>
#include <stdint.h>

int main(){
  int64_t N,K,A,B;
  std::cin>>N>>K>>A>>B;
  if(K==1){
    std::cout<<A*(N-1)<<std::endl;
    return 0;
  }
  int64_t cost=0;
  while(N>=K){
    cost+=A*(N%K);
    N/=K;
    cost+=std::min((K-1)*N*A,B);
  }
  cost+=A*(N-1);
  std::cout<<cost<<std::endl;
  return 0;
}