#include <iostream>
#include <stdint.h>

int main(){
  int N;
  std::cin>>N;
  int64_t a=1,b=0;
  for(int i=0;i<N;i++){
    int64_t a2=b;
    int64_t b2=3*a+b*2;
    a=a2%1000000007,b=b2%1000000007;
  }
  std::cout<<a<<std::endl;
  return 0;
}