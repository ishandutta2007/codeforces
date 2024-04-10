#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>

#define FOX(i) (i)
#define SRC N
#define SINK (N+1)

int as[500];
int N;

std::vector<std::vector<int> > cycles;
bool visited[500];

struct Dinitz{
  int V;
  std::vector<int> head;
  std::vector<int> vertex;
  std::vector<int> conn;
  std::vector<int> res;
  std::vector<int> prev;
  std::vector<int> level;
  std::vector<int> curr;
  std::vector<int> orig;
  Dinitz(int V):V(V),head(V,-1),level(V){
  }
  void half_edge(int a,int b,int cap){
    prev.push_back(head[a]);
    head[a]=conn.size();
    
    vertex.push_back(a);
    conn.push_back(b);
    res.push_back(cap);
    orig.push_back(cap);
  }
  void add_edge(int a,int b,int cap){
    half_edge(a,b,cap);
    half_edge(b,a,0);
  }
  bool bfs(){
    std::fill(level.begin(),level.end(),V);
    std::queue<std::pair<int,int> > frontier;
    frontier.emplace(SRC,0);
    while(!frontier.empty()){
      int node=frontier.front().first;
      int dist=frontier.front().second;
      frontier.pop();
      if(level[node]<=dist){
	continue;
      }
      level[node]=dist;
      for(int e=head[node];e>=0;e=prev[e]){
	if(res[e]>0){
	  frontier.emplace(conn[e],dist+1);
	}
      }
    }
    return level[SINK]<V;
  }
  int dfs(int node,int flow){
    if(node==SINK){
      return flow;
    }
    for(;curr[node]>=0;curr[node]=prev[curr[node]]){
      int e=curr[node];
      if((level[conn[e]]==level[node]+1)&&(res[e]>0)){
	int min=dfs(conn[e],std::min(flow,res[e]));
	if(min>0){
	  res[e]-=min;
	  res[e^1]+=min;
	  return min;
	}
      }
    }
    return 0;
  }
  int maxflow(){
    int total=0;
    while(bfs()){
      curr=head;
      for(int aug;(aug=dfs(SRC,1e9))!=0;total+=aug);
    }
    return total;
  }
  void findcycles(int node){
    if(visited[node]){
      return;
    }
    visited[node]=true;
    
    cycles.back().push_back(node);
    for(int e=head[node];e>=0;e=prev[e]){
      if((res[e]!=orig[e])&&(conn[e]<N)){
	findcycles(conn[e]);
      }
    }
  }
};

bool isprime[20001];

int main(){
  std::fill(isprime+2,isprime+20001,true);
  for(int i=2;i<=20000;i++){
    if(isprime[i]){
      for(int k=i*2;k<=20000;k+=i){
	isprime[k]=false;
      }
    }
  }
  std::cin>>N;
  struct Dinitz dinitz(N+2);
  for(int i=0;i<N;i++){
    std::cin>>as[i];
  }
  for(int i=0;i<N;i++){
    if(as[i]%2==0){
      dinitz.add_edge(SRC,FOX(i),2);
    }else{
      dinitz.add_edge(FOX(i),SINK,2);
    }
  }
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      if(isprime[as[i]+as[j]]){
	int even=(as[i]%2==0)?i:j;
	int odd=(as[i]%2==1)?i:j;
	dinitz.add_edge(FOX(even),FOX(odd),1);
      }
    }
  }
  int maxflow=dinitz.maxflow();
  if(maxflow<N){
    std::cout<<"Impossible"<<std::endl;
    return 0;
  }
  cycles.emplace_back();
  assert(cycles.size()==1);
  assert(cycles.back().empty());
  for(int node=0;node<N;node++){
    dinitz.findcycles(node);
    if(cycles.back().size()>0){
      cycles.emplace_back();
    }
  }
  assert(cycles.back().empty());
  cycles.pop_back();
  std::cout<<cycles.size()<<std::endl;
  for(const std::vector<int>& cycle:cycles){
    std::cout<<cycle.size();
    for(int fox:cycle){
      std::cout<<" "<<fox+1;
    }
    std::cout<<std::endl;
  }
  return 0;
}