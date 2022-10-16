#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

const int INF=1e9+7;

int N,M;

int deg[200005];
std::multiset<int> rev[200005];

int dist[200005];
bool vis[200005];

int main(){
  scanf("%d %d",&N,&M);
  for(int i=0;i<M;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    deg[U]++;
    rev[V].insert(U);
  }
  std::fill(dist,dist+N-1,INF);
  std::set<std::pair<int,int> > rest;
  for(int i=0;i<N;i++){
    rest.emplace(dist[i],i);
  }
  while(!vis[0]){
    int x=rest.begin()->second;
    rest.erase(rest.begin());
    vis[x]=true;
    for(int y:rev[x]){
      if(vis[y]) continue;
      deg[y]--;
      rest.erase({dist[y],y});
      dist[y]=std::min<int>(dist[y],dist[x]+deg[y]+1);
      rest.insert({dist[y],y});
    }
  }
  printf("%d\n",dist[0]);
}