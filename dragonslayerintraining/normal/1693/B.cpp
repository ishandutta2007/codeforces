#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<std::vector<int> > children;
int ls[200005];
int rs[200005];
int vs[200005];

int cost;

void dfs(int x){
  for(int y:children[x]){
    dfs(y);
    vs[x]+=vs[y];
    vs[x]=std::min(vs[x],rs[x]);
  }
  if(vs[x]<ls[x]){
    vs[x]=rs[x];
    cost++;
  }
}

void solve(){
  int N;
  scanf("%d",&N);
  children.clear();
  children.resize(N);
  std::fill(vs,vs+N,0);
  for(int i=1;i<N;i++){
    int P;
    scanf("%d",&P);
    P--;
    children[P].push_back(i);
  }
  for(int i=0;i<N;i++){
    scanf("%d %d",&ls[i],&rs[i]);
  }
  cost=0;
  dfs(0);
  printf("%d\n",cost);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}