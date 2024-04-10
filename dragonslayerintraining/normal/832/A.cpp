#include <iostream>
#include <stdint.h>

int main(){
  int64_t N,K;
  std::cin>>N>>K;
  N%=(2*K);
  if(N<K){
    std::cout<<"NO"<<std::endl;
  }else{
    std::cout<<"YES"<<std::endl;
  }
  return 0;
}