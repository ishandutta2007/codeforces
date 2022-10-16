#include <iostream>
#include <stdint.h>

int64_t solve(int64_t N){
  return (N>1)?(N/2+solve((N+1)/2)*2):0;
}

int main(){
  int64_t N;
  std::cin>>N;
  std::cout<<solve(N)<<std::endl;
  return 0;
}