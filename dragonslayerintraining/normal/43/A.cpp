#include <iostream>
#include <map>

int N;

std::map<std::string,int> map;

int main(){
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::string team;
    std::cin>>team;
    map[team]++;
  }
  std::string bestteam;
  int bestscore=0;
  for(std::map<std::string,int>::iterator it=map.begin();it!=map.end();it++){
    if(it->second>bestscore){
      bestscore=it->second;
      bestteam=it->first;
    }
  }
  std::cout<<bestteam<<std::endl;
  return 0;
}