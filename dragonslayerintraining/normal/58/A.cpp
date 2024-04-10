#include <iostream>

int main(){
  std::string str;
  std::cin>>str;
  int state=0;
  for(int i=0;i<str.length();i++){
    switch(state){
    case 0:if(str[i]=='h'){state++;}break;
    case 1:if(str[i]=='e'){state++;}break;
    case 2:if(str[i]=='l'){state++;}break;
    case 3:if(str[i]=='l'){state++;}break;
    case 4:if(str[i]=='o'){state++;}break;
    }
  }
  if(state==5){
    std::cout<<"YES"<<std::endl;
  }else{
    std::cout<<"NO"<<std::endl;
  }
  return 0;
}