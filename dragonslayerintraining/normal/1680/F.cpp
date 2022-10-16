#include <cstdio>
#include <vector>

std::vector<std::vector<int> > adj;

bool vis[1000006];
int depth[1000006];
int anc[1000006][20];

int pre[1000006];
int post[1000006];
int euler=0;

long long sum[1000006];

void dfs_init(int x){
  vis[x]=true;
  pre[x]=euler++;
  for(int y:adj[x]){
    if(!vis[y]){
      depth[y]=depth[x]+1;
      anc[y][0]=x;
      //printf("par(%d)=%d\n",y,x);
      for(int k=1;k<20;k++){
	anc[y][k]=anc[anc[y][k-1]][k-1];
      }
      dfs_init(y);
    }
  }
  post[x]=euler;
}

int lca(int x,int y){
  if(depth[x]>depth[y]) std::swap(x,y);
  int diff=depth[y]-depth[x];
  for(int k=0;k<20;k++){
    if(diff&(1<<k)){
      y=anc[y][k];
    }
  }
  if(x==y) return x;
  for(int k=0;k<20;k++){
    if(anc[x][k]!=anc[y][k]){
      x=anc[x][k];
      y=anc[y][k];
    }
  }
  return anc[x][0];
}

std::vector<std::pair<int,int> > elist;


void dfs_sum(int x){
  vis[x]=true;
  for(int y:adj[x]){
    if(!vis[y]){
      dfs_sum(y);
      sum[x]+=sum[y];
    }
  }
}

void solve(){
  int N,M;
  scanf("%d %d",&N,&M);
  adj.clear();
  adj.resize(N);
  elist.clear();
  std::fill(sum,sum+N,0);
  for(int i=0;i<M;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    elist.emplace_back(U,V);
    adj[U].push_back(V);
    adj[V].push_back(U);
  }
  std::fill(vis,vis+N,false);
  euler=0;
  dfs_init(0);
  std::vector<std::pair<int,int> > bad;
  for(auto e:elist){
    int x=e.first,y=e.second;
    if(x==anc[y][0]||y==anc[x][0]) continue;
    int z=lca(x,y);
    //printf("LCA(%d,%d)=%d\n",x,y,z);
    if(depth[x]%2==depth[y]%2){
      bad.emplace_back(x,y);
      sum[x]++;
      sum[y]++;
      sum[z]-=2;
    }else{
      sum[x]--;
      sum[y]--;
      sum[z]+=2;
    }
  }
  if(bad.size()<=1){
    int flip=((bad.size()==1)&&(depth[bad[0].first]%2==0));
    printf("YES\n");
    for(int i=0;i<N;i++){
      printf("%d",(depth[i]+flip)%2);
    }
    printf("\n");
    return;
  }
  std::fill(vis,vis+N,false);
  dfs_sum(0);
  for(int i=0;i<N;i++){
    if(sum[i]==bad.size()){
      printf("YES\n");
      for(int j=0;j<N;j++){
	printf("%d",(depth[j]+depth[i]+(pre[i]<=pre[j]&&post[j]<=post[i]))%2);
      }
      printf("\n");
      return;
    }
  }
  printf("NO\n");
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}