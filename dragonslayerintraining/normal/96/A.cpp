#include <iostream>

int main(){
  std::string str;
  std::cin>>str;
  int run=0;
  char player='\0';
  for(int i=0;i<str.length();i++){
    if(str[i]==player){
      run++;
    }else{
      player=str[i];
      run=1;
    }
    if(run>=7){
      std::cout<<"YES"<<std::endl;
      return 0;
    }
  }
  std::cout<<"NO"<<std::endl;
  return 0;
}