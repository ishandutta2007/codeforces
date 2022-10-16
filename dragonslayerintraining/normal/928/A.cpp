#include <iostream>

void canonicalize(std::string& str){
  for(char& c:str){
    c=std::tolower(c);
    if(c=='o') c='0';
    if(c=='l') c='1';
    if(c=='i') c='1';
  }
}

int main(){
  std::string s;
  std::cin>>s;
  canonicalize(s);
  int N;
  std::cin>>N;
  while(N-->0){
    std::string t;
    std::cin>>t;
    canonicalize(t);
    if(s==t){
      std::cout<<"No"<<std::endl;
      return 0;
    }
  }
  std::cout<<"Yes"<<std::endl;
}