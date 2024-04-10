#include <iostream>

int main(){
  std::string str1,str2;
  std::cin>>str1>>str2;
  for(int i=0;i<str1.length();i++){
    std::cout<<!(str1[i]==str2[i]);
  }
  std::cout<<std::endl;
  return 0;
}