#include <iostream>
#include <stdint.h>

int main(){
  int64_t N,K;
  std::cin>>N>>K;
  int64_t del=0;
  int64_t pow=0;
  for(;N>0;N/=10){
    if(N%10==0){
      pow++;
    }else{
      del++;
    }
    if(pow==K){
      std::cout<<del<<std::endl;
      return 0;
    }
  }
  std::cout<<std::max<int64_t>(pow+del-1,0LL)<<std::endl;
  return 0;
}