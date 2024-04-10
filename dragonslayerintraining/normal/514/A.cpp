#include <iostream>

int main(){
  std::string str;
  std::cin>>str;
  bool first=true;
  for(char& c:str){
    if(!first||c!='9'){
      c=std::min<char>(c,'0'+'9'-c);
    }
    first=false;
  }
  std::cout<<str<<std::endl;
  return 0;
}