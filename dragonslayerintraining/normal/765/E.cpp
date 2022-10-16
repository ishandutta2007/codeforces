#include <cstdio>
#include <vector>
#include <queue>
#include <set>

std::vector<int> edges[200005];
int tree[200005];
int deg[200005];
int len[200005];
int id[200005];
int ext[200005];
std::set<int> hang[200005];
int M;

void add_edge(int x,int y,int l){
  deg[x]++,tree[x]^=y,len[x]^=l;
  deg[y]++,tree[y]^=x,len[y]^=l;
}

void dfs_compress(int node,int parent){
  if(parent==-1){
    id[node]=M++;
  }else{
    id[node]=-1;
  }
  for(int child:edges[node]){
    if(child==parent) continue;
    dfs_compress(child,node);
    if(id[node]==-1){
      id[node]=id[child];
      ext[node]=ext[child]+1;
    }else{
      if(ext[node]){
	add_edge(id[node],M,ext[node]);
	id[node]=M++;
	ext[node]=0;
      }
      add_edge(id[child],id[node],ext[child]+1);
    }
  }
  if(id[node]==-1){
    id[node]=M++;
  }
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N-1;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    edges[U].push_back(V);
    edges[V].push_back(U);
  }
  for(int i=0;i<N;i++){
    if(edges[i].size()==1){
      dfs_compress(i,-1);
      break;
    }
  }
  std::priority_queue<std::pair<int,int> > leaves;
  for(int i=0;i<M;i++){
    //printf("%d: deg=%d, tree=%d, len=%d\n",i,deg[i],tree[i],len[i]);
    if(deg[i]==1){
      leaves.emplace(-len[i],i);
    }
  }
  while(!leaves.empty()){
    int node=leaves.top().second;
    int L=-leaves.top().first;
    leaves.pop();
    int other=tree[node];
    //printf("hang %d off %d\n",L,other);
    //delete edge
    tree[other]^=node;
    len[other]^=len[node];
    deg[other]--;
    hang[other].insert(L);
    if(deg[other]==0&&hang[other].size()<=2){
      int ans=0;
      for(int l:hang[other]){
	ans+=l;
      }
      while(ans%2==0) ans/=2;
      printf("%d\n",ans);
      return 0;
    }
    if(hang[other].size()==1&&deg[other]==1){
      leaves.emplace(-len[other]-*hang[other].begin(),other);
      //printf("release %d\n",other);
    }
  }
  printf("-1\n");
  return 0;
}