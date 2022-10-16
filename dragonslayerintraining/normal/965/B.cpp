#include <cstdio>
#include <iostream>

char grid[105][105];
int cnt[105][105];

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    scanf("%s",grid[i]);
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<=N-K;j++){
      bool open=true;
      for(int k=j;k<j+K;k++){
	if(grid[i][k]!='.'){
	  open=false;
	}
      }
      if(open){
	for(int k=j;k<j+K;k++){
	  cnt[i][k]++;
	}
      }
    }
  }
  for(int i=0;i<=N-K;i++){
    for(int j=0;j<N;j++){
      bool open=true;
      for(int k=i;k<i+K;k++){
	if(grid[k][j]!='.'){
	  open=false;
	}
      }
      if(open){
	for(int k=i;k<i+K;k++){
	  cnt[k][j]++;
	}
      }
    }
  }
  std::pair<int,std::pair<int,int> > best;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      best=std::max(best,
		    std::make_pair(cnt[i][j],std::make_pair(i,j)));
    }
  }
  printf("%d %d\n",best.second.first+1,best.second.second+1);
  return 0;
}