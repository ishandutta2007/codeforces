#include <iostream>


int main(){
  std::string str;
  std::cin>>str;
  int cnt=0;
  for(int i=0;i<str.length();i++){
    switch(str[i]){
    case '0':
      cnt=cnt*2;
      break;
    case '1':
      cnt=cnt*2+1;
      break;
    default:
      for(;i<str.length();i++){
	cnt=cnt*2+1;
      }
      break;
    }
  }
  std::cout<<cnt<<std::endl;  
  return 0;
}