#include <cstdio>
#include <algorithm>

char grid[10][10];

void solve(){
  int N,M;
  scanf("%d %d",&N,&M);
  int row=5,col=5;
  for(int i=0;i<N;i++){
    scanf("%s",grid[i]);
    for(int j=0;j<M;j++){
      if(grid[i][j]=='R'){
	row=std::min(row,i);
	col=std::min(col,j);
      }
    }
  }
  if(grid[row][col]=='R'){
    printf("YES\n");
  }else{
    printf("NO\n");
  }
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}