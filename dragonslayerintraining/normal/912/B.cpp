#include <iostream>
#include <stdint.h>

int main(){
  int64_t K,N;
  std::cin>>N>>K;
  if(K==1){
    std::cout<<N<<std::endl;
  }else{
    int64_t k=1;
    while(k<=N){
      k<<=1;
    }
    std::cout<<k-1<<std::endl;
  }
  return 0;
}