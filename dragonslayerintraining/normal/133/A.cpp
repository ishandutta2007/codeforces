#include <iostream>

int main(){
  std::string str;
  std::getline(std::cin,str);
  if(str.find_first_of("HQ9")==std::string::npos){
    std::cout<<"NO"<<std::endl;
  }else{
    std::cout<<"YES"<<std::endl;
  }
  return 0;
}