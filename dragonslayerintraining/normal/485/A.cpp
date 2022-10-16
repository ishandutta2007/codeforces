#include <iostream>

int main(){
  int A,M;
  std::cin>>A>>M;
  M/=(M&-M);
  if(A%M==0){
    std::cout<<"Yes"<<std::endl;
  }else{
    std::cout<<"No"<<std::endl;
  }
  return 0;
}