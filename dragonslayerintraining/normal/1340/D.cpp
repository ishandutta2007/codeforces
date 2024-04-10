#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<int> edges[100005];
int D;

std::vector<std::pair<int,int> > moves;

void dfs(int node,int t){
  bool flipped=false;
  moves.push_back({node,t});
  for(int child:edges[node]){
    edges[child].erase(std::find(edges[child].begin(),edges[child].end(),node));
    if(t==D){
      t-=1+edges[node].size();
      moves.push_back({node,t});
      flipped=true;
    }
    dfs(child,t+1);
    t++;
    moves.push_back({node,t});
  }
  if((t==D||!flipped)&&node!=1){
    t-=1+edges[node].size();
    moves.push_back({node,t});
  }
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N-1;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    edges[U].push_back(V);
    edges[V].push_back(U);
  }
  for(int i=1;i<=N;i++){
    D=std::max<int>(D,edges[i].size());
  }
  dfs(1,0);
  printf("%d\n",(int)moves.size());
  for(auto m:moves){
    printf("%d %d\n",m.first,m.second);
  }
}