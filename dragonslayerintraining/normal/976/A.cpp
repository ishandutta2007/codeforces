#include <iostream>

int main(){
  int N;
  std::string str;
  std::cin>>N;
  std::cin>>str;
  if(str=="0"){
    std::cout<<"0"<<std::endl;
    return 0;
  }
  int zero=0;
  for(char c:str){
    if(c=='0'){
      zero++;
    }
  }
  std::cout<<"1"<<std::string(zero,'0')<<std::endl;
  return 0;
}