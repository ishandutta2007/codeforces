#include <iostream>

int main(){
  int X;
  std::cin>>X;
  int cnt=0;
  for(;X>0;X>>=1){
    cnt+=(X&1);
  }
  std::cout<<cnt<<std::endl;
  return 0;
}