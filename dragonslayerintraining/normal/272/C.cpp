#include <iostream>
#include <stdint.h>

int64_t as[100000];

int64_t top=0;

int main(){
  int64_t N;
  std::cin>>N;
  for(int64_t i=0;i<N;i++){
    std::cin>>as[i];
  }
  int64_t M;
  std::cin>>M;
  for(int64_t i=0;i<M;i++){
    int64_t W,H;
    std::cin>>W>>H;
    std::cout<<std::max(top,as[W-1])<<std::endl;
    top=std::max(top,as[W-1])+H;
  }
  return 0;
}