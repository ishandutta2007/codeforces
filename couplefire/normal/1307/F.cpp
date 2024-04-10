#include <cstdio>
#include <vector>
#include <cassert>
#include <queue>
#include <algorithm>

const int INF=1e9+7;

std::vector<int> edges[400005];

int anc[19][400005];
int depth[400005];

void dfs(int node){
  for(int child:edges[node]){
    edges[child].erase(std::find(edges[child].begin(),edges[child].end(),node));
    anc[0][child]=node;
    for(int k=1;k<19;k++){
      anc[k][child]=anc[k-1][anc[k-1][child]];
    }
    depth[child]=depth[node]+1;
    dfs(child);
  }
}

int la(int node,int len){
  for(int k=19-1;k>=0;k--){
    if(len&(1<<k)){
      node=anc[k][node];
    }
  }
  return node;
}

int lca(int a,int b){
  if(depth[a]<depth[b]) std::swap(a,b);
  a=la(a,depth[a]-depth[b]);
  if(a==b) return a;
  for(int k=19-1;k>=0;k--){
    if(anc[k][a]!=anc[k][b]){
      a=anc[k][a];
      b=anc[k][b];
    }
  }
  return anc[0][a];
}

//move x steps from a to b
//assumes x<=dist(a,b)
int walk(int a,int b,int x){
  int c=lca(a,b);
  if(x<=depth[a]-depth[c]){
    return la(a,x);
  }
  int excess=x-(depth[a]-depth[c]);
  assert(excess<=(depth[b]-depth[c]));
  return la(b,depth[b]-depth[c]-excess);
}

int uf[400005];
int dist[400005];//dist[x]=0 iff x is rest stop

int find(int a){
  while(a!=uf[a]){
    a=uf[a]=uf[uf[a]];
  }
  return a;
}

bool query(int K){
  int A,B;
  scanf("%d %d",&A,&B);
  A--,B--;
  int C=lca(A,B);
  if(depth[A]+depth[B]-2*depth[C]<=2*K){
    return true;
  }else{
    return find(walk(A,B,K))==find(walk(B,A,K));
  }
}

int main(){
  int N,K,R;
  scanf("%d %d %d",&N,&K,&R);
  int oldN=N;
  for(int i=0;i<oldN-1;i++){
    int X,Y;
    scanf("%d %d",&X,&Y);
    X--,Y--;
    edges[X].push_back(N);
    edges[N].push_back(X);
    edges[Y].push_back(N);
    edges[N].push_back(Y);
    N++;
  }
  for(int i=0;i<N;i++){
    uf[i]=i;
  }
  std::fill(dist,dist+N,INF);
  std::queue<int> frontier;
  for(int i=0;i<R;i++){
    int X;
    scanf("%d",&X);
    X--;
    dist[X]=0;
    frontier.push(X);
  }
  while(!frontier.empty()){
    int x=frontier.front();
    if(dist[x]>K-1) break;
    frontier.pop();
    for(int y:edges[x]){
      uf[find(y)]=find(x);
      if(dist[y]==INF){
	dist[y]=dist[x]+1;
	frontier.push(y);
      }
    }
  }
  dfs(0);
  int V;
  scanf("%d",&V);
  while(V--){
    if(query(K)){
      printf("YES\n");
    }else{
      printf("NO\n");
    }
  }
}