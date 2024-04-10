#include <cstdio>
#include <algorithm>

int as[200005];

void solve(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    as[i]=((i+A)%N+N)%N;
  }
  std::sort(as,as+N);
  for(int i=0;i<N;i++){
    if(as[i]!=i){
      printf("NO\n");
      return;
    }
  }
  printf("YES\n");
  return;
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}