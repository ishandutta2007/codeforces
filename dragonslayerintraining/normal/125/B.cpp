#include <iostream>
#include <vector>

struct ctoken{
  enum etype{
    OPEN,
    CLOSE
  }type;
  char c;
  ctoken(enum etype type,char c):type(type),c(c){
  }
};

std::vector<struct ctoken> tokens;

void lex(){
  std::string str;
  std::cin>>str;
  for(int i=0;i<str.length();i++){
    if(str[i]=='<'){
      if(str[i+1]=='/'){
	tokens.push_back(ctoken(ctoken::CLOSE,str[i+2]));
      }else{
	tokens.push_back(ctoken(ctoken::OPEN,str[i+1]));
      }
    }
  }
}

int main(){
  lex();
  int indent=0;
  for(int i=0;i<tokens.size();i++){
    switch(tokens[i].type){
    case ctoken::OPEN:
      std::cout<<std::string(indent,' ');
      std::cout<<"<"<<tokens[i].c<<">"<<std::endl;
      indent+=2;
      break;
    case ctoken::CLOSE:
      indent-=2;
      std::cout<<std::string(indent,' ');
      std::cout<<"</"<<tokens[i].c<<">"<<std::endl;
      break;
    }
  }
  return 0;
}