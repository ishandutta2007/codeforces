#include <iostream>
#include <algorithm>

int main(){
  std::string str;
  std::cin>>str;
  char next='a';
  for(char c:str){
    if(c>next){
      std::cout<<"NO"<<std::endl;
      return 0;
    }else{
      next=std::max<char>(next,c+1);
    }
  }
  std::cout<<"YES"<<std::endl;
  return 0;
}