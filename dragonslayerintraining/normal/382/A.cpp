#include <iostream>

int main(){
  int c;
  std::string left,right;
  while((c=std::cin.get())!='|'){
    left+=c;
  }
  while((c=std::cin.get())!='\n'){
    right+=c;
  }
  while(std::isspace(std::cin.peek())){
    std::cin.get();
  }
  while((c=std::cin.get())!='\n'){
    if(left.size()<right.size()){
      left+=c;
    }else{
      right+=c;
    }
  }
  if(left.size()!=right.size()){
    std::cout<<"Impossible"<<std::endl;
  }else{
    std::cout<<left<<"|"<<right<<std::endl;
  }
  return 0;
}