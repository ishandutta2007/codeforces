#include <iostream>
#include <stdint.h>

int main(){
  int64_t N;
  std::cin>>N;
  int64_t ac=2;
  for(int64_t i=0;i<N;i++){
    ac*=2;
  }
  std::cout<<ac-2<<std::endl;
  return 0;
}