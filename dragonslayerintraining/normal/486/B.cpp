#include <cstdio>
#include <algorithm>

int as[100][100];
int bs[100][100];
int row[100];
int col[100];
int rowcheck[100];
int colcheck[100];

int main(){
  int M,N;
  scanf("%d %d",&M,&N);
  std::fill(row,row+M,1);
  std::fill(col,col+N,1);
  for(int i=0;i<M;i++){
    for(int j=0;j<N;j++){
      scanf("%d",&as[i][j]);
      row[i]&=as[i][j];
      col[j]&=as[i][j];
    }
  }
  for(int i=0;i<M;i++){
    for(int j=0;j<N;j++){
      bs[i][j]=(row[i]&col[j]);
      rowcheck[i]|=bs[i][j];
      colcheck[j]|=bs[i][j];
    }
  }
  for(int i=0;i<M;i++){
    for(int j=0;j<N;j++){
      if(as[i][j]!=(rowcheck[i]|colcheck[j])){
	printf("NO\n");
	return 0;
      }
    }
  }
  printf("YES\n");
  for(int i=0;i<M;i++){
    for(int j=0;j<N;j++){
      if(j) printf(" ");
      printf("%d",bs[i][j]);
    }
    printf("\n");
  }
  return 0;
}