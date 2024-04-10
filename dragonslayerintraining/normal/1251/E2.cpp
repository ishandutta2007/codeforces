#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

void solve(){
  int N;
  scanf("%d",&N);
  std::vector<std::pair<int,int> > voters;
  for(int i=0;i<N;i++){
    int M,P;
    scanf("%d %d",&M,&P);
    voters.push_back({M,P});
  }
  std::sort(voters.begin(),voters.end());
  int boost=0;
  long long cost=0;
  std::multiset<int> pool;
  for(int i=N-1;i>=0;i--){
    int M=voters[i].first,P=voters[i].second;
    pool.insert(P);
    while(i+boost<M){
      cost+=*pool.begin();
      boost++;
      pool.erase(pool.begin());
    }
  }
  printf("%I64d\n",cost);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}