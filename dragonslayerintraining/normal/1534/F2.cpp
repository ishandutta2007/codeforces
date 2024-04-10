#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>

int N,M;

char* grid[400005];
bool* vis[400005];

int as[400005];

int top[400005];
int target[400005];

int label,t;

int end[400005][2];

//something falls through (i,j)
void drop(int i,int j){
  if(i<0||i>=N||j<0||j>=M) return;
  if(vis[i][j]) return;
  vis[i][j]=true;
  if(target[j]==i){
    end[j][t]=label;
    //printf("%d fell at %d\n",j,label);
  }
  drop(i+1,j);
  if(j-1>=0&&grid[i][j-1]=='#'){
    drop(i,j-1);
  }
  if(j+1<M&&grid[i][j+1]=='#'){
    drop(i,j+1);
  }
  if(i>0&&grid[i-1][j]=='#'){
    drop(i-1,j);
  }
}

int main(){
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    grid[i]=new char[M+5];
    vis[i]=new bool[M];
    scanf("%s",grid[i]);
  }
  for(int j=0;j<M;j++){
    scanf("%d",&as[j]);
  }
  std::fill(top,top+M,-1);
  std::fill(target,target+M,-1);
  for(int j=0;j<M;j++){
    for(int i=0;i<N;i++){
      if(grid[i][j]=='#'){
	top[j]=i;
	break;
      }
    }
    int cnt=0;
    for(int i=N-1;i>=0;i--){
      if(grid[i][j]=='#'){
	cnt++;
	if(cnt==as[j]){
	  target[j]=i;
	}
      }
    }
  }
  for(int j=0;j<M;j++){
    end[j][0]=-1;
    end[j][1]=-1;
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      vis[i][j]=false;
    }
  }
  for(int j=0;j<M;j++){
    label=j;
    t=0;
    if(top[j]!=-1){
      drop(top[j],j);
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      vis[i][j]=false;
    }
  }
  for(int j=M-1;j>=0;j--){
    label=j;
    t=1;
    if(top[j]!=-1){
      drop(top[j],j);
    }
  }
  std::vector<std::pair<int,int> > itvls;
  for(int j=0;j<M;j++){
    if(target[j]==-1) continue;
    //fprintf(stderr,"%d: %d,%d\n",j,end[j][0],end[j][1]);
    assert(end[j][0]!=-1);
    assert(end[j][1]!=-1);
    itvls.push_back({end[j][1],-end[j][0]});
  }
  std::sort(itvls.begin(),itvls.end());
  int cost=0;
  int far=-1;
  for(auto it:itvls){
    int l=-it.second;
    int r=it.first;
    //printf("[%d,%d]\n",l,r);
    if(l>far){
      far=r;
      cost++;
    }
  }
  printf("%d\n",cost);
}