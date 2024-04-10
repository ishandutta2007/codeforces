#include <cstdio>
#include <vector>

const int MOD=1e9+7;

std::vector<std::pair<int,int> > adj[100005];
int ways=(MOD+1)/2;

int color[100005];

void dfs(int x,int c){
  if(color[x]==c) return;
  if(color[x]==(c^1)){
    ways=0;
    return;
  }
  color[x]=c;
  for(auto e:adj[x]){
    dfs(e.first,c^e.second);
  }
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<M;i++){
    int A,B,C;
    scanf("%d %d %d",&A,&B,&C);
    A--,B--;
    adj[A].push_back({B,C^1});
    adj[B].push_back({A,C^1});
  }
  std::fill(color,color+N,-1);
  for(int i=0;i<N;i++){
    if(color[i]==-1){
      ways=2LL*ways%MOD;
      dfs(i,0);
    }
  }
  printf("%d\n",ways);
}