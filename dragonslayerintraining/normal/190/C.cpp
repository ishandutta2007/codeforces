#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <cstdlib>

std::ostringstream out;

void parse(){
  std::string type;
  std::cin>>type;
  if(type=="pair"){
    out<<"pair<";
    parse();
    out<<",";
    parse();
    out<<">";
  }else if(type=="int"){
    out<<"int";
  }else{
    std::cout<<"Error occurred"<<std::endl;
    exit(0);
  }
}

int main(){
  int N;
  std::cin>>N;
  parse();
  std::string type;
  std::cin>>type;
  if(type!=""){
    std::cout<<"Error occurred"<<std::endl;
  }else{
    std::cout<<out.str()<<std::endl;
  }
  return 0;
}