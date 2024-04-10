#include <cstdio>
#include <vector>

std::vector<std::vector<int> > adj;

bool leaf[200005];

void dfs(int x,int par){
  leaf[x]=true;
  for(int y:adj[x]){
    if(y==par) continue;
    dfs(y,x);
    if(leaf[y]){
      leaf[x]=false;
    }
  }
}

void solve(){
  int N;
  scanf("%d",&N);
  adj.clear();
  adj.resize(N);
  for(int i=0;i<N-1;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    adj[U].push_back(V);
    adj[V].push_back(U);
  }
  dfs(0,-1);
  int cnt=0;
  for(int i=0;i<N;i++){
    if(leaf[i]){
      cnt++;
    }else if(i!=0){
      cnt--;
    }
  }
  printf("%d\n",cnt);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}