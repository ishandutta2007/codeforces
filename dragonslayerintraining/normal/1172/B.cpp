#include <cstdio>
#include <vector>
#include <algorithm>

const int MOD=998244353;

int N;
std::vector<int> edges[200005];
int dp[200005];

int fact[200005]={1};

void modmul(int& x,int y){
  x=1LL*x*y%MOD;
}

void dfs(int node){
  dp[node]=1;
  for(int child:edges[node]){
    edges[child].erase(std::find(edges[child].begin(),edges[child].end(),node));
    dfs(child);
    modmul(dp[node],dp[child]);
  }
  if(node){
    modmul(dp[node],fact[edges[node].size()+1]);
  }else{
    modmul(dp[node],fact[edges[node].size()]);
    modmul(dp[node],N);
  }
}

int main(){
  scanf("%d",&N);
  for(int i=1;i<=N;i++){
    fact[i]=1LL*i*fact[i-1]%MOD;
  }
  for(int i=0;i<N-1;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    edges[U].push_back(V);
    edges[V].push_back(U);
  }
  dfs(0);
  printf("%d\n",dp[0]);
  return 0;
}