#include <iostream>
#include <vector>
#include <map>

std::map<char,char> map;

int main(){
  std::string str1,str2;
  std::cin>>str1>>str2;
  for(int i=0;i<str1.length();i++){
    if(map.count(str1[i])&&(map[str1[i]]!=str2[i])){
      std::cout<<-1<<std::endl;
      return 0;
    }
    if(map.count(str2[i])&&(map[str2[i]]!=str1[i])){
      std::cout<<-1<<std::endl;
      return 0;
    }
    map[str1[i]]=str2[i];
    map[str2[i]]=str1[i];
  }
  std::vector<std::pair<char,char> > out;
  for(std::pair<char,char> pair:map){
    if(pair.first<pair.second){
      out.push_back(pair);
    }
  }
  std::cout<<out.size()<<std::endl;
  for(std::pair<char,char> pair:out){
    std::cout<<pair.first<<" "<<pair.second<<std::endl;
  }
  return 0;
}