#include <iostream>

int getspinner(){
  std::string str;
  std::cin>>str;
  switch(str[0]){
  case '^':return 0;
  case '>':return 1;
  case 'v':return 2;
  case '<':return 3;
  }
}

int main(){
  int s1=getspinner();
  int s2=getspinner();
  int N;
  std::cin>>N;
  switch((((s1+N)%4==s2)<<1)|((s2+N)%4==s1)){
  case 1:
    std::cout<<"ccw"<<std::endl;
    break;
  case 2:
    std::cout<<"cw"<<std::endl;
    break;
  default:
    std::cout<<"undefined"<<std::endl;
    break;
  }
  return 0;
}