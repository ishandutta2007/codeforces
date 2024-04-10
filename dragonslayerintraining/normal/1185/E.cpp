#include <cstdio>
#include <algorithm>

const int INF=1e9+7;

char grid[2005][2005];

int pos[256][4];

void solve(){
  for(char c='a';c<='z';c++){
    pos[c][0]=INF;
    pos[c][1]=INF;
    pos[c][2]=-INF;
    pos[c][3]=-INF;
  }
  int cnt=0;
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    scanf("%s",grid[i]);
    for(int j=0;j<M;j++){
      char c=grid[i][j];
      if(c=='.') continue;
      pos[c][0]=std::min(pos[c][0],i);
      pos[c][1]=std::min(pos[c][1],j);
      pos[c][2]=std::max(pos[c][2],i);
      pos[c][3]=std::max(pos[c][3],j);
      cnt=std::max(cnt,c-'a'+1);
    }
  }
  int hide_row=pos['a'+cnt-1][0],hide_col=pos['a'+cnt-1][1];
  for(int c='a';c<'a'+cnt;c++){
    //printf("%c: %d %d %d %d\n",c,pos[c][0]+1,pos[c][1]+1,pos[c][2]+1,pos[c][3]+1);
    if(pos[c][0]!=pos[c][2]&&pos[c][1]!=pos[c][3]){
      if(pos[c][0]!=INF){
	printf("NO\n");
	return;
      }else{
	pos[c][0]=pos[c][2]=hide_row;
	pos[c][1]=pos[c][3]=hide_col;
      }
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      char c='.';
      for(int t='a';t<'a'+cnt;t++){
	if(i>=pos[t][0]&&j>=pos[t][1]&&
	   i<=pos[t][2]&&j<=pos[t][3]){
	  c=t;
	}
      }
      if(grid[i][j]!=c){
	printf("NO\n");
	return;
      }
    }
  }
  printf("YES\n");
  printf("%d\n",cnt);
  for(int c='a';c<'a'+cnt;c++){
    printf("%d %d %d %d\n",pos[c][0]+1,pos[c][1]+1,pos[c][2]+1,pos[c][3]+1);
  }
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
  return 0;
}