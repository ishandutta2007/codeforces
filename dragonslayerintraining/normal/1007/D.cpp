#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>

const int INF=1e9+7;

void fail(){
  printf("NO\n");
  exit(0);
}

struct TwoSAT{
  std::vector<std::vector<int> > edges;
  std::vector<bool> val;
  std::vector<int> low,pre;
  int pre_max;
  int reserve(){
    int id=edges.size();
    edges.emplace_back();
    edges.emplace_back();
    return id;
  }
  void imply(int a,int b){
    edges[a].push_back(b);
    edges[b^1].push_back(a^1);
  }
  std::vector<int> stk;
  void dfs_2sat(int node){
    assert(!pre[node]);
    low[node]=pre[node]=++pre_max;
    stk.push_back(node);
    for(int child:edges[node]){
      if(!pre[child]){
	dfs_2sat(child);
      }
      low[node]=std::min(low[node],low[child]);
    }
    if(low[node]==pre[node]){
      int start=stk.size()-1;
      while(stk[start]!=node) start--;
      bool mark=!val[node^1];
      //printf("SCC:");
      for(int i=start;i<stk.size();i++){
	//printf(" %d",stk[i]);
	if(mark){
	  val[stk[i]]=true;
	  if(val[stk[i]^1]){
	    fail();
	  }
	}
	low[stk[i]]=INF;
      }
      //printf("\n");
      stk.resize(start);
    }
  }
  void solve(){
    std::vector<bool>(edges.size()).swap(val);
    std::vector<int>(edges.size()).swap(low);
    std::vector<int>(edges.size()).swap(pre);
    pre_max=0;
    for(int i=0;i<edges.size();i++){
      if(!pre[i]){
	dfs_2sat(i);
      }
    }
  }
}twosat;

std::vector<int> edges[100001];

std::vector<int> parent,size,head,pre,post,who;
int pre_max=0;

void dfs_size(int node){
  if(parent[node]>=0) edges[node].erase(std::remove(edges[node].begin(),edges[node].end(),parent[node]),edges[node].end());
  size[node]=1;
  for(int& child:edges[node]){
    parent[child]=node;
    dfs_size(child);
    size[node]+=size[child];
    if(size[child]>size[edges[node][0]]){
      std::swap(child,edges[node][0]);
    }
  }
}

void dfs_hld(int node){
  pre[node]=pre_max++;
  who[pre[node]]=node;
  for(int child:edges[node]){
    head[child]=(child==edges[node][0])?head[node]:child;
    dfs_hld(child);
  }
  post[node]=pre_max;
}

struct Segtree{
  int forbid;
  int last;
  int next,prev;
};

std::vector<struct Segtree> st;
int N;

void st_build(){
  for(int i=1;i<N*2;i++){
    st[i].forbid=twosat.reserve();
    st[i].last=twosat.reserve();
    st[i].next=twosat.reserve();
    st[i].prev=twosat.reserve();
  }
  for(int i=1;i<N;i++){
    twosat.imply(st[i].forbid,st[i<<1].forbid);
    twosat.imply(st[i].forbid,st[i<<1|1].forbid);
  }
}

void st_add_at(int a,int x){
  twosat.imply(st[a].forbid,x^1);
  if(a<N){
    twosat.imply(x,st[a<<1].forbid);
    twosat.imply(x,st[a<<1|1].forbid);
  }
  int new_prev=twosat.reserve();
  int new_next=twosat.reserve();
  twosat.imply(new_prev,x^1);
  twosat.imply(new_next,x^1);
  twosat.imply(new_prev,st[a].prev);
  twosat.imply(st[a].next,new_next);
  twosat.imply(x,st[a].prev);
  twosat.imply(st[a].last,new_next);
  st[a].prev=new_prev;
  st[a].next=new_next;
}

void st_add(int a,int b,int x){
  /*
  for(int i=a;i<b;i++){
    printf("ADD %d\n",who[i]+1);
  }
  */
  for(a+=N,b+=N;a<b;a>>=1,b>>=1){
    if(a&1) st_add_at(a++,x);
    if(b&1) st_add_at(--b,x);
  }
}

void add_path(int a,int b,int x){
  if(pre[a]>pre[b]) std::swap(a,b);
  while(pre[head[a]]<pre[head[b]]){
    st_add(pre[head[b]],pre[b]+1,x);
    b=parent[head[b]];
  }
  while(pre[head[a]]>pre[head[b]]){
    st_add(pre[head[a]],pre[a]+1,x);
    a=parent[head[a]];
  }
  assert(head[a]==head[b]);
  if(pre[a]>pre[b]) std::swap(a,b);
  //printf("LCA=%d\n",a);
  st_add(pre[a]+1,pre[b]+1,x);//exclude LCA,right bound exclusive
}

int main(){
  scanf("%d",&N);
  std::vector<int> ants(N*2);
  for(int i=0;i<ants.size();i++){
    ants[i]=twosat.reserve();
  }
  for(int i=0;i<N-1;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    edges[U].push_back(V);
    edges[V].push_back(U);
  }
  parent.resize(N);
  size.resize(N);
  head.resize(N);
  pre.resize(N);
  post.resize(N);
  who.resize(N);

  parent[0]=-1;
  
  dfs_size(0);
  dfs_hld(0);
  // for(int i=0;i<N;i++) printf("size[%d]=%d\n",i,size[i]);
  // for(int i=0;i<N;i++) printf("head[%d]=%d\n",i,head[i]);
  // for(int i=0;i<N;i++) printf("pre[%d]=%d\n",i,pre[i]);
  // for(int i=0;i<N;i++) printf("post[%d]=%d\n",i,post[i]);

  st.resize(N*2);
  st_build();
  
  int M;
  scanf("%d",&M);
  for(int i=0;i<M*2;i++){
    int A,B;
    scanf("%d %d",&A,&B);
    A--,B--;
    add_path(A,B,i);
  }
  twosat.solve();
  printf("YES\n");
  for(int i=0;i<M;i++){
    //printf("2sat[%d]=%d,%d\n",i,(int)twosat.val[i<<1],(int)twosat.val[i<<1|1]);
    assert(twosat.val[ants[i]]^twosat.val[ants[i]^1]);
    if(twosat.val[ants[i]]){
      printf("1\n");
    }else{
      printf("2\n");
    }
  }
  return 0;
}