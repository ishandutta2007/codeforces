#include <iostream>

int main(){
  std::string str;
  std::cin>>str;
  str[0]=std::toupper(str[0]);
  std::cout<<str<<std::endl;
  return 0;
}