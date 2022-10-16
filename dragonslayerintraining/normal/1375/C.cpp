#include <cstdio>

int as[300005];

void solve(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  if(as[0]<as[N-1]){
    printf("YES\n");
  }else{
    printf("NO\n");
  }
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}