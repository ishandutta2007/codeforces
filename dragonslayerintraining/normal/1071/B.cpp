#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

const int INF=1e9+7;

char grid[2005][2005];
int dist[2005][2005];
bool good[2005][2005];

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    scanf("%s",grid[i]);
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      dist[i][j]=INF;
    }
  }
  for(int r=0;r<N;r++){
    for(int c=0;c<N;c++){
      dist[r][c]=(r||c)?INF:0;
      if(r) dist[r][c]=std::min(dist[r][c],dist[r-1][c]);
      if(c) dist[r][c]=std::min(dist[r][c],dist[r][c-1]);
      if(grid[r][c]!='a') dist[r][c]++;
    }
  }
  int far=-1;
  for(int r=0;r<N;r++){
    for(int c=0;c<N;c++){
      if(dist[r][c]<=K) far=std::max(far,r+c);
    }
  }
  for(int r=0;r<N;r++){
    for(int c=0;c<N;c++){
      if(dist[r][c]<=K&&far==r+c){
	good[r][c]=true;
      }
    }
  }
  
  std::string str(far+1,'a');
  if(far==-1){
    str+=grid[0][0];
    good[0][0]=true;
    far=0;
  }
  for(;far<(N-1)*2;far++){
    char next=127;
    for(int r=0;r<N;r++){
      int c=far-r;
      if(c<0||c>=N||!good[r][c]) continue;
      if(r+1<N) next=std::min(next,grid[r+1][c]);
      if(c+1<N) next=std::min(next,grid[r][c+1]);
    } 
    for(int r=0;r<N;r++){
      int c=far-r;
      if(c<0||c>=N||!good[r][c]) continue;
      if(r+1<N&&next==grid[r+1][c]) good[r+1][c]=true;
      if(c+1<N&&next==grid[r][c+1]) good[r][c+1]=true;
    }
    str+=next;
  }
  printf("%s\n",str.c_str());
  return 0;
}