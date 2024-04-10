#include <iostream>

int main(){
  int N1,N2,K1,K2;
  std::cin>>N1>>N2>>K1>>K2;
  if(N1>N2){
    std::cout<<"First"<<std::endl;
  }else{
    std::cout<<"Second"<<std::endl;
  }
  return 0;
}