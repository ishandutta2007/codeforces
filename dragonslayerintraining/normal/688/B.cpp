#include <iostream>
#include <algorithm>

int main(){
  std::string str;
  std::cin>>str;
  std::cout<<str;
  std::reverse(str.begin(),str.end());
  std::cout<<str<<std::endl;
  return 0;
}