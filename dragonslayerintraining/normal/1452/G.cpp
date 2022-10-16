#include <cstdio>
#include <queue>

std::vector<int> adj[200005];
int dist[200005];

int size[200005];
bool dead[200005];

int ans[200005];

void dfs_size(int x,int par){
  size[x]=1;
  for(int y:adj[x]){
    if(y==par||dead[y]) continue;
    dfs_size(y,x);
    size[x]+=size[y];
  }
}

int find_centroid(int x,int par,int total_size){
  for(int y:adj[x]){
    if(y==par||dead[y]) continue;
    if(size[y]*2>total_size){
      return find_centroid(y,x,total_size);
    }
  }
  return x;
}

int survive[200005];
int total_size;

void dfs1(int x,int par,int depth,int late){
  late=std::min(late,dist[x]-depth-1);
  if(late<0) return;
  int& ref=survive[late];
  ref=std::max(ref,dist[x]);
  for(int y:adj[x]){
    if(y==par||dead[y]) continue;
    dfs1(y,x,depth+1,late);
  }
}

void dfs2(int x,int par,int depth,int deep){
  deep=std::min(deep,dist[x]+depth-1);
  if(depth>deep) return;
  //fprintf(stderr,"%d can achieve %d\n",x+1,survive[depth]);
  ans[x]=std::max(ans[x],survive[depth]);
  for(int y:adj[x]){
    if(y==par||dead[y]) continue;
    dfs2(y,x,depth+1,deep);
  }
}

void dfs_solve(int x){
  dfs_size(x,-1);
  total_size=size[x];
  std::fill(survive,survive+total_size,0);
  x=find_centroid(x,-1,size[x]);
  //fprintf(stderr,"centroid: %d\n",x+1);
  dfs1(x,-1,0,total_size-1);
  for(int i=total_size-2;i>=0;i--){
    survive[i]=std::max(survive[i],survive[i+1]);
  }
  /*
  for(int i=0;i<total_size;i++){
    fprintf(stderr,"survive[%d]=%d\n",i,survive[i]);
  }
  */
  dfs2(x,-1,0,total_size-1);
  dead[x]=true;
  for(int y:adj[x]){
    if(dead[y]) continue;
    dfs_solve(y);
  }
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N-1;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    adj[U].push_back(V);
    adj[V].push_back(U);
  }
  std::fill(dist,dist+N,-1);
  std::queue<int> q;
  int K;
  scanf("%d",&K);
  while(K--){
    int A;
    scanf("%d",&A);
    A--;
    dist[A]=0;
    q.push(A);
  }
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
  /*
  for(int i=0;i<N;i++){
    fprintf(stderr,"dist[%d]=%d\n",i+1,dist[i]);
  }
  */
  dfs_solve(0);
  for(int i=0;i<N;i++){
    printf("%d\n",ans[i]);
  }
}