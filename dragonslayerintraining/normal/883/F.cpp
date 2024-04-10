#include <iostream>
#include <set>

std::string canon_u(std::string str){
  std::string res;
  for(char c:str){
    if(c=='u'){
      res+="oo";
    }else{
      res+=c;
    }
  }
  return res;
}

std::string canon_h(std::string str){
  std::string res;
  int cnt=0;
  for(char c:str){
    if(c=='k'){
      cnt++;
    }else{
      if(c=='h'){
	res+='h';
      }else{
	while(cnt-->0){
	  res+='k';
	}
	res+=c;
      }
      cnt=0;
    }
  }
  while(cnt-->0){
    res+='k';
  }
  return res;
}

std::set<std::string> set;

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::string str;
    std::cin>>str;
    str=canon_u(str);
    str=canon_h(str);
    set.insert(str);
  }
  std::cout<<set.size()<<std::endl;
  return 0;
}