#include <iostream>

int main(){
  std::string str;
  std::cin>>str;
  int cost=0;
  for(int i=0;i<str.length();i++){
    if(std::isupper(str[i])){
      cost++;
    }
  }
  int best=cost;
  for(int i=0;i<str.length();i++){
    if(std::isupper(str[i])){
      cost--;
    }else{
      cost++;
    }
    best=std::min(best,cost);
  }
  std::cout<<best<<std::endl;
  return 0;
}