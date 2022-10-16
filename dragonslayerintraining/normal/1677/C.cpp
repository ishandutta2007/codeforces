#include <cstdio>
#include <algorithm>

int as[100005];
int br[100005];
bool vis[100005];

void solve(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    as[i]=A-1;
  }
  for(int i=0;i<N;i++){
    int B;
    scanf("%d",&B);
    br[B-1]=i;
  }
  std::fill(vis,vis+N,false);
  int K=0;
  for(int i=0;i<N;i++){
    if(vis[i]) continue;
    int len=1;
    vis[i]=true;
    for(int j=br[as[i]];j!=i;j=br[as[j]]){
      vis[j]=true;
      len++;
    }
    K+=len/2;
  }
  printf("%lld\n",2LL*K*(N-K));
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}