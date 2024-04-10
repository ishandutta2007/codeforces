#include <iostream>
#include <vector>

int main(){
  std::string line;
  std::cin>>line;
  std::vector<std::string> toks;
  toks.push_back("");
  for(int i=0;i<line.length();i++){
    if(line[i]=='/'){
      if(!toks.back().empty()){
	toks.push_back("");
      }
    }else{
      toks.back()+=line[i];
    }
  }
  if(toks.back().empty()){
    toks.pop_back();
  }
  if(toks.empty()){
    std::cout<<'/'<<std::endl;
  }else{
    for(int i=0;i<toks.size();i++){
      std::cout<<'/'<<toks[i];
    }
    std::cout<<std::endl;
  }
  return 0;
}