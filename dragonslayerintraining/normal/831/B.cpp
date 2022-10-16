#include <iostream>
#include <algorithm>

char map[256];

int main(){
  std::string layout1,layout2,str;
  std::cin>>layout1>>layout2>>str;
  std::iota(map,map+256,0);
  for(int i=0;i<26;i++){
    map[layout1[i]]=layout2[i];
    map[layout1[i]+'A'-'a']=layout2[i]+'A'-'a';
  }
  for(int i=0;i<str.length();i++){
    std::cout<<map[str[i]];
  }
  std::cout<<std::endl;
  return 0;
}