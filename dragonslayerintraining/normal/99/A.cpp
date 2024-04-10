#include <iostream>

int main(){
  std::string str;
  std::cin>>str;
  size_t i=str.find('.');
  if(str[i-1]!='9'){
    if(str[i+1]>='5'){
      for(int k=0;k<i-1;k++){
	std::cout<<str[k];
      }
      std::cout<<char(str[i-1]+1)<<std::endl;
    }else{
      for(int k=0;k<i;k++){
	std::cout<<str[k];
      }
      std::cout<<std::endl;
    }
  }else{
    std::cout<<"GOTO Vasilisa."<<std::endl;
  }
  
  return 0;
}