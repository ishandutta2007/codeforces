#include <cstdio>
#include <algorithm>

int as[200005];

void solve(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  for(int i=1;i<N;i++){
    int diff=std::labs(as[i]-as[i-1]);
    if(diff>=2){
      printf("YES\n");
      printf("%d %d\n",i,i+1);
      return;
    }
  }
  printf("NO\n");
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}