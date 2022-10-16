#include <iostream>
#include <stdint.h>

int64_t gcd(int64_t a,int64_t b){
  return b?gcd(b,a%b):a;
}

int main(){
  int64_t T;
  std::cin>>T;
  for(int64_t i=0;i<T;i++){
    int64_t N;
    std::cin>>N;
    std::cout<<4*N/gcd(4*N,N+1)+1<<std::endl;
  }
  return 0;
}