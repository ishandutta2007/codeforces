#include <cstdio>
#include <vector>

std::vector<int> edges[200005];
std::vector<std::pair<int,int> > elist;
std::vector<int> flow;
int ss[200005];

bool vis[200005];

int dfs(int node,int parent){
  if(vis[node]) return 0;
  vis[node]=true;
  for(int e:edges[node]){
    int other=elist[e].second;
    if(other==parent) continue;
    if(!vis[other]){
      flow[e]=dfs(other,node);
      flow[e^1]=-flow[e];
      ss[node]+=flow[e];
    }
  }
  return ss[node];
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&ss[i]);
  }
  int M;
  scanf("%d",&M);
  for(int i=0;i<M;i++){
    int X,Y;
    scanf("%d %d",&X,&Y);
    X--,Y--;
    edges[X].push_back(elist.size());
    elist.emplace_back(X,Y);
    edges[Y].push_back(elist.size());
    elist.emplace_back(Y,X);
  }
  flow.resize(elist.size());
  for(int i=0;i<N;i++){
    if(dfs(i,-1)){
      printf("Impossible\n");
      return 0;
    }
  }
  printf("Possible\n");
  for(int i=0;i<M;i++){
    printf("%d\n",flow[i<<1]);
  }
  return 0;
}