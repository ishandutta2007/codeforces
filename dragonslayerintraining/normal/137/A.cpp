#include <iostream>

int main(){
  std::string str;
  std::cin>>str;
  int run=0;
  int visits=0;
  for(int i=0;i<str.length();){
    for(int start=i;(i-start<5)&&(i<str.length());i++){
      if((i>start)&&(str[i]!=str[i-1])){
	break;
      }
    }
    visits++;
  }
  std::cout<<visits<<std::endl;
  return 0;
}