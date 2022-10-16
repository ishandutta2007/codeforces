#include <iostream>

int main(){
  int A,B;
  std::cin>>A>>B;
  int prod=1;
  for(int i=1;i<=std::min(A,B);i++){
    prod*=i;
  }
  std::cout<<prod<<std::endl;
  return 0;
}