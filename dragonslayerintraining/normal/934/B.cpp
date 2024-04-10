#include <iostream>

int main(){
  int K;
  std::cin>>K;
  if(K>36){
    std::cout<<-1<<std::endl;
    return 0;
  }
  for(;K>1;K-=2){
    std::cout<<"8";
  }
  if(K){
    std::cout<<"6";
  }
  std::cout<<std::endl;
  return 0;
}