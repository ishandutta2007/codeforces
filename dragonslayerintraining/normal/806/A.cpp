#include <iostream>
#include <stdint.h>

int64_t calc(int64_t X,int64_t Y,int64_t P,int64_t Q){
  int64_t r=0;
  if(P>0){
    r=std::max(r,(X+P-1)/P);
  }else{
    if(X!=0){
      return -1;
    }
  }
  if(Q>0){
    r=std::max(r,(Y+Q-1)/Q);
  }else{
    if(Y!=0){
      return -1;
    }
  }
  return r*(P+Q)-(X+Y);
}

int main(){
  int64_t T;
  std::cin>>T;
  for(int64_t i=0;i<T;i++){
    int64_t X,Y,P,Q;
    std::cin>>X>>Y>>P>>Q;
    std::cout<<calc(X,Y-X,P,Q-P)<<std::endl;
  }
  return 0;
}