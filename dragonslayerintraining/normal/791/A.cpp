#include <iostream>

int main(){
  int A,B;
  std::cin>>A>>B;
  int year=0;
  while(A<=B){
    A*=3;
    B*=2;
    year++;
  }
  std::cout<<year<<std::endl;
  return 0;
}