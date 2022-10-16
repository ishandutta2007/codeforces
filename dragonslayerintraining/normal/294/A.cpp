#include <cstdio>

int N,M;

int as[102];

int main(){
  scanf("%d",&N);
  for(int i=1;i<=N;i++){
    scanf("%d",&as[i]);
  }
  scanf("%d",&M);
  for(int i=0;i<M;i++){
    int X,Y;
    scanf("%d %d",&X,&Y);
    as[X-1]+=Y-1;
    as[X+1]+=as[X]-Y;
    as[X]=0;
  }
  for(int i=1;i<=N;i++){
    printf("%d\n",as[i]);
  }
  return 0;
}