#include <iostream>
#include <algorithm>

int main(){
  int L,R,A;
  std::cin>>L>>R>>A;
  std::cout<<(std::min(L,R)+std::min(A,std::abs(L-R)+(A-std::abs(L-R))/2))*2<<std::endl;
  return 0;
}