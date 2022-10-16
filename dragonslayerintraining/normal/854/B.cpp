#include <iostream>

int main(){
  int N,K;
  std::cin>>N>>K;
  std::cout<<((K!=N)&&(K!=0))<<" "<<std::min(2*K,N-K)<<std::endl;
  return 0;
}