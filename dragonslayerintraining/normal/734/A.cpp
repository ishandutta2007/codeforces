#include <iostream>

int diff=0;

int main(){
  int N;
  std::cin>>N;
  std::string str;
  std::cin>>str;
  for(int i=0;i<str.length();i++){
    if(str[i]=='A'){
      diff++;
    }else{
      diff--;
    }
  }
  if(diff>0){
    std::cout<<"Anton"<<std::endl;
  }else if(diff<0){
    std::cout<<"Danik"<<std::endl;
  }else{
    std::cout<<"Friendship"<<std::endl;
  }
  return 0;
}