#include <iostream>

int calc(int A,int C){
  if((A==0)&&(C==0)){
    return 0;
  }
  return calc(A/3,C/3)*3+(C%3+3-A%3)%3;
}

int main(){
  int A,C;
  std::cin>>A>>C;
  std::cout<<calc(A,C)<<std::endl;
  return 0;
}