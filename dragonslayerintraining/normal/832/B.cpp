#include <iostream>

int good[256];
int wildcard=-1;

std::string pattern;

bool match(std::string query){
  if(query.length()<pattern.length()){
    return false;
  }
  if(wildcard==-1){
    if(query.length()!=pattern.length()){
      return false;
    }
    for(int i=0;i<query.length();i++){
      if((query[i]!=pattern[i])&&
	 ((pattern[i]!='?')||(!good[query[i]]))){
	return false;
      }
    }
    return true;
  }
  for(int i=0;i<wildcard;i++){
    if((query[i]!=pattern[i])&&
       ((pattern[i]!='?')||(!good[query[i]]))){
      return false;
    }
  }
  for(int i=0;i<query.length()-pattern.length();i++){
    if(good[query[wildcard+i]]){
      return false;
    }
  }
  int shift=query.size()-pattern.size();
  for(int i=wildcard;i<pattern.size();i++){
    if((query[i+shift]!=pattern[i])&&
       ((pattern[i]!='?')||(!good[query[i+shift]]))){
      return false;
    }
  }
  return true;
}

int main(){
  std::string goodstr;
  std::cin>>goodstr;
  for(char c:goodstr){
    good[c]=1;
  }
  std::cin>>pattern;
  for(int i=0;i<pattern.size();i++){
    if(pattern[i]=='*'){
      wildcard=i;
      pattern.erase(pattern.begin()+wildcard);
      break;
    }
  }
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::string query;
    std::cin>>query;
    if(match(query)){
      std::cout<<"YES"<<std::endl;
    }else{
      std::cout<<"NO"<<std::endl;
    }
  }
  return 0;
}