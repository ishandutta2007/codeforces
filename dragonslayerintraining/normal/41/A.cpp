#include <iostream>
#include <algorithm>

int main(){
  std::string s,t;
  std::cin>>s>>t;
  std::reverse(s.begin(),s.end());
  if(s==t){
    std::cout<<"YES"<<std::endl;
  }else{
    std::cout<<"NO"<<std::endl;
  }
  return 0;
}