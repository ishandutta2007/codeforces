#include <iostream>

int main(){
  int N,M,A,B;
  std::cin>>N>>M>>A>>B;
  std::cout<<std::min(std::min(A*N,B*(N/M)+A*(N%M)),B*((N+M-1)/M))<<std::endl;
  return 0;
}