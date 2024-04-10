#include <iostream>
#include <stdint.h>

int main(){
  int N,K;
  std::cin>>N>>K;
  int64_t best=-1e10;
  for(int i=0;i<N;i++){
    int F,T;
    std::cin>>F>>T;
    best=std::max(best,F-std::max<int64_t>(T-K,0));
  }
  std::cout<<best<<std::endl;
  return 0;
}