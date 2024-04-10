#include <iostream>

int main(){
  int N;
  std::cin>>N;
  if(N<4){
    std::cout<<"NO"<<std::endl;
    return 0;
  }
  if(N%2==0){
    std::cout<<"YES"<<std::endl;
    return 0;
  }else{
    std::cout<<"NO"<<std::endl;
    return 0;
  }
}