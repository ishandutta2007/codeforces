#include <iostream>
#include <stdint.h>

int main(){
  int64_t A,B;
  int64_t x,y,z;
  std::cin>>A>>B>>x>>y>>z;
  std::cout<<std::max<int64_t>(0,2*x+y-A)+std::max<int64_t>(0,3*z+y-B)<<std::endl;
  return 0;
}