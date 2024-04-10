#include <cstdio>
#include <iostream>
#include <algorithm>

std::string read(){
  std::string r1,r2;
  std::cin>>r1>>r2;
  std::string res=r1+r2[1]+r2[0];
  res.erase(std::remove(res.begin(),res.end(),'X'),res.end());
  return res;
}

int main(){
  std::string S=read(),T=read();
  for(int i=0;i<3;i++){
    if(S==T){
      std::cout<<"YES"<<std::endl;
      return 0;
    }
    std::rotate(S.begin(),S.begin()+1,S.end());
  }
  std::cout<<"NO"<<std::endl;
  return 0;
}