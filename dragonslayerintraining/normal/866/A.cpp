#include <iostream>

int main(){
  int A;
  std::cin>>A;
  if(A>1){
    std::cout<<2*(A-1)<<" "<<2<<std::endl;
    std::cout<<1<<std::endl;
    std::cout<<2<<std::endl;
  }else{
    std::cout<<1<<" "<<1<<std::endl;
    std::cout<<1<<std::endl;
  }
  return 0;
}