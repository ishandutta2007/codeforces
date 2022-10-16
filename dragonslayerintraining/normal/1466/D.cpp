#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

void solve(){
  int N;
  scanf("%d",&N);
  std::vector<int> ws(N);
  for(int i=0;i<N;i++){
    scanf("%d",&ws[i]);
  }
  std::vector<std::vector<int> > adj(N);
  for(int i=0;i<N-1;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    adj[U].push_back(V);
    adj[V].push_back(U);
  }
  long long score=0;
  std::vector<int> add;
  for(int i=0;i<N;i++){
    score+=ws[i];
    for(int d=1;d<adj[i].size();d++){
      add.push_back(ws[i]);
    }
  }
  std::sort(add.begin(),add.end(),std::greater<int>());
  printf("%lld",score);
  for(int i=0;i<N-2;i++){
    score+=add[i];
    printf(" %lld",score);
  }
  printf("\n");
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}