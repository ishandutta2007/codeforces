#include <iostream>

int cnt[256];

int main(){
  int N;
  std::string str;
  std::cin>>N>>str;
  for(char c:str){
    cnt[c]++;
  }
  std::cout<<2*std::min(cnt['U'],cnt['D'])+2*std::min(cnt['L'],cnt['R'])<<std::endl;
  return 0;
}