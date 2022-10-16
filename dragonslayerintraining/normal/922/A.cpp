#include <iostream>

int main(){
  int X,Y;
  std::cin>>X>>Y;
  std::cout<<(Y>0&&(Y>1||X==0)&&((X+Y)%2&&X+1>=Y)?"YES":"NO")<<std::endl;
  return 0;
}