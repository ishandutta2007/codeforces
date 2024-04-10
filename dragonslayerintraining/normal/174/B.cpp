#include <iostream>
#include <vector>

std::vector<std::string> v,s;

int main(){
  v.push_back("");
  char c;
  while((c=std::cin.get())!='\n'){
    if(c=='.'){
      v.push_back("");
    }else{
      v.back().push_back(c);
    }
  }
  if(v.size()<2){
    std::cout<<"NO"<<std::endl;
    return 0;
  }
  s.push_back(v.front());
  for(int i=1;i<v.size()-1;i++){
    std::string str;
    if(v[i].size()<=1){
      std::cout<<"NO"<<std::endl;
      return 0;
    }
    for(int j=0;j<v[i].size();j++){
      if(j==std::max<int>(v[i].size()-8,1)){
	s.push_back(str);
	str.clear();
      }
      str+=v[i][j];
    }
    s.push_back(str);
  }
  s.push_back(v.back());
  
  for(int i=0;i<s.size();i+=2){
    if((s[i].size()<1)||(s[i].size()>8)){
      std::cout<<"NO"<<std::endl;
      return 0;
    }
    if((s[i+1].size()<1)||(s[i+1].size()>3)){
      std::cout<<"NO"<<std::endl;
      return 0;
    }
  }
  std::cout<<"YES"<<std::endl;
  for(int i=0;i<s.size();i+=2){
    std::cout<<s[i]<<"."<<s[i+1]<<std::endl;
  }
  
  return 0;
}