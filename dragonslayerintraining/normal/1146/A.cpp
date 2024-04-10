#include <iostream>
#include <algorithm>

int main(){
  std::string str;
  std::cin>>str;
  int cnt=0;
  for(char c:str){
    if(c=='a') cnt++;
  }
  std::cout<<std::min<int>(str.length(),cnt*2-1)<<std::endl;
  return 0;
}