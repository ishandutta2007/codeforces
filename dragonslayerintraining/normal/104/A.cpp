#include <iostream>

int f(int N){
  if(N<=10){
    return 0;
  }
  N-=10;
  if(N>11){
    return 0;
  }
  switch(N){
  case 10:return 15;
  default:return 4;
  }
}

int main(){
  int N;
  std::cin>>N;
  std::cout<<f(N)<<std::endl;
  return 0;
}