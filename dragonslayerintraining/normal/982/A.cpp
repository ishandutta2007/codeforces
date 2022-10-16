#include <iostream>

bool good(std::string str){
  for(int i=1;i<str.length();i++){
    if(str[i-1]=='1'&&str[i]=='1'){
      return false;
    }
  }
  return true;
}

int main(){
  int N;
  std::string str;
  std::cin>>N>>str;
  if(!good(str)){
    std::cout<<"No"<<std::endl;
    return 0;
  }
  for(int i=0;i<str.length();i++){
    if(str[i]=='1') continue;
    str[i]='1';
    if(good(str)){
      std::cout<<"No"<<std::endl;
      return 0;
    }
    str[i]='0';
  }
  std::cout<<"Yes"<<std::endl;
  return 0;
}