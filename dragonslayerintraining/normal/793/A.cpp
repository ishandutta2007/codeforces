#include <iostream>
#include <stdint.h>

int64_t as[100000];

int main(){
  int64_t N,K;
  std::cin>>N>>K;
  int64_t min=1e9;
  for(int64_t i=0;i<N;i++){
    std::cin>>as[i];
    min=std::min(min,as[i]);
  }
  int64_t seconds=0;
  for(int64_t i=0;i<N;i++){
    as[i]-=min;
    if(as[i]%K==0){
      seconds+=(as[i]/K);
    }else{
      std::cout<<-1<<std::endl;
      return 0;
    }
  }
  std::cout<<seconds<<std::endl;
  
  return 0;
}