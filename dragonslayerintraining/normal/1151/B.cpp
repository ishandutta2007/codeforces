#include <cstdio>

int mat[505][505];

int row=-1;
int col=-1;

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  int sum=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      scanf("%d",&mat[i][j]);
      if(mat[i][j]!=mat[i][0]){
	row=i;
	col=j;
      }
    }
    sum^=mat[i][0];
  }
  if(row==-1){
    if(sum==0){
      printf("NIE\n");
      return 0;
    }
  }else{
    if(sum!=0){
      col=0;
    }
  }
  printf("TAK\n");
  for(int i=0;i<N;i++){
    if(i) printf(" ");
    printf("%d",(i==row)?col+1:1);
  }
  printf("\n");
  return 0;
}