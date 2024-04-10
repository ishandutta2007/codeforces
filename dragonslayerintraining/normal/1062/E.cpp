#include <cstdio>
#include <vector>
#include <algorithm>

const int INF=1e9+7;

std::vector<int> children[100005];
int depth[100005];
int anc[100005][17];
int pre[100005];
int post[100005];
int euler=0;
int who[200005];
int N;

void dfs_init(int node){
  who[euler]=node;
  pre[node]=euler++;
  for(int k=1;k<17;k++){
    anc[node][k]=anc[anc[node][k-1]][k-1];
  }
  for(int child:children[node]){
    anc[child][0]=node;
    depth[child]=depth[node]+1;
    dfs_init(child);
  }
  who[euler]=node;
  post[node]=euler++;
}

int lca(int a,int b){
  if(depth[a]<depth[b]) std::swap(a,b);
  int diff=depth[a]-depth[b];
  for(int k=17-1;k>=0;k--){
    if(diff&(1<<k)){
      a=anc[a][k];
    }
  }
  if(a==b) return a;
  for(int k=17-1;k>=0;k--){
    if(anc[a][k]!=anc[b][k]){
      a=anc[a][k],b=anc[b][k];
    }
  }
  return anc[a][0];
}

struct Node{
  int min[2],max[2];
  Node(){
    min[0]=min[1]=INF;
    max[0]=max[1]=-INF;
  }
}st[200005];

struct Node combine(struct Node a,struct Node b){
  int min[4]={a.min[0],a.min[1],b.min[0],b.min[1]};
  int max[4]={a.max[0],a.max[1],b.max[0],b.max[1]};
  std::sort(min,min+4);
  std::sort(max,max+4);
  struct Node res;
  res.min[0]=min[0];
  res.min[1]=min[1];
  res.max[0]=max[3];
  res.max[1]=max[2];
  return res;
}

void pull(int i){
  st[i]=combine(st[i<<1],st[i<<1|1]);
}

void build(){
  for(int i=N-1;i>0;i--){
    pull(i);
  }
}

struct Node query(int a,int b){
  struct Node res;
  for(a+=N,b+=N;a<b;a>>=1,b>>=1){
    if(a&1) res=combine(res,st[a++]);
    if(b&1) res=combine(res,st[--b]);
  }
  return res;
}

int main(){
  int Q;
  scanf("%d %d",&N,&Q);
  for(int i=1;i<N;i++){
    int P;
    scanf("%d",&P);
    P--;
    children[P].push_back(i);
  }
  dfs_init(0);
  for(int i=0;i<N;i++){
    st[i+N].min[0]=pre[i];
    st[i+N].max[0]=post[i];
  }
  build();
  while(Q-->0){
    int L,R;
    scanf("%d %d",&L,&R);
    L--;
    struct Node q=query(L,R);
    if(who[q.min[0]]==who[q.max[0]]){
      printf("%d %d\n",who[q.min[0]]+1,depth[lca(who[q.min[1]],who[q.max[1]])]);
    }else{
      int l1=lca(who[q.min[0]],who[q.max[1]]);
      int l2=lca(who[q.min[1]],who[q.max[0]]);    
      if(depth[l1]<depth[l2]){
	printf("%d %d\n",who[q.min[0]]+1,depth[l2]);
      }else{
	printf("%d %d\n",who[q.max[0]]+1,depth[l1]);
      }
    }
  }
  return 0;
}