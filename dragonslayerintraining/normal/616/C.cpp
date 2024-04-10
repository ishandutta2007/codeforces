#include <cstdio>
#include <set>

int dx[5]={-1,0,1,0};
int dy[5]={0,-1,0,1};

char grid[1005][1005];
int N,M;

int cc[1005][1005];
int size[1000006];
int cc_cnt=0;

int ans[1005][1005];

void dfs(int x,int y,int c){
  cc[x][y]=c;
  size[c]++;
  for(int d=0;d<4;d++){
    int x2=x+dx[d],y2=y+dy[d];
    if(x2<0||x2>=N||y2<0||y2>=M) continue;
    if(cc[x2][y2]||grid[x2][y2]!='.') continue;
    dfs(x2,y2,c);
  }
}

int main(){
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    scanf("%s",grid[i]);
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(!cc[i][j]&&grid[i][j]=='.'){
	dfs(i,j,++cc_cnt);
      }
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      std::set<int> ccs;
      for(int d=0;d<4;d++){
	int x2=i+dx[d],y2=j+dy[d];
	if(x2<0||x2>=N||y2<0||y2>=M) continue;
	if(grid[x2][y2]!='.') continue;
	ccs.insert(cc[x2][y2]);
      }
      for(int id:ccs){
	ans[i][j]+=size[id];
      }
    }
  }
  
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(grid[i][j]=='.'){
	printf(".");
      }else{
	printf("%d",(ans[i][j]+1)%10);
      }
    }
    printf("\n");
  }
}