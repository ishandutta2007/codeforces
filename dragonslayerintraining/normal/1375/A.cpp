#include <cstdio>
#include <cmath>

int as[100005];

void solve(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
    if(i%2){
      as[i]=-labs(as[i]);
    }else{
      as[i]=labs(as[i]);
    }
  }
  for(int i=0;i<N;i++){
    if(i) printf(" ");
    printf("%d",as[i]);
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