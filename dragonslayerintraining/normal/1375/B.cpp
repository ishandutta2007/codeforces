#include <cstdio>

int as[300][300];
int bs[300][300];

void solve(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      scanf("%d",&as[i][j]);
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      bs[i][j]=(i>0)+(i<N-1)+(j>0)+(j<M-1);
      if(bs[i][j]<as[i][j]){
	printf("NO\n");
	return;
      }
    }
  }
  printf("YES\n");
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(j) printf(" ");
      printf("%d",bs[i][j]);
    }
    printf("\n");
  }
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}