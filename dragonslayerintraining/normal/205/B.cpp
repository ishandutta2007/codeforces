#include <iostream>
#include <stdint.h>

int main(){
  int64_t N;
  std::cin>>N;
  int64_t cost=0;
  int64_t prev;
  std::cin>>prev;
  for(int64_t i=1;i<N;i++){
    int64_t A;
    std::cin>>A;
    if(A<prev){
      cost+=(prev-A);
    }
    prev=A;
  }
  std::cout<<cost<<std::endl;
  return 0;
}