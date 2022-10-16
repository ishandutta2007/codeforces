#include <iostream>

int main(){
  unsigned long long A,B;
  std::cin>>A>>B;
  if(A<B){
    std::cout<<-1<<std::endl;
    return 0;
  }
  unsigned long long C=(A-B)>>1;
  if(B&C){
    std::cout<<-1<<std::endl;
  }else{
    std::cout<<C<<" "<<(B|C)<<std::endl;
  }
  return 0;
}