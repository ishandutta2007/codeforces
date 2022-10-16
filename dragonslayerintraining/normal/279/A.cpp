#include <iostream>

int main(){
  int X,Y;
  std::cin>>X>>Y;
  if((Y>X)&&(X+Y>=0)){
    std::cout<<4*Y-2<<std::endl;
  }else if((X+Y<0)&&(Y>=X)){
    std::cout<<-4*X-1<<std::endl;
  }else if((Y<X)&&(X+Y<=1)){
    std::cout<<-4*Y<<std::endl;
  }else if((X+Y>1)&&(Y<=X)){
    std::cout<<4*X-3<<std::endl;
  }else{
    std::cout<<0<<std::endl;
  }
  return 0;
}