#include <iostream>
#include <stdint.h>

int main(){
  int64_t N,M,A,B;
  std::cin>>N>>M>>A>>B;
  std::cout<<std::min(A*(M-N%M),B*(N%M))<<std::endl;
  return 0;
}