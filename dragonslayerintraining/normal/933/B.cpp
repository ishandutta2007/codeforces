#include <iostream>
#include <stdint.h>
#include <vector>

int64_t mod(int64_t N,int64_t M){
  if(N<0) N=M-(-N%M);
  return N%M;
}

std::vector<int64_t> poly;

int main(){
  int64_t P,K;
  std::cin>>P>>K;
  while(P!=0){
    poly.push_back(mod(P,K));
    P-=mod(P,K);
    P/=-K;
  }
  std::cout<<poly.size()<<std::endl;
  for(int64_t i=0;i<poly.size();i++){
    if(i>0) std::cout<<" ";
    std::cout<<poly[i];
  }
  std::cout<<std::endl;
  return 0;
}