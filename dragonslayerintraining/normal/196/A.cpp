#include <iostream>
#include <algorithm>

int main(){
  std::string str;
  std::cin>>str;
  std::string res;
  char last='\0';
  for(int i=str.length()-1;i>=0;i--){
    if(str[i]>=last){
      res+=str[i];
      last=str[i];
    }
  }
  std::reverse(res.begin(),res.end());
  std::cout<<res<<std::endl;
  return 0;
}