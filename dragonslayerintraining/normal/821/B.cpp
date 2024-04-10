#include <iostream>
#include <stdint.h>

int64_t best;

int main(){
  int64_t M,B;
  std::cin>>M>>B;
  for(int64_t y=0;y<=B;y++){
    int64_t x=M*(B-y);
    best=std::max(best,(x+1)*(y+1)*(x+y)/2);
  }
  std::cout<<best<<std::endl;
  return 0;
}