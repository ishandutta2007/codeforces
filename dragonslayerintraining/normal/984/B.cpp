#include <cstdio>

char grid[105][105];

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=1;i<=N;i++){
    scanf("%s",grid[i]+1);
    for(int j=1;j<=M;j++){
      if(grid[i][j]=='.') grid[i][j]='0';
    }
  }
  for(int i=1;i<=N;i++){
    for(int j=1;j<=M;j++){
      int cnt=0;
      for(int di=-1;di<=1;di++){
	for(int dj=-1;dj<=1;dj++){
	  cnt+=(grid[i+di][j+dj]=='*');
	}
      }
      if(grid[i][j]!='*'&&grid[i][j]!=('0'+cnt)){
	printf("NO\n");
	return 0;
      }
    }
  }
  printf("YES\n");
  return 0;
}