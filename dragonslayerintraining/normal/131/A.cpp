#include <iostream>
#include <cctype>

int main(){
  std::string str;
  std::cin>>str;
  for(int i=1;i<str.length();i++){
    if(!std::isupper(str[i])){
      std::cout<<str<<std::endl;
      return 0;
    }
  }
  for(int i=0;i<str.length();i++){
    if(std::isupper(str[i])){
      std::cout<<char(std::tolower(str[i]));
    }else{
      std::cout<<char(std::toupper(str[i]));
    }
  }
  std::cout<<std::endl;
  return 0;
}