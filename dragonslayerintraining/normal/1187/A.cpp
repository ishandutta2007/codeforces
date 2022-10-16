#include <cstdio>
#include <algorithm>

void solve(){
  int N,S,T;
  scanf("%d %d %d",&N,&S,&T);
  printf("%d\n",std::max(N-S+1,N-T+1));
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
  return 0;
}