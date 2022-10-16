#include <cstdio>
#include <set>

char grid[1005][1005];

int row[1000];
int col[1000];
int total=0;

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    scanf("%s",grid[i]);    
  }
  
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(grid[i][j]=='*'){
	total++;
	row[i]++;
	col[j]++;
      }
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(row[i]+col[j]-(grid[i][j]=='*')==total){
	printf("YES\n%d %d\n",i+1,j+1);
	return 0;
      }
    }
  }
  printf("NO\n");
  return 0;
}