#include <cstdio>
#include <queue>

char mem[2000006];
char* grid[1000006];

int dr[4]={0,1,0,-1};
int dc[4]={1,0,-1,0};

void solve(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    grid[i]=mem+i*(M+1);
    scanf("%s",grid[i]);
  }
  std::queue<std::pair<int,int> > q;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(grid[i][j]=='L'){
	for(int d=0;d<4;d++){
	  q.push({i+dr[d],j+dc[d]});
	}
      }
    }
  }
  while(!q.empty()){
    int r=q.front().first;
    int c=q.front().second;
    q.pop();
    //printf("(%d,%d)\n",r,c);
    if(r<0||r>=N||c<0||c>=M) continue;
    if(grid[r][c]!='.') continue;
    int free=0;
    for(int d=0;d<4;d++){
      int r2=r+dr[d],c2=c+dc[d];
      if(r2<0||r2>=N||c2<0||c2>=M) continue;
      if(grid[r2][c2]!='.') continue;
      free++;
    }
    //printf("(%d,%d): %d free\n",r,c,free);
    if(free<=1){
      grid[r][c]='+';
      for(int d=0;d<4;d++){
	q.push({r+dr[d],c+dc[d]});
      }
    }
  }
  for(int i=0;i<N;i++){
    printf("%s\n",grid[i]);
  }
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}