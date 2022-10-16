#include <iostream>
#include <stdint.h>

int64_t solve(int64_t a,int64_t b){
  return b?(a/b+solve(b,a%b)):0;
}

int main(){
  int64_t A,B;
  std::cin>>A>>B;
  std::cout<<solve(A,B)<<std::endl;
  return 0;
}