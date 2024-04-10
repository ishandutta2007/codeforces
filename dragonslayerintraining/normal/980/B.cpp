#include <cstdio>
#include <algorithm>

char grid[4][100];

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<4;i++){
    std::fill(grid[i],grid[i]+N,'.');
  }
  printf("YES\n");
  if(K){
    grid[1][N/2]='#';
    K--;
    if(K%2==1){
      grid[2][N/2]='#';
      K--;
    }
    for(int i=1;K>0;i++){
      if(K){
	grid[1][N/2+i]='#';
	grid[1][N/2-i]='#';
	K-=2;
      }
      if(K){
	grid[2][N/2+i]='#';
	grid[2][N/2-i]='#';
	K-=2;
      }
    }
  }
  for(int i=0;i<4;i++){
    printf("%s\n",grid[i]);
  }
  return 0;
}