#include <cstdio>
#include <algorithm>
#include <numeric>

int uf[100005];

int find(int a){
  return (a==uf[a])?a:(uf[a]=find(uf[a]));
}

void solve(){
  int N,M;
  scanf("%d %d",&N,&M);
  std::iota(uf,uf+N,0);
  int cnt=0;
  for(int i=0;i<M;i++){
    int X,Y;
    scanf("%d %d",&X,&Y);
    X--,Y--;
    if(X==Y) continue;
    cnt++;
    if(find(X)==find(Y)){
      cnt++;
    }
    uf[find(X)]=find(Y);
  }
  printf("%d\n",cnt);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}