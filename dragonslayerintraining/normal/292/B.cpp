#include <cstdio>

int N,M;

int deg[100000];
int cnt[100000];

int main(){
  scanf("%d %d",&N,&M);
  for(int i=0;i<M;i++){
    int X,Y;
    scanf("%d %d",&X,&Y);
    X--,Y--;
    deg[X]++;
    deg[Y]++;
  }
  for(int i=0;i<N;i++){
    cnt[deg[i]]++;
  }
  if((cnt[1]==2)&&(cnt[2]==N-2)){
    printf("bus");
  }else if(cnt[2]==N){
    printf("ring");
  }else if((cnt[1]==N-1)&&(cnt[N-1]==1)){
    printf("star");
  }else{
    printf("unknown");
  }
  printf(" topology\n");
  return 0;
}