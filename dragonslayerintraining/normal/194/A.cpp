#include <iostream>

int main(){
  int N,K;
  std::cin>>N>>K;
  K-=2*N;
  std::cout<<std::max(0,N-K)<<std::endl;
  return 0;
}