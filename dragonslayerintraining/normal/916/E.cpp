#include <cstdio>
#include <vector>
#include <cassert>
#include <stdint.h>

int anc[100005][17];
int depth[100005];
std::vector<int> edges[100005];
int pre[100005];
int post[100005];
int euler=0;
int N;

void dfs_init(int node){
  pre[node]=euler++;
  for(int child:edges[node]){
    if(child==anc[node][0]) continue;
    depth[child]=depth[node]+1;
    anc[child][0]=node;
    for(int k=1;k<17;k++){
      anc[child][k]=anc[anc[child][k-1]][k-1];
    }
    dfs_init(child);
  }
  post[node]=euler;
}

int la(int a,int d){
  for(int k=17-1;k>=0;k--){
    if(d&(1<<k)){
      a=anc[a][k];
    }
  }
  return a;
}

int lca(int a,int b){
  if(depth[a]<depth[b]) std::swap(a,b);
  a=la(a,depth[a]-depth[b]);
  if(a==b) return a;
  for(int k=17-1;k>=0;k--){
    if(anc[a][k]!=anc[b][k]){
      a=anc[a][k];
      b=anc[b][k];
    }
  }
  return anc[a][0];
}

int next(int a,int b){
  assert(a!=b);
  if(depth[a]>=depth[b]||la(b,depth[b]-depth[a])!=a){
    return anc[a][0];
  }else{
    return la(b,depth[b]-depth[a]-1);
  }
}

int64_t st[400005];
int64_t lazy[400005];

void push(int w,int L,int R){
  if(R-L>1){
    lazy[w<<1]+=lazy[w];
    lazy[w<<1|1]+=lazy[w];
  }
  st[w]+=lazy[w]*(R-L);
  lazy[w]=0;
}

void pull(int w,int L,int R){
  st[w]=st[w<<1]+st[w<<1|1];
}

void update(int w,int L,int R,int a,int b,int64_t v){
  push(w,L,R);
  if(b<=L||a>=R) return;
  if(a<=L&&b>=R){
    lazy[w]+=v;
    push(w,L,R);
  }else{
    int M=(L+R)/2;
    update(w<<1,L,M,a,b,v);
    update(w<<1|1,M,R,a,b,v);
    pull(w,L,R);
  }
}
void update(int u,int64_t v){
  update(1,0,N,pre[u],post[u],v);
}

int64_t query(int w,int L,int R,int a,int b){
  push(w,L,R);
  if(b<=L||a>=R) return 0;
  if(a<=L&&b>=R){
    return st[w];
  }else{
    int M=(L+R)/2;
    return query(w<<1,L,M,a,b)+query(w<<1|1,M,R,a,b);
  }
}
int64_t query(int u){
  return query(1,0,N,pre[u],post[u]);
}

int as[100005];

int main(){
  int Q;
  scanf("%d %d",&N,&Q);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  for(int i=0;i<N-1;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    edges[U].push_back(V);
    edges[V].push_back(U);
  }
  dfs_init(0);
  for(int i=0;i<N;i++){
    update(1,0,N,pre[i],pre[i]+1,as[i]);
  }
  int root=0;
  while(Q--){
    int T;
    scanf("%d",&T);
    if(T==1){
      scanf("%d",&root);
      root--;
    }else if(T==2){
      int U,V,X;
      scanf("%d %d %d",&U,&V,&X);
      U--,V--;
      int S=lca(root,U)^lca(root,V)^lca(U,V);
      if(S==root){
	update(0,X);
      }else{
	int T=next(S,root);
	if(T==anc[S][0]){
	  update(S,X);
	}else{
	  update(0,X);
	  update(T,-X);
	}
      }
    }else{
      int S;
      scanf("%d",&S);
      S--;
      int64_t ans;
      if(S==root){
	ans=query(0);
      }else{
	int T=next(S,root);
	if(T==anc[S][0]){
	  ans=query(S);
	}else{
	  ans=query(0)-query(T);
	}
      }
      printf("%I64d\n",ans);
    }
  }
  return 0;
}