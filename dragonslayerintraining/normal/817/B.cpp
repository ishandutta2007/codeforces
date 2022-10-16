#include <iostream>
#include <algorithm>
#include <stdint.h>

int as[100000];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
  }
  std::sort(as,as+N);
  int64_t k=std::count(as,as+N,as[2]);
  if((as[0]==as[1])&&(as[1]==as[2])){
    std::cout<<k*(k-1)*(k-2)/6<<std::endl;
  }else if((as[0]==as[1])&&(as[1]<as[2])){
    std::cout<<k<<std::endl;
  }else if((as[0]<as[1])&&(as[1]==as[2])){
    std::cout<<k*(k-1)/2<<std::endl;
  }else{
    std::cout<<k<<std::endl;
  }
  return 0;
}