#include <iostream>
#include <algorithm>

std::string real,p1,p2;

bool test(){
  int mark=real.find(p1);
  if(mark==std::string::npos){
    return false;
  }
  mark=real.find(p2,mark+p1.length());
  if(mark==std::string::npos){
    return false;
  }
  return true;
}

int main(){
  std::cin>>real>>p1>>p2;
  bool fwd=test();
  std::reverse(real.begin(),real.end());
  bool bkwd=test();
  if(fwd&&bkwd){
    std::cout<<"both"<<std::endl;
  }else if(fwd){
    std::cout<<"forward"<<std::endl;
  }else if(bkwd){
    std::cout<<"backward"<<std::endl;
  }else{
    std::cout<<"fantasy"<<std::endl;
  }
  return 0;
}