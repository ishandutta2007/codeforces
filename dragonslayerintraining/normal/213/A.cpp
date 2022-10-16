#include <iostream>
#include <vector>

int uf[200];

int where[200];
std::vector<int> depend[200];
int moves[200];

void dfs(int node){
  if(moves[node]>0){
    return;
  }
  for(int dep:depend[node]){
    dfs(dep);
    moves[node]=std::max(moves[node],
			 moves[dep]+(where[node]-where[dep]+3)%3);
  }
}

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int C;
    std::cin>>C;
    C--;
    where[i]=C;
  }
  for(int i=0;i<N;i++){
    int K;
    std::cin>>K;
    for(int j=0;j<K;j++){
      int D;
      std::cin>>D;
      D--;
      depend[i].push_back(D);
    }
  }
  int cost[3]={0,0,0};
  for(int i=0;i<N;i++){
    dfs(i);
    for(int s=0;s<3;s++){
      cost[s]=std::max(cost[s],moves[i]+(s-where[i]+3)%3);
    }
  }
  std::cout<<N+std::min(cost[0],std::min(cost[1],cost[2]))<<std::endl;
  return 0;
}