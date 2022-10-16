#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

long long cs[500005];

long long gcd(long long a,long long b){
  return b?gcd(b,a%b):a;
}

void solve(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    scanf("%lld",&cs[i]);
  }
  std::vector<std::vector<int> > adj(N);
  for(int i=0;i<M;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    adj[V-1].push_back(U-1);
  }
  std::map<std::vector<int>,long long> sums;
  for(int i=0;i<N;i++){
    std::sort(adj[i].begin(),adj[i].end());
    sums[adj[i]]+=cs[i];
  }
  long long G=0;
  for(auto it:sums){
    if(it.first.empty()) continue;
    G=gcd(G,it.second);
  }
  printf("%lld\n",G);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}