#include <iostream>

int main(){
  int N,M;
  std::cin>>N>>M;
  if(N>=30){
    std::cout<<M<<std::endl;
  }else{
    std::cout<<M%(1<<N)<<std::endl;
  }
  return 0;
}