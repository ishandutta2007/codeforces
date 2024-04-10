#include <iostream>
#include <stdint.h>

int main(){
  int64_t N;
  std::cin>>N;
  int64_t twos=1;
  while(N%2==0){
    twos*=2;
    N/=2;
  }
  if(N>1){
    std::cout<<(twos*((N*N-1)/2))<<" "<<(twos*((N*N+1)/2))<<std::endl;
  }else{
    if(twos>=4){
      twos/=4;
      std::cout<<(twos*3)<<" "<<(twos*5)<<std::endl;
    }else{
      std::cout<<-1<<std::endl;
    }
  }
  return 0;
}