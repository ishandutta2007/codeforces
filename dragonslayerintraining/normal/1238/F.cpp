#include <cstdio>
#include <vector>
#include <functional>
#include <algorithm>

const int INF=1e9+7;

std::vector<std::vector<int> > edges;

int dp[300005];
int best;

void dfs(int node,int parent){
  std::vector<int> sub({0,0});
  for(int child:edges[node]){
    if(child==parent) continue;
    dfs(child,node);
    sub.push_back(dp[child]);
  }
  std::sort(sub.begin(),sub.end(),std::greater<int>());
  dp[node]=sub[0]+edges[node].size()-1;
  //printf("dp[%d]=%d\n",node+1,dp[node]);
  best=std::max(best,dp[node]+sub[1]);
}

void solve(){
  int N;
  scanf("%d",&N);
  edges.clear();
  edges.resize(N);
  for(int i=0;i<N-1;i++){
    int X,Y;
    scanf("%d %d",&X,&Y);
    X--,Y--;
    edges[X].push_back(Y);
    edges[Y].push_back(X);
  }
  best=-INF;
  dfs(0,0);
  printf("%d\n",best+2);
}

int main(){
  int Q;
  scanf("%d",&Q);
  while(Q--){
    solve();
  }
}