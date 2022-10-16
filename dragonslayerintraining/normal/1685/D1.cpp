#include <cstdio>
#include <algorithm>

int ps[205];
int rs[205];

bool vis[205];

void solve(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&ps[i]);
    ps[i]--;
    rs[ps[i]]=i;
  }
  while(true){
    std::fill(vis,vis+N,false);
    for(int i=0;!vis[i];i=rs[i]){
      vis[i]=true;
    }
    int i=std::find(vis,vis+N,false)-vis;
    if(i==N) break;
    std::swap(rs[i-1],rs[i]);
  }
  printf("1");
  for(int i=rs[0];i!=0;i=rs[i]){
    printf(" %d",i+1);
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