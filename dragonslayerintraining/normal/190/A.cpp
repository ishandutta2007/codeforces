#include <iostream>

int main(){
  int N,M;
  std::cin>>N>>M;
  if((N==0)&&(M!=0)){
    std::cout<<"Impossible"<<std::endl;
    return 0;
  }
  std::cout<<std::max(M,N)<<" "<<N+std::max(M-1,0)<<std::endl;
  return 0;
}