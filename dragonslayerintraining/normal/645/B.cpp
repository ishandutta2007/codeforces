#include <iostream>

int main(){
  int N,K;
  std::cin>>N>>K;
  K=std::min(K,N/2);
  std::cout<<1LL*K*(N*2-K*2-1)<<std::endl;
  return 0;
}