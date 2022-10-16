#include <iostream>

int main(){
  std::string str;
  std::cin>>str;
  for(int i=0;i<str.length();i++){
    if(str[i]=='.'){
      std::cout<<0;
    }else if(str[++i]=='.'){
      std::cout<<1;
    }else{
      std::cout<<2;
    }
  }
  std::cout<<std::endl;
  return 0;
}