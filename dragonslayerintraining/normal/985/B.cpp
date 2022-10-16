#include <cstdio>

char grid[2000][2005];
int N,M;
int cnt[2000];

bool check(int i){
  for(int j=0;j<M;j++){
    if(cnt[j]<=(grid[i][j]=='1')){
      return false;
    }
  }
  return true;
}

int main(){
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    scanf("%s",grid[i]);
    for(int j=0;j<M;j++){
      if(grid[i][j]=='1'){
	cnt[j]++;
      }
    }
  }
  for(int i=0;i<N;i++){
    if(check(i)){
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
  return 0;
}