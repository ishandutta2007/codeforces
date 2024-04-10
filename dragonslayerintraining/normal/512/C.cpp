#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>

int N;
std::map<int,int> edges[202];
std::vector<int> backptr;

int as[202];

bool isprime(int num){
  if(num<2){
    return false;
  }
  for(int i=2;i*i<=num;i++){
    if(num%i==0){
      return false;
    }
  }
  return true;
}

std::vector<bool> visited;
std::vector<int> cycle;

std::vector<std::vector<int> > cycles;

void computecycles(int node){
  if(node>=N){
    return;
  }
  if(visited[node]){
    return;
  }
  visited[node]=true;
  cycle.push_back(node);
  bool iseven=(as[backptr[node]]%2==0);
  for(auto it:edges[node]){
    if(!iseven){
      if(it.second>0){
	computecycles(it.first);
      }
    }else{
      if(edges[it.first][node]){
	computecycles(it.first);
      }
    }
  }
}

int main(){
  std::cin>>N;
  int even_cnt=0;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
    if(as[i]%2==0){
      even_cnt++;
    }
  }
  if(even_cnt*2!=N){
    std::cout<<"Impossible"<<std::endl;
    return 0;
  }
  int even_index=0,odd_index=0;
  backptr.resize(N);
  for(int i=0;i<N;i++){
    if(as[i]%2==0){
      int index=even_index++;
      backptr[index]=i;
      edges[index][N]=0;
      edges[N][index]=2;
    }else{
      int index=even_cnt+(odd_index++);
      backptr[index]=i;
      edges[index][N+1]=2;
      edges[N+1][index]=0;
    }
  }
  for(int i=0;i<even_cnt;i++){
    for(int j=even_cnt;j<N;j++){
      if(isprime(as[backptr[i]]+as[backptr[j]])){
	//std::cout<<as[backptr[i]]<<"+"<<as[backptr[j]]<<" is prime"<<std::endl;
	edges[i][j]=1;
	edges[j][i]=0;
      }
    }
  }
  std::vector<int> prev;
  std::vector<int> widest;
  prev.resize(N+2);
  widest.resize(N+2);
  while(true){
    std::fill(prev.begin(),prev.end(),-1);
    std::fill(widest.begin(),widest.end(),0);
    std::priority_queue<std::pair<int,std::pair<int,int> > >frontier;
    frontier.push(std::make_pair(1e9,std::make_pair(N,N)));
    while(!frontier.empty()){
      int width=frontier.top().first;
      int node=frontier.top().second.first;
      int parent=frontier.top().second.second;
      frontier.pop();
      if(width<=widest[node]){
	continue;
      }
      widest[node]=width;
      prev[node]=parent;
      for(auto it:edges[node]){
	frontier.push(std::make_pair(std::min(width,it.second),std::make_pair(it.first,node)));
      }
    }
    int inc=widest[N+1];
    //std::cout<<"Widest: "<<inc<<std::endl;
    if(inc==0){
      break;
    }
    for(int node=N+1;node!=N;node=prev[node]){
      edges[node][prev[node]]+=inc;
      edges[prev[node]][node]-=inc;
    }
  }
  int flow=0;
  for(auto it:edges[N+1]){
    flow+=it.second;
  }
  if(flow!=N){
    std::cout<<"Impossible"<<std::endl;
    return 0;
  }
  visited.resize(N);
  for(int i=0;i<N;i++){
    computecycles(i);
    if(cycle.size()){
      cycles.push_back(cycle);
      cycle.clear();
    }
  }
  std::cout<<cycles.size()<<std::endl;
  for(const auto& cycle:cycles){
    std::cout<<cycle.size();
    for(int i=0;i<cycle.size();i++){
      std::cout<<" "<<backptr[cycle[i]]+1;
    }
    std::cout<<std::endl;
  }
  return 0;
}