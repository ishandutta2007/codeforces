#include <cstdio>
#include <algorithm>
#include <cassert>

const int MOD=1e9+7;

int perm[2][400005];
int where[2][400005];

bool vis[400005];

void solve(){
  int N;
  scanf("%d",&N);
  for(int r=0;r<2;r++){
    for(int i=0;i<N;i++){
      scanf("%d",&perm[r][i]);
      perm[r][i]--;
      where[r][perm[r][i]]=i;
    }
  }
  std::fill(vis,vis+N,false);
  int ans=1;
  for(int i=0;i<N;i++){
    if(vis[i]) continue;
    int j=i;
    while(!vis[j]){
      vis[j]=true;
      j=where[1][perm[0][j]];
    }
    assert(j==i);
    ans=ans*2LL%MOD;
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