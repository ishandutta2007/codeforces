#include <iostream>

int main(){
  std::string str;
  std::cin>>str;
  int state=-1;
  for(char c:str){
    if(state==-1){
      if(c=='1'){
	state=0;
      }
    }else{
      state+=(c=='0');
    }
  }
  if(state>=6){
    std::cout<<"yes"<<std::endl;
  }else{
    std::cout<<"no"<<std::endl;
  }
  return 0;
}