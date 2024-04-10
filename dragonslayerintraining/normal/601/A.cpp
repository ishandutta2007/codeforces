#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

int adj[400][400];
int N,M;

int distance[400];

void bfs(int type){
  std::fill(distance,distance+400,1e9);
  std::queue<std::pair<int,int> > frontier;
  frontier.emplace(0,0);
  while(!frontier.empty()){
    int node,dist;
    std::tie(node,dist)=frontier.front();
    frontier.pop();
    if(dist>=distance[node]){
      continue;
    }
    distance[node]=dist;
    for(int i=0;i<N;i++){
      if(adj[node][i]==type){
	frontier.emplace(i,dist+1);
      }
    }
  }
}


int main(){
  std::cin>>N>>M;
  for(int i=0;i<M;i++){
    int U,V;
    std::cin>>U>>V;
    U--,V--;
    adj[U][V]=1;
    adj[V][U]=1;
  }
  int worst=0;
  bfs(0);
  worst=std::max(worst,distance[N-1]);
  bfs(1);
  worst=std::max(worst,distance[N-1]);
  if(worst<1e9){
    std::cout<<worst<<std::endl;
  }else{
    std::cout<<-1<<std::endl;
  }
  return 0;
}