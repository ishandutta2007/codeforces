#include <iostream>
#include <algorithm>

int main(){
  int X[3];
  std::cin>>X[0]>>X[1]>>X[2];
  std::sort(X,X+3);
  std::cout<<X[2]-X[0]<<std::endl;
  return 0;
}