#include <iostream>
#include <stdint.h>

int64_t sum=0;

int64_t as[200000];

int main(){
  int64_t N;
  std::cin>>N;
  for(int64_t i=0;i<N;i++){
    std::cin>>as[i];
    sum+=as[i];
  }
  int64_t sum2=0;
  for(int64_t i=0;i<N;i++){
    sum2+=as[i];
    if(sum2*2>=sum){
      std::cout<<i+1<<std::endl;
      return 0;
    }
  }
  return 0;
}