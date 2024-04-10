#include <iostream>

int min=0,max=0;

int main(){
  std::string str;
  std::cin>>str;
  int ac=0;
  for(int i=0;i<str.length();i++){
    if(str[i]=='+'){
      ac++;
    }else{
      ac--;
    }
    max=std::max(max,ac);
    min=std::min(min,ac);
  }
  std::cout<<max-min<<std::endl;
  return 0;
}