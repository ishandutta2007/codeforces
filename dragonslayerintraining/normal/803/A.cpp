#include <cstdio>

int mat[101][101];

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    if(K>=1){
      mat[i][i]=1;
      K--;
    }
    for(int j=i+1;j<N;j++){
      if(K>=2){
	mat[i][j]=mat[j][i]=1;
	K-=2;
      }
    }
  }
  if(K){
    printf("-1\n");
    return 0;
  }else{
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
	if(j) printf(" ");
	printf("%d",mat[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}