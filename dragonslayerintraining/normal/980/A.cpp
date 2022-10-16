#include <iostream>
#include <vector>

std::string str;

int main(){
  std::cin>>str;
  int pearls=0;
  for(char c:str){
    if(c=='o'){
      pearls++;
    }
  }
  if(pearls==0){
    std::cout<<"YES"<<std::endl;
    return 0;
  }
  if(str.length()%pearls){
    std::cout<<"NO"<<std::endl;
    return 0;
  }
  std::cout<<"YES"<<std::endl;
  return 0;
}