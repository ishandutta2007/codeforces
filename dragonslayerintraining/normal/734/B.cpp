#include <iostream>

int main(){
  int k2,k3,k5,k6;
  std::cin>>k2>>k3>>k5>>k6;
  int k56=std::min(k5,k6);
  int sum=0;
  sum+=256*std::min(k2,k56);
  k2-=std::min(k2,k56);
  sum+=32*std::min(k3,k2);
  std::cout<<sum<<std::endl;
  return 0;
}