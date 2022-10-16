#include <iostream>
#include <vector>
#include <map>
#include <queue>

#define ROW(r) (r)
#define COL(c) (N+(c))
#define LMP(l) (N+M+(l))
#define DEST (N+M+K)

int N,M,K;

std::vector<std::pair<int,int> > graph[30001];

std::map<std::pair<int,int>,int> at;
std::vector<std::pair<int,int> > lamps;


void link(int i,int j,int cost){
  graph[i].emplace_back(j,cost);
}

void adj_link(int i,int j){
  link(LMP(i),LMP(j),0);
  link(LMP(j),LMP(i),0);
}

int dist[30001];

void out(int index){
  if(index<N){
    std::cerr<<"ROW("<<index+1<<")";
  }else if(index<N+M){
    std::cerr<<"COL("<<index-N+1<<")";
  }else if(index<N+M+K){
    std::cerr<<"LMP("<<index-N-M+1<<")";
  }else{
    std::cerr<<"DEST";
  }
}

int main(){
  std::cin>>N>>M>>K;
  std::fill(dist,dist+N+M+K+1,1e9);
  for(int i=0;i<K;i++){
    int R,C;
    std::cin>>R>>C;
    R--,C--;
    lamps.emplace_back(R,C);
    at[std::make_pair(R,C)]=i;
    if(at.count(std::make_pair(R-1,C))){
      adj_link(i,at[std::make_pair(R-1,C)]);
    }
    if(at.count(std::make_pair(R+1,C))){
      adj_link(i,at[std::make_pair(R+1,C)]);
    }
    if(at.count(std::make_pair(R,C-1))){
      adj_link(i,at[std::make_pair(R,C-1)]);
    }
    if(at.count(std::make_pair(R,C+1))){
      adj_link(i,at[std::make_pair(R,C+1)]);
    }
    if(R-1>=0){
      link(ROW(R-1),LMP(i),0);
    }
    link(ROW(R),LMP(i),0);
    if(R+1<N){
      link(ROW(R+1),LMP(i),0);
    }
    
    if(C-1>=0){
      link(COL(C-1),LMP(i),0);
    }
    link(COL(C),LMP(i),0);
    if(C+1<M){
      link(COL(C+1),LMP(i),0);
    }
    if(R-1>=0){
      link(LMP(i),ROW(R-1),1);
    }
    link(LMP(i),ROW(R),1);
    if(R+1<N){
      link(LMP(i),ROW(R+1),1);
    }
    
    if(C-1>=0){
      link(LMP(i),COL(C-1),1);
    }
    link(LMP(i),COL(C),1);
    if(C+1<M){
      link(LMP(i),COL(C+1),1);
    }
  }
  link(ROW(N-1),DEST,0);
  link(COL(M-1),DEST,0);

  if(at.count(std::make_pair(N-1,M-1))){
    link(LMP(at[std::make_pair(N-1,M-1)]),DEST,0);
  }
    
  std::priority_queue<std::pair<int,int> > frontier;
  frontier.emplace(LMP(at[std::make_pair(0,0)]),0);
  while(!frontier.empty()){
    int node=frontier.top().first;
    int ds=-frontier.top().second;
    frontier.pop();
    if(ds<dist[node]){
      dist[node]=ds;
    }else{
      continue;
    }
    for(std::pair<int,int> edge:graph[node]){
      if(ds+edge.second<dist[edge.first]){
	/*
	out(node);
	std::cerr<<"=>";
	out(edge.first);
	std::cerr<<" "<<(ds+edge.second)<<std::endl;
	*/
	frontier.emplace(edge.first,-(ds+edge.second));
      }
    }
  }
  /*
  for(int i=0;i<N;i++){
    std::cerr<<"ROW("<<i+1<<"): "<<dist[ROW(i)]<<std::endl;
  }
  for(int i=0;i<M;i++){
    std::cerr<<"COL("<<i+1<<"): "<<dist[COL(i)]<<std::endl;
  }
  for(int i=0;i<K;i++){
    std::cerr<<"LMP("<<i+1<<"): "<<dist[LMP(i)]<<std::endl;
  }
  */
  if(dist[DEST]==1e9){
    std::cout<<-1<<std::endl;
  }else{
    std::cout<<dist[DEST]<<std::endl;
  }
  return 0;
}