#include <iostream>

int main(){
  int len;
  std::cin>>len;
  len=(len+1)/3;
  std::cout<<len/12<<" "<<len%12<<std::endl;
  return 0;
}