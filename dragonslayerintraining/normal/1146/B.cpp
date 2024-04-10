#include <iostream>

std::string S,T;

int main(){
  std::cin>>T;
  int cnt=0;
  for(char c:T){
    if(c!='a') cnt++;
  }
  S=T.substr(0,T.length()-cnt/2);
  std::string T2=S;
  for(char c:S){
    if(c!='a'){
      T2+=c;
    }
  }
  if(T2==T){
    std::cout<<S<<std::endl;
  }else{
    std::cout<<":("<<std::endl;
  }
  return 0;
}