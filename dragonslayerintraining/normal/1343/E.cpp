#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

const long long INF=1e14+7;

long long ps[200005];

std::vector<int> adj[200005];

int N,M,A,B,C;

int da[200005];
int db[200005];
int dc[200005];

void bfs(int s,int* dist){
  std::fill(dist,dist+N,-1);
  std::queue<int> q;
  q.push(s);
  dist[s]=0;
  while(!q.empty()){
    int x=q.front();
    q.pop();
    for(int y:adj[x]){
      if(dist[y]==-1){
	dist[y]=dist[x]+1;
	q.push(y);
      }
    }
  }
}

void solve(){
  scanf("%d %d %d %d %d",&N,&M,&A,&B,&C);
  A--,B--,C--;
  for(int i=1;i<=M;i++){
    scanf("%lld",&ps[i]);
  }
  std::sort(ps+1,ps+M+1);
  for(int i=1;i<=M;i++){
    ps[i]+=ps[i-1];
  }
  std::fill(adj,adj+N,std::vector<int>());
  for(int i=0;i<M;i++){
    int X,Y;
    scanf("%d %d",&X,&Y);
    X--,Y--;
    adj[X].push_back(Y);
    adj[Y].push_back(X);
  }
  bfs(A,da);
  bfs(B,db);
  bfs(C,dc);
  long long best=INF;
  for(int i=0;i<N;i++){
    int x=db[i],y=da[i]+db[i]+dc[i];
    //printf("%d: %d %d %d (%d,%d)\n",i,da[i],db[i],dc[i],x,y);
    if(y<N){
      best=std::min(best,ps[x]+ps[y]);
    }
  }
  printf("%lld\n",best);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}