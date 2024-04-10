#include <iostream>
#include <cstring>
#include <cctype>

int main(){
  std::string str;
  std::cin>>str;
  int cap=0;
  for(int i=0;i<str.length();i++){
    if(std::isupper(str[i])){
      cap++;
    }
  }
  if(cap*2>str.length()){
    for(int i=0;i<str.length();i++){
      std::cout<<char(std::toupper(str[i]));
    }
    std::cout<<std::endl;
  }else{
    for(int i=0;i<str.length();i++){
      std::cout<<char(std::tolower(str[i]));
    }
    std::cout<<std::endl;
  }
  return 0;
}