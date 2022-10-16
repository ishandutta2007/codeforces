#include <iostream>

int main(){
  int N,X,Y;
  std::cin>>N>>X>>Y;
  int req=(Y*N+99)/100;
  std::cout<<std::max(0,req-X)<<std::endl;
  return 0;
}