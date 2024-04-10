#include <iostream>
#include <vector>
#include <cctype>

bool test(){
  std::string list;
  std::cin>>list;
  std::vector<std::string> toks;
  toks.push_back("");
  for(int i=0;i<list.length();i++){
    if(list[i]=='@'){
      toks.push_back("");
    }else{
      if(!std::islower(list[i])){
	return false;
      }
      toks.back()+=list[i];
    }
  }
  if(toks.size()==1){
    return false;
  }
  if(toks[0].size()==0){
    return false;
  }
  if(toks[toks.size()-1].size()==0){
    return false;
  }
  for(int i=1;i<toks.size()-1;i++){
    if(toks[i].size()<2){
      return false;
    }
  }
  std::cout<<toks[0];
  for(int i=1;i<toks.size()-1;i++){
    std::cout<<"@"<<toks[i][0]<<","<<toks[i].substr(1,std::string::npos);
  }
  std::cout<<"@"<<toks[toks.size()-1]<<std::endl;
  return true;
}

int main(){
  if(!test()){
    std::cout<<"No solution"<<std::endl;
  }
  return 0;
}