#include <cstdio>
#include <stdint.h>
#include <vector>

const int64_t MOD=998244353;

std::vector<int> children[200005];
int64_t dp[200005][2];

void dfs(int node){
  if(children[node].empty()){
    dp[node][0]=dp[node][1]=1;
    return;
  }
  int64_t cnt[3]={1,0,0};
  for(int child:children[node]){
    dfs(child);
    cnt[2]=(cnt[2]*(dp[child][0]+dp[child][1])+cnt[1]*dp[child][1])%MOD;
    cnt[1]=(cnt[1]*dp[child][0]+cnt[0]*dp[child][1])%MOD;
    cnt[0]=(cnt[0]*dp[child][0])%MOD;
  }
  dp[node][0]=(cnt[0]+cnt[2])%MOD;
  dp[node][1]=(cnt[1]+cnt[2])%MOD;
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=1;i<N;i++){
    int P;
    scanf("%d",&P);
    children[P-1].push_back(i);
  }
  dfs(0);
  printf("%I64d\n",dp[0][0]);
  return 0;
}