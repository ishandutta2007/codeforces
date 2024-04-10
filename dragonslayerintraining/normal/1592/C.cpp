#include <cstdio>
#include <vector>

std::vector<std::vector<int> > edges;

int as[100005];
int sum[100005];

int state[100005];

void dfs(int x,int z){
  sum[x]=as[x];
  for(int y:edges[x]){
    if(y==z) continue;
    dfs(y,x);
    sum[x]^=sum[y];
  }
}

void dfs_check(int x,int z){
  state[x]=0;
  for(int y:edges[x]){
    if(y==z) continue;
    dfs_check(y,x);
    if(state[x]&state[y]&1){
      state[x]|=2;
    }
    state[x]|=state[y];
  }
  if(sum[x]==sum[0]){
    state[x]|=1;
  }
  if((state[x]&1)&&(sum[x]==0)){
    state[x]|=2;
  }
}

bool solve(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  edges.clear();
  edges.resize(N);
  for(int i=0;i<N-1;i++){
    int X,Y;
    scanf("%d %d",&X,&Y);
    X--,Y--;
    edges[X].push_back(Y);
    edges[Y].push_back(X);
  }
  dfs(0,0);
  if(sum[0]==0){
    return true;
  }
  if(K==2){
    return false;
  }
  dfs_check(0,0);
  if(state[0]&2){
    return true;
  }
  return false;
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    if(solve()){
      printf("YES\n");
    }else{
      printf("NO\n");
    }
  }
}