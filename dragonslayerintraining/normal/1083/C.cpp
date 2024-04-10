#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>

std::vector<int> children[200005];
int depth[200005];
int anc[200005][18];
int pre[200005];
int post[200005];
int euler=0;

void dfs_init(int node){
  pre[node]=euler++;
  for(int k=1;k<18;k++){
    anc[node][k]=anc[anc[node][k-1]][k-1];
  }
  for(int child:children[node]){
    anc[child][0]=node;
    depth[child]=depth[node]+1;
    dfs_init(child);
  }
  post[node]=euler++;
}

int lca(int a,int b){
  if(depth[a]<depth[b]) std::swap(a,b);
  int diff=depth[a]-depth[b];
  for(int k=18-1;k>=0;k--){
    if(diff&(1<<k)){
      a=anc[a][k];
    }
  }
  if(a==b) return a;
  for(int k=18-1;k>=0;k--){
    if(anc[a][k]!=anc[b][k]){
      a=anc[a][k];
      b=anc[b][k];
    }

  }
  return anc[a][0];
}

struct Node{
  int ends[2];
  Node(){
    ends[0]=ends[1]=-1;
  }
  Node(int a,int b){
    ends[0]=a,ends[1]=b;
  }
}st[800005];
int where[200005];
int ps[200005];

struct Node combine(struct Node a,struct Node b){
  if(a.ends[0]==-2) return b;
  if(b.ends[0]==-2) return a;
  if(a.ends[0]==-1||b.ends[0]==-1) return Node();
  int ends[4]={a.ends[0],a.ends[1],b.ends[0],b.ends[1]};
  int shallow=ends[0];
  for(int i=1;i<4;i++){
    if(depth[ends[i]]<depth[shallow]){
      shallow=ends[i];
    }
  }
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      if(i==j||ends[i]==-1||ends[j]==-1) continue;
      if(pre[ends[i]]<=pre[ends[j]]&&post[ends[i]]>=post[ends[j]]){
	ends[i]=-1;
      }
    }
  }
  int out=0;
  for(int i=0;i<4;i++){
    if(ends[i]!=-1){
      ends[out++]=ends[i];
    }
  }
  if(out==1){
    return Node(shallow,ends[0]);
  }else if(out==2&&depth[lca(ends[0],ends[1])]<=depth[shallow]){
    return Node(ends[0],ends[1]);
  }else{
    return Node();
  }
}

void pull(int w,int L,int R){
  st[w]=combine(st[w<<1],st[w<<1|1]);
}

void build(int w,int L,int R){
  if(R-L==1){
    st[w].ends[0]=ps[L];
    st[w].ends[1]=ps[L];
  }else{
    int M=(L+R)/2;
    build(w<<1,L,M);
    build(w<<1|1,M,R);
    pull(w,L,R);
  }
}

int query(int w,int L,int R,struct Node prefix){
  if(R-L==1){
    if(combine(prefix,st[w]).ends[0]==-1){
      return L;
    }else{
      return R;
    }
  }else{
    int M=(L+R)/2;
    struct Node tmp=combine(prefix,st[w<<1]);
    if(tmp.ends[0]==-1){
      return query(w<<1,L,M,prefix);
    }else{
      return query(w<<1|1,M,R,tmp);
    }
  }
}

void update(int w,int L,int R,int i,int v){
  if(i<L||i>=R) return;
  if(R-L==1){
    st[w]=Node(v,v);
  }else{
    int M=(L+R)/2;
    update(w<<1,L,M,i,v);
    update(w<<1|1,M,R,i,v);
    pull(w,L,R);
  }
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&where[i]);
    ps[where[i]]=i;
  }
  for(int i=1;i<N;i++){
    int P;
    scanf("%d",&P);
    P--;
    children[P].push_back(i);
  }
  dfs_init(0);
  build(1,0,N);
  int Q;
  scanf("%d",&Q);
  while(Q-->0){
    int T;
    scanf("%d",&T);
    if(T==1){
      int I,J;
      scanf("%d %d",&I,&J);
      I--,J--;
      std::swap(where[I],where[J]);
      std::swap(ps[where[I]],ps[where[J]]);
      update(1,0,N,where[I],I);
      update(1,0,N,where[J],J);
    }else if(T==2){
      printf("%d\n",query(1,0,N,Node(-2,-2)));
      /*
      struct Node curr(-2,-2);
      for(int i=0;i<=N;i++){
	if(i==N){
	  printf("%d\n",N+1);
	  break;
	}
	curr=combine(curr,Node(ps[i],ps[i]));

	printf("%d: (%d,%d)\n",i,curr.ends[0],curr.ends[1]);
	if(curr.ends[0]==-1){
	  printf("%d\n",i);
	  break;
	}
      }
      */
    }else{
      assert(0);
    }
  }
  return 0;
}