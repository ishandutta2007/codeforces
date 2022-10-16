#include <iostream>
#include <stdint.h>

int main(){
  int64_t P,Q;
  std::cin>>P>>Q;
  int64_t N;
  std::cin>>N;
  for(int64_t i=0;i<N;i++){
    int64_t A;
    std::cin>>A;
    if(P/A<Q||P<Q*A){
      std::cout<<"NO"<<std::endl;
      return 0;
    }
    P-=Q*A;
    std::swap(P,Q);
  }
  if(Q==0){
    std::cout<<"YES"<<std::endl;
  }else{
    std::cout<<"NO"<<std::endl;
  }
  return 0;
}