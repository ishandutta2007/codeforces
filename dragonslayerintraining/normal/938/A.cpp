#include <iostream>

bool isvowel(char c){
  return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y';
}

int main(){
  int N;
  std::string str;
  std::cin>>N;
  std::cin>>str;
  std::string res;
  for(char c:str){
    if(res.empty()||!isvowel(c)||!isvowel(res.back())){
      res.push_back(c);
    }
  }
  std::cout<<res<<std::endl;
  return 0;
}