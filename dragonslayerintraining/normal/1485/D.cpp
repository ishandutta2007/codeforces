#include <cstdio>

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      int A;
      scanf("%d",&A);
      printf("%d ",720720+(i+j)%2*A*A*A*A);
    }
    printf("\n");
  }
}