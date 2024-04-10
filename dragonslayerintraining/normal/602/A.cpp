#include <iostream>
#include <stdint.h>

int64_t readnum(){
  int N,B;
  std::cin>>N>>B;
  int64_t ac=0;
  for(int i=0;i<N;i++){
    int64_t X;
    std::cin>>X;
    ac=ac*B+X;
  }
  return ac;
}

int main(){
  int64_t X=readnum();
  int64_t Y=readnum();
  if(X<Y){
    std::cout<<"<"<<std::endl;
  }else if(X>Y){
    std::cout<<">"<<std::endl;
  }else{
    std::cout<<"="<<std::endl;
  }
  return 0;
}