#include <cstdio>

void solve(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
  }
  printf("%d\n",N/2*6);
  for(int i=0;i<N;i+=2){
    printf("1 %d %d\n",i+1,i+2);
    printf("2 %d %d\n",i+1,i+2);
    printf("1 %d %d\n",i+1,i+2);
    printf("1 %d %d\n",i+1,i+2);
    printf("2 %d %d\n",i+1,i+2);
    printf("1 %d %d\n",i+1,i+2);
  }
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}