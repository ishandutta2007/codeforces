#include <cstdio>
#include <algorithm>

void solve(){
  int N;
  scanf("%d",&N);
  int ans=0;
  for(;N>0;N/=10){
    ans=std::max(ans,N%10);
  }
  printf("%d\n",ans);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}