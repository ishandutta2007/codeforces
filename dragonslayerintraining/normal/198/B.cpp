#include <iostream>
#include <algorithm>
#include <queue>

int N,K;

struct cpath{
  int len,where,s;
  cpath(int len,int where,int s):len(len),where(where),s(s){
  }
  bool operator<(struct cpath other)const{
    return len>other.len;
  }
};
std::string side[2];
int shortest[2][100000];
int main(){
  std::cin>>N>>K;
  std::cin>>side[0]>>side[1];
  for(int i=0;i<2;i++){
    std::fill(shortest[i],shortest[i]+N,1e7);
  }
  std::priority_queue<struct cpath> frontier;
  frontier.push(cpath(0,0,0));
  while(!frontier.empty()){
    struct cpath path=frontier.top();
    frontier.pop();
    if(path.where<path.len){
      continue;
    }
    if(path.where>=N){
      std::cout<<"YES"<<std::endl;
      return 0;
    }
    if(side[path.s][path.where]=='X'){
      continue;
    }
    if(path.len>=shortest[path.s][path.where]){
      continue;
    }
    shortest[path.s][path.where]=path.len;
    frontier.push(cpath(path.len+1,path.where+1,path.s));
    frontier.push(cpath(path.len+1,path.where-1,path.s));
    frontier.push(cpath(path.len+1,path.where+K,path.s^1));
  }
  std::cout<<"NO"<<std::endl;
  return 0;
}