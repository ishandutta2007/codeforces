#include <iostream>

int main(){
  std::string str;
  std::cin>>str;
  int del=1;
  for(int i=0;i<str.length();i++){
    if((del==0)||((str[i]=='1')&&(i+1!=str.length()))){
      std::cout<<str[i];
    }else{
      del--;
    }
  }
  std::cout<<std::endl;
  return 0;
}