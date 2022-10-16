#include <iostream>
#include <stdint.h>

int main(){
  int64_t N;
  std::cin>>N;
  int64_t cnt=0;
  int64_t run=0;
  int64_t prev=0;
  for(int i=0;i<N;i++){
    int64_t A;
    std::cin>>A;
    if(A==prev){
      run++;
    }else{
      run=1;
    }
    cnt+=run;
    prev=A;
  }
  std::cout<<cnt<<std::endl;
  return 0;
}