#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <stdint.h>
#include <cassert>

const int64_t MOD=1e9+7;

int64_t modpow(int64_t base,int64_t exp){
  int64_t ac=1;
  for(;exp>0;exp>>=1){
    if(exp&1) ac=1LL*ac*base%MOD;
    base=1LL*base*base%MOD;
  }
  return ac;
}
/*
int64_t inverse(int64_t x){
  return modpow(x,MOD-2);
}
*/
std::vector<int64_t> edges[100005];
int64_t depth[100005];
int64_t anc[17][100005];
int64_t pre[100005];
int64_t post[100005];
int64_t who[200005];
int64_t euler=0;

void dfs_init(int64_t node,int64_t parent){
  anc[0][node]=parent;
  for(int64_t k=1;k<17;k++){
    anc[k][node]=anc[k-1][anc[k-1][node]];
  }
  who[euler]=node;
  pre[node]=euler++;
  for(int64_t child:edges[node]){
    if(child==parent) continue;
    depth[child]=depth[node]+1;
    dfs_init(child,node);
  }
  who[euler]=node;
  post[node]=euler++;
}

int64_t lca(int64_t a,int64_t b){
  if(depth[a]<depth[b]) std::swap(a,b);
  int64_t diff=depth[a]-depth[b];
  for(int64_t k=17-1;k>=0;k--){
    if(diff&(1<<k)){
      a=anc[k][a];
    }
  }
  if(a==b) return a;
  for(int64_t k=17-1;k>=0;k--){
    if(anc[k][a]!=anc[k][b]){
      a=anc[k][a];
      b=anc[k][b];
    }
  }
  return anc[0][a];
}

int64_t as[100005];
int64_t bs[100005];

int64_t freq[100005];

int64_t fs[100005];

void dfs_induced(int64_t node,int64_t parent,int64_t level,const std::vector<std::vector<int64_t> >& adj,const std::vector<int64_t>& marked){
  /*
    if(marked[node]) print64_tf("*");
    printf("Enter %I64d\n",node);
  */
  if(marked[node]) freq[level++]++;
  for(int64_t child:adj[node]){
    if(child==parent) continue;
    dfs_induced(child,node,level,adj,marked);
  }
  /*
    if(marked[node]) print64_tf("*");
    printf("Exit %I64d\n",node);
  */
}

int64_t factorial[200005]={1};
int64_t inverse[200005]={0,1};
int64_t inverse_factorial[200005]={0,1};

int solve1(int M,int K){
  /*
    for(int64_t i=0;i<K;i++){
    printf("freq[%I64d]=%I64d\n",i,freq[i]);
    }
  */
  int64_t last=-1;
  for(int64_t i=0;i<K;i++){
    if(freq[i]){
      last=i;
    }
  }
  for(int64_t i=0;i<=M;i++){
    if(i<=last){
      fs[i]=0;
      continue;
    }
    fs[i]=1;
    for(int64_t k=0;k<i;k++){
      fs[i]=1LL*fs[i]*modpow(i-k,freq[k])%MOD;
    }
  }
  /*
    for(int64_t i=0;i<=M;i++){
    printf("fs[%I64d]=%I64d\n",i,fs[i]);
    }
  */
  int64_t ans=0;
  //divide into exactly j groups
  for(int64_t j=std::max<int64_t>(0,last);j<=M;j++){
    int64_t tmp=0;
    for(int64_t i=0;i<=j;i++){
      tmp=(fs[i]+1LL*(MOD-i)*inverse[j+1-i]%MOD*tmp)%MOD;
    }
    //printf("%I64d groups: %I64d\n",j,tmp);
    ans=(ans+1LL*tmp*inverse_factorial[j])%MOD;
  }
  return ans;
}

int dp[305];

int solve2(int M,int K){
  for(int i=0;i<=M;i++){
    dp[i]=0;
  }
  dp[0]=1;
  for(int i=0;i<K;i++){
    for(int j=0;j<freq[i];j++){
      //printf("add %d: ",i);
      for(int k=M;k>0;k--){
	dp[k]=(1LL*dp[k]*std::max(0,k-i)+dp[k-1])%MOD;
      }
      dp[0]=0;
      /*
      for(int k=0;k<=M;k++){
	printf("dp[%d]=%d\n",k,dp[k]);
      }
      */
    }
  }
  int ans=0;
  for(int i=0;i<=M;i++){
    ans=(ans+dp[i])%MOD;
  }
  return ans;
}

int main(){
  for(int64_t i=1;i<=200000;i++){
    factorial[i]=1LL*factorial[i-1]*i%MOD;
  }
  for(int64_t i=2;i<=200000;i++){
    inverse[i]=1LL*(MOD-MOD/i)*inverse[MOD%i]%MOD;
    inverse_factorial[i]=1LL*inverse_factorial[i-1]*inverse[i]%MOD;
  }
  int64_t N,Q;
  scanf("%I64d %I64d",&N,&Q);
  for(int64_t i=0;i<N-1;i++){
    int64_t U,V;
    scanf("%I64d %I64d",&U,&V);
    U--,V--;
    edges[U].push_back(V);
    edges[V].push_back(U);
  }
  dfs_init(0,0);
  while(Q-->0){
    int64_t K,M,R;
    scanf("%I64d %I64d %I64d",&K,&M,&R);
    R--;
    for(int64_t i=0;i<K;i++){
      scanf("%I64d",&as[i]);
      as[i]--;
    }
    std::copy(as,as+K,bs);
    bs[K]=R;
    std::sort(bs,bs+K+1,[](int64_t i,int64_t j){return pre[i]<pre[j];});
    std::map<int64_t,int64_t> induced;
    for(int64_t i=0;i<=K;i++){
      induced[bs[i]];
    }
    for(int64_t i=0;i<K;i++){
      induced[lca(bs[i],bs[i+1])];
    }
    int64_t id=0;
    for(auto& it:induced){
      it.second=id++;
    }
    std::vector<int64_t> events;
    for(auto it:induced){
      events.push_back(pre[it.first]);
      events.push_back(post[it.first]);
    }
    std::sort(events.begin(),events.end());
    std::vector<std::vector<int64_t> > adj(induced.size());
    std::vector<int64_t> mark(induced.size());
    std::vector<int64_t> stk;
    for(int64_t i:events){
      if(stk.size()&&stk.back()==who[i]){
	stk.pop_back();
      }else{
	if(stk.size()){
	  int64_t x=induced[stk.back()],y=induced[who[i]];
	  adj[x].push_back(y);
	  adj[y].push_back(x);
	}
	stk.push_back(who[i]);
      }
    }
    for(int64_t i=0;i<K;i++){
      mark[induced[as[i]]]=1;
    }
    std::fill(freq,freq+K,0);
    dfs_induced(induced[R],-1,0,adj,mark);
    int ans1=solve1(M,K);
    int ans2=solve2(M,K);
    //printf("%d vs %d\n",ans1,ans2);
    assert(ans1==ans2);
    printf("%d\n",ans2);
  }
  return 0;
}