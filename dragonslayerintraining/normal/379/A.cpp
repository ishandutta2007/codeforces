#include <iostream>

int main(){
  int A,B;
  std::cin>>A>>B;
  int cnt=0;
  while(A>=B){
    cnt+=A/B*B;
    A=A-A/B*(B-1);
  }
  std::cout<<cnt+A<<std::endl;
  return 0;
}