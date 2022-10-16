#include <iostream>
#include <algorithm>

bool ispal(std::string str){
  std::string rev(str);
  std::reverse(rev.begin(),rev.end());
  return str==rev;
}

int main(){
  std::string str;
  std::cin>>str;
  for(int i=0;i<15;i++){
    if(ispal(std::string(i,'0')+str)){
      std::cout<<"YES"<<std::endl;
      return 0;
    }
  }
  std::cout<<"NO"<<std::endl;
  return 0;
}