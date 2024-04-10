#include <iostream>

int main(){
  int A,B;
  std::cin>>A>>B;
  std::cout<<std::min(A,B)<<" "<<(std::max(A-B,B-A)/2)<<std::endl;
  return 0;
}