#include <cstdio>

int next[4][2]={{0,1},{2,1},{2,3},{3,3}};

int rowcnt[1005];
int colcnt[1005];
char grid[1005][1005];
bool vis[1005][1005];
int N,M;

void dfs(int r,int c){
  if(r<0||r>=N||c<0||c>=M||grid[r][c]!='#'||vis[r][c]) return;
  vis[r][c]=true;
  dfs(r+1,c);
  dfs(r-1,c);
  dfs(r,c-1);
  dfs(r,c+1);
}

int main(){
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    scanf("%s",grid[i]);
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      rowcnt[i]+=(grid[i][j]=='#');
      colcnt[j]+=(grid[i][j]=='#');
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(!rowcnt[i]&&!colcnt[j]){
	grid[i][j]='~';
      }
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      rowcnt[i]+=(grid[i][j]=='~');
      colcnt[j]+=(grid[i][j]=='~');
    }
  }
  for(int i=0;i<N;i++){
    int state=0;
    for(int j=0;j<M;j++){
      state=next[state][grid[i][j]=='#'];
    }
    if(state==3||!rowcnt[i]){
      printf("-1\n");
      return 0;
    }
  }
  for(int i=0;i<M;i++){
    int state=0;
    for(int j=0;j<N;j++){
      state=next[state][grid[j][i]=='#'];
    }
    if(state==3||!colcnt[i]){
      printf("-1\n");
      return 0;
    }
  }
  int cnt=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(grid[i][j]=='#'&&!vis[i][j]){
	dfs(i,j);
	cnt++;
      }
    }
  }
  printf("%d\n",cnt);
}