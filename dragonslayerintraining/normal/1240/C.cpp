#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

std::vector<std::vector<std::pair<int,int> > > edges;

//0 if root not saturated (<k edges)
//1 if root may be saturated (<=k edges)
long long dp[500005][2];
int N,K;

void dfs(int node,int parent){
  long long base=0;
  std::vector<long long> boost;
  for(auto e:edges[node]){
    int child=e.first;
    if(child==parent) continue;
    dfs(child,node);
    base+=dp[child][1];
    if(dp[child][0]+e.second>dp[child][1]){
      boost.push_back(dp[child][0]+e.second-dp[child][1]);
    }
  }
  std::sort(boost.begin(),boost.end(),std::greater<long long>());
  dp[node][0]=base+std::accumulate(boost.begin(),boost.begin()+std::min<int>(boost.size(),K-1),0LL);
  dp[node][1]=base+std::accumulate(boost.begin(),boost.begin()+std::min<int>(boost.size(),K),0LL);
}

void solve(){
  scanf("%d %d",&N,&K);
  edges.clear();
  edges.resize(N);
  for(int i=0;i<N-1;i++){
    int U,V,W;
    scanf("%d %d %d",&U,&V,&W);
    U--,V--;
    edges[U].push_back({V,W});
    edges[V].push_back({U,W});
  }
  dfs(0,0);
  printf("%I64d\n",dp[0][1]);
}

int main(){
  int Q;
  scanf("%d",&Q);
  while(Q--){
    solve();
  }
}