#include <iostream>

int main(){
  int D1,D2,D3;
  std::cin>>D1>>D2>>D3;
  std::cout<<std::min(D1+D2+D3,(D1+D2+D3-std::max(D1,std::max(D2,D3)))*2)<<std::endl;
  return 0;
}