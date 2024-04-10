#include <cstdio>
#include <vector>
#include <algorithm>

const int BLOCK=300;

std::vector<int> edges[100005];

int pre[100005];
int post[100005];
int euler=0;

void dfs(int node,int parent){
  pre[node]=euler++;
  for(int child:edges[node]){
    if(child==parent) continue;
    dfs(child,node);
  }
  post[node]=euler;
}

struct Query{
  int l,r,k,id;
  Query(int l,int r,int k,int id):l(l),r(r),k(k),id(id){
  }
  bool operator<(struct Query q)const{
    if(q.l/BLOCK!=l/BLOCK) return q.l/BLOCK<l/BLOCK;
    if(q.r!=r) return (q.r<r)^((q.l/BLOCK)&1);
    return q.l<l;
  }
};
std::vector<struct Query> queries;

int cs[100005];
int as[100005];

int freq[100005];
int ft[100005];
int ans[100005];
int N;

void update(int i,int v){
  for(i++;i>0;i-=(i&-i)){
    ft[i]+=v;
  }
}

int query(int i){
  int ans=0;
  for(i++;i<=N+1;i+=(i&-i)){
    ans+=ft[i];
  }
  return ans;
}

void change(int x,int delta){
  update(freq[x],-1);
  freq[x]+=delta;
  update(freq[x],1);
}

int main(){
  int Q;
  scanf("%d %d",&N,&Q);
  for(int i=0;i<N;i++){
    scanf("%d",&cs[i]);
  }
  for(int i=0;i<N-1;i++){
    int A,B;
    scanf("%d %d",&A,&B);
    A--,B--;
    edges[A].push_back(B);
    edges[B].push_back(A);
  }
  dfs(0,0);
  for(int i=0;i<N;i++){
    as[pre[i]]=cs[i];
  }
  for(int i=0;i<Q;i++){
    int V,K;
    scanf("%d %d",&V,&K);
    V--;
    queries.emplace_back(pre[V],post[V],K,i);
  }
  std::sort(queries.begin(),queries.end());
  int l=0,r=0;//[l,r)
  for(auto q:queries){
    while(r<q.r) change(as[r++],1);
    while(l>q.l) change(as[--l],1);
    while(r>q.r) change(as[--r],-1);
    while(l<q.l) change(as[l++],-1);
    ans[q.id]=query(q.k);
  }
  for(int i=0;i<Q;i++){
    printf("%d\n",ans[i]);
  }
  return 0;
}