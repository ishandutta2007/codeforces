#include <cstdio>

char grid[100][100];

void solve(){
  int N,M;
  scanf("%d %d",&N,&M);
  bool flag[2]={false,false};
  for(int i=0;i<N;i++){
    scanf("%s",grid[i]);
    for(int j=0;j<M;j++){
      if(grid[i][j]=='.') continue;
      flag[(i+j+(grid[i][j]=='R'))%2]=true;
    }
  }
  if(!flag[0]){
    printf("YES\n");
    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
	printf("%c",(i+j)%2?'W':'R');
      }
      printf("\n");
    }
  }else if(!flag[1]){
    printf("YES\n");
    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
	printf("%c",(i+j)%2?'R':'W');
      }
      printf("\n");
    }
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