#include <iostream>
#include <map>

bool test(){
  std::string str;
  std::cin>>str;
  std::map<char,int> cnt;
  for(char c:str) cnt[c]++;
  if(cnt.size()<2||cnt.size()>4) return false;
  int multi=0;
  for(auto pair:cnt){
    multi+=(pair.second>1);
  }
  return (cnt.size()+multi>=4);
}

int main(){
  std::cout<<(test()?"Yes":"No")<<std::endl;
  return 0;
}