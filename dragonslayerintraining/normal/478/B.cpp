#include <iostream>
#include <stdint.h>

int main(){
  int64_t N,M;
  std::cin>>N>>M;
  int64_t max=(N-M)*(N-M+1)/2;
  int64_t k=N/M;
  int64_t plus=N%M;
  int64_t min=(M-plus)*k*(k-1)/2+plus*k*(k+1)/2;
  std::cout<<min<<" "<<max<<std::endl;
  return 0;
}