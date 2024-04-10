#include <cstdio>
#include <algorithm>

char board[4][100][105];

int bad[4];

int main(){
  int N;
  scanf("%d",&N);
  for(int b=0;b<4;b++){
    for(int i=0;i<N;i++){
      scanf("%s",board[b][i]);
    }
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
	if((board[b][i][j]=='1')^(i&1)^(j&1)){
	  bad[b]++;
	}
      }
    }
  }
  std::sort(bad,bad+4);
  printf("%d\n",bad[0]+bad[1]+N*N*2-bad[2]-bad[3]);
  
  return 0;
}