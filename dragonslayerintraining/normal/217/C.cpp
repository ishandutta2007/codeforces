#include <iostream>
#include <cctype>

int oper(char op,int left,int right){
  switch(op){
  case '|':
    return left|right;
  case '&':
    return left&right;
  case '^':
    return left^right;
  }
}

int parse(){
  while(true){
    switch(std::cin.get()){
    case '0':return 0x1;
    case '1':return 0x8;
    case '?':return 0x6;
    case '(':{
      int left=parse();
      char op=std::cin.get();
      int right=parse();
      std::cin.get();
      int ret=0;
      for(int l=0;l<4;l++){
	if(left&(1<<l)){
	  for(int r=0;r<4;r++){
	    if(right&(1<<r)){
	      int gate=oper(op,l,r);
	      ret|=(1<<gate);
	    }
	  }
	}
      }
      return ret;
    }
    default:
      continue;
    }
  }
}

int main(){
  int N;
  std::cin>>N;
  int val=parse();
  if(val&6){
    std::cout<<"YES"<<std::endl;
  }else{
    std::cout<<"NO"<<std::endl;
  }
  return 0;
}