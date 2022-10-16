#include <iostream>
#include <stdint.h>

int main(){
  int64_t A,B;
  std::cin>>A>>B;
  while((A>0)&&(B>0)){
    if(A>=2*B){
      A%=(B*2);
      continue;
    }
    if(B>=2*A){
      B%=(A*2);
      continue;
    }
    break;
  }
  std::cout<<A<<" "<<B<<std::endl;
  return 0;
}