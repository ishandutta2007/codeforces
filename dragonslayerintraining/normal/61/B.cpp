#include <iostream>
#include <cctype>
#include <algorithm>
#include <set>

void canonicalize(std::string& str){
  std::string ret;
  for(int i=0;i<str.length();i++){
    if(std::isalpha(str[i])){
      ret+=std::tolower(str[i]);
    }
  }
  str=ret;
}

std::set<std::string> combos;

int main(){
  std::string str[3];
  std::cin>>str[0]>>str[1]>>str[2];
  for(int i=0;i<3;i++){
    canonicalize(str[i]);
  }
  for(int i=0;i<6;i++){
    combos.insert(str[0]+str[1]+str[2]);
    std::next_permutation(str,str+3);
  }
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::string line;
    std::cin>>line;
    canonicalize(line);
    if(combos.count(line)){
      std::cout<<"ACC"<<std::endl;
    }else{
      std::cout<<"WA"<<std::endl;
    }
  }
  return 0;
}