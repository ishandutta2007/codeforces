#include <iostream>

int main(){
  std::string str;
  std::cin>>str;
  int cnt=0;
  for(char c:str){
    if(c=='x'){
      cnt++;
    }else{
      cnt--;
    }
  }
  for(int i=0;i<cnt;i++){
    std::cout<<'x';
  }
  for(int i=0;i<-cnt;i++){
    std::cout<<'y';
  }
  std::cout<<std::endl;
  return 0;
}