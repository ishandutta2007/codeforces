#include <iostream>
#include <vector>

struct Edge{
  int other,cost;
  Edge(int other,int cost):other(other),cost(cost){
  }
};

std::vector<struct Edge> edges[200000];
int cost[200000];


int dfs1(int node,int parent){
  int sum=0;
  for(struct Edge edge:edges[node]){
    int child=edge.other;
    if(child!=parent){
      sum+=edge.cost;
      sum+=dfs1(child,node);
    }
  }
  return sum;
}

void dfs2(int node,int parent,int above){
  cost[node]=above;
  for(struct Edge edge:edges[node]){
    int child=edge.other;
    if(child!=parent){
      dfs2(child,node,above-2*edge.cost+1);
    }
  }
}

int main(){
  int N;
  std::cin>>N;
  for(int i=1;i<N;i++){
    int S,T;
    std::cin>>S>>T;
    S--,T--;
    edges[S].push_back(Edge(T,0));
    edges[T].push_back(Edge(S,1));
  }
  dfs2(0,0,dfs1(0,0));
  std::vector<int> capital;
  int best=1e9;
  for(int i=0;i<N;i++){
    if(cost[i]<best){
      best=cost[i];
      capital.clear();
      capital.push_back(i);
    }else if(cost[i]==best){
      capital.push_back(i);
    }
  }
  std::cout<<best<<std::endl;
  for(int i=0;i<capital.size();i++){
    if(i>0){
      std::cout<<" ";
    }
    std::cout<<capital[i]+1;
  }
  std::cout<<std::endl;
  return 0;
}