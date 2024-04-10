#include <iostream>
#include <algorithm>
#include <cstring>

std::string read(){
  std::string S;
  std::cin>>S;
  std::reverse(S.begin(),S.end());
  while(S.size()&&S.back()=='0'){
    S.erase(S.end()-1);
  }
  std::reverse(S.begin(),S.end());
  return S;
}

int main(){
  std::string A=read();
  std::string B=read();
  if(A.size()>B.size()){
    std::cout<<">"<<std::endl;
  }else if(A.size()<B.size()){
    std::cout<<"<"<<std::endl;
  }else{
    int cmp=strcmp(A.c_str(),B.c_str());
    if(cmp<0){
      std::cout<<"<"<<std::endl;
    }else if(cmp>0){
      std::cout<<">"<<std::endl;
    }else{
      std::cout<<"="<<std::endl;
    }
  }
}