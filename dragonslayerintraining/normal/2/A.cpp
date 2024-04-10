#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>

std::vector<std::pair<std::string,int> > scores;
std::map<std::string,int> final;

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::string name;
    int delta;
    std::cin>>name>>delta;
    scores.push_back(std::pair<std::string,int>(name,delta));
    if(!final.count(name)){
      final[name]=0;
    }
    final[name]+=delta;
  }
  int maxscore=0;
  std::set<std::string> leaders;
  for(std::map<std::string,int>::iterator it=final.begin();it!=final.end();it++){
    maxscore=std::max(maxscore,it->second);
  }
  for(std::map<std::string,int>::iterator it=final.begin();it!=final.end();it++){
    if(it->second==maxscore){
      leaders.insert(it->first);
    }
  }
  final.clear();
  for(int i=0;i<N;i++){
    std::string name=scores[i].first;
    int delta=scores[i].second;
    if(!final.count(name)){
      final[name]=0;
    }
    final[name]+=delta;
    if((leaders.count(name))&&(final[name]>=maxscore)){
      std::cout<<name<<std::endl;
      return 0;
    }
  }
  
  return 0;
}