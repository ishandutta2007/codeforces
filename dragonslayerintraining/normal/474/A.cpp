#include <iostream>
#include <algorithm>

std::string kb=
  "qwertyuiop"
  "asdfghjkl;"
  "zxcvbnm,./";

int main(){
  std::string dir,str;
  std::cin>>dir>>str;
  int shift=(dir=="L")?1:-1;
  for(char& c:str){
    c=*(std::find(kb.begin(),kb.end(),c)+shift);
  }
  std::cout<<str<<std::endl;
  return 0;
}