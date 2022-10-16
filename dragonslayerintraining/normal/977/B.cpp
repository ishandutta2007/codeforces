#include <iostream>
#include <map>

std::map<std::string,int> cnt;

int main(){
  int N;
  std::string str;
  std::cin>>N;
  std::cin>>str;
  for(int i=1;i<str.length();i++){
    std::string sub;
    sub+=str[i-1];
    sub+=str[i];
    cnt[sub]++;
  }
  std::pair<int,std::string> max;
  for(auto pair:cnt){
    max=std::max(max,std::make_pair(pair.second,pair.first));
  }
  std::cout<<max.second<<std::endl;
  return 0;
}