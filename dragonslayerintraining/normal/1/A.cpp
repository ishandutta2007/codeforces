#include <iostream>

int main(){
  unsigned long long N,M,A;
  std::cin>>N>>M>>A;
  std::cout<<(((N+A-1)/A)*((M+A-1)/A))<<std::endl;
  return 0;
}