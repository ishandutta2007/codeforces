#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

int hs[200005];
std::vector<int> adj[200005];
int max[200005];

long long cost=0;

void dfs(int x,int par){
  for(int y:adj[x]){
    if(y==par) continue;
    dfs(y,x);
    max[x]=std::max(max[x],max[y]);
  }
  if(hs[x]>max[x]){
    cost+=hs[x]-max[x];
    max[x]=hs[x];
  }
}


int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&hs[i]);
  }
  for(int i=0;i<N-1;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    adj[U].push_back(V);
    adj[V].push_back(U);
  }
  int root=std::max_element(hs,hs+N)-hs;
  std::multiset<int> set;
  set.insert(0);
  for(int y:adj[root]){
    dfs(y,root);
    set.insert(max[y]);
    if(set.size()>2){
      set.erase(set.begin());
    }
  }
  for(int v:set){
    cost+=hs[root]-v;
  }
  printf("%lld\n",cost);
}