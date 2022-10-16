#include <iostream>
#include <stdint.h>

int main(){
  int64_t N,M;
  std::cin>>N>>M;
  int64_t loc=0;
  int64_t dist=0;
  for(int64_t i=0;i<M;i++){
    int64_t A;
    std::cin>>A;
    A--;
    if(A>=loc){
      dist+=A-loc;
    }else{
      dist+=N+A-loc;
    }
    loc=A;
  }
  std::cout<<dist<<std::endl;
  return 0;
}