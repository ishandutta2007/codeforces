#include <cstdio>
#include <vector>
#include <algorithm>

const int MOD=998244353;

int modpow(int base,int exp){
  int ac=1;
  for(;exp;exp>>=1){
    if(exp&1) ac=1LL*ac*base%MOD;
    base=1LL*base*base%MOD;
  }
  return ac;
}

int inverse(int x){
  return modpow(x,MOD-2);
}

std::vector<int> edges[150005];
int size[150005];
int par[150005];
int head[150005];

int pre[150005];
int post[150005];
int euler;
int delta[150005];

long long ft[150005];
int N,Q;

void update(int i,long long v){
  for(i++;i<=N;i+=(i&-i)){
    ft[i]+=v;
  }
}

void update(int a,int b,long long v){
  update(a,v);
  update(b,-v);
}

long long query(int i){
  long long ac=0;
  for(i++;i>0;i-=(i&-i)){
    ac+=ft[i];
  }
  return ac;
}

void dfs_size(int node){
  size[node]=1;
  for(int child:edges[node]){
    edges[child].erase(std::find(edges[child].begin(),edges[child].end(),node));
    par[child]=node;
    dfs_size(child);
    size[node]+=size[child];
  }
}

void dfs_hld(int node){
  pre[node]=euler++;
  for(int& child:edges[node]){
    if(size[child]>size[edges[node][0]]){
      std::swap(child,edges[node][0]);
    }
  }
  for(int child:edges[node]){
    head[child]=(child==edges[node][0])?head[node]:child;
    dfs_hld(child);
  }
  post[node]=euler;
}

int main(){
  scanf("%d %d",&N,&Q);
  int invN=inverse(N);
  for(int i=0;i<N-1;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    edges[U].push_back(V);
    edges[V].push_back(U);
  }
  dfs_size(0);
  dfs_hld(0);
  while(Q--){
    int T;
    scanf("%d",&T);
    if(T==1){
      int V,D;
      scanf("%d %d",&V,&D);
      V--;
      update(0,pre[V],1LL*size[V]*D);
      update(pre[V],post[V],1LL*N*D);
      update(post[V],N,1LL*size[V]*D);
      if(edges[V].size()){
	int U=edges[V][0];
	update(pre[U],post[U],-1LL*size[U]*D);
      }
      delta[V]=(delta[V]+D)%MOD;
    }else{
      int V;
      scanf("%d",&V);
      V--;
      long long ans=query(pre[V])%MOD;
      for(V=head[V];V!=0;V=head[par[V]]){
	ans-=1LL*size[V]*delta[par[V]];
      }
      printf("%lld\n",(ans%MOD*invN%MOD+MOD)%MOD);
    }
    /*
    for(int V=0;V<N;V++){
      printf("%d: %lld/%d=%lld\n",V,(query(pre[V])%MOD*1%MOD+MOD)%MOD,N,(query(pre[V])%MOD*invN%MOD+MOD)%MOD);
    }
    */
  }
  return 0;
}