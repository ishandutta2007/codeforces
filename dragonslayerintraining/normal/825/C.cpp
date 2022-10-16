#include <iostream>
#include <algorithm>
#include <stdint.h>

int64_t as[1000];

int main(){
  int64_t N,K;
  std::cin>>N>>K;
  for(int64_t i=0;i<N;i++){
    std::cin>>as[i];
  }
  std::sort(as,as+N);
  int64_t max=K*2;
  int64_t cnt=0;
  for(int64_t i=0;i<N;i++){
    while(max<as[i]){
      max*=2;
      cnt++;
    }
    max=std::max(max,as[i]*2);
  }
  std::cout<<cnt<<std::endl;
  return 0;
}