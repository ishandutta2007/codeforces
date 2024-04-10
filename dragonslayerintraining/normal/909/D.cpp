#include <iostream>
#include <vector>

std::vector<std::pair<char,int> > compress(std::vector<std::pair<char,int> > gs){
  std::vector<std::pair<char,int> > ret;
  for(std::pair<char,int> pair:gs){
    if(pair.second<=0){
      continue;
    }
    if(ret.empty()||(ret.back().first!=pair.first)){
      ret.push_back(pair);
    }else{
      ret.back().second+=pair.second;
    }
  }
  return ret;
}

int main(){
  std::string str;
  std::cin>>str;
  std::vector<std::pair<char,int> > gs;
  for(char c:str){
    gs.emplace_back(c,1);
  }
  gs=compress(gs);
  int cnt=0;
  while(gs.size()>1){
    gs.front().second++;
    gs.back().second++;
    for(std::pair<char,int>& g:gs){
      g.second-=2;
    }
    gs=compress(gs);
    cnt++;
  }
  std::cout<<cnt<<std::endl;
  return 0;
}