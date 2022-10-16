#include <cstdio>
#include <stdint.h>

int64_t bright[15][101][101];

int main(){
  int64_t N,Q,C;
  scanf("%I64d %I64d %I64d",&N,&Q,&C);
  for(int64_t i=0;i<N;i++){
    int64_t X,Y,S;
    scanf("%I64d %I64d %I64d",&X,&Y,&S);
    for(int64_t t=0;t<=C;t++){
      bright[t][X][Y]+=((S+t)%(C+1));
    }
  }
  for(int64_t t=0;t<=C;t++){
    for(int64_t i=1;i<=100;i++){
      for(int64_t j=1;j<=100;j++){
	bright[t][i][j]+=bright[t][i][j-1]+bright[t][i-1][j]-bright[t][i-1][j-1];
      }
    }
  }
  for(int64_t i=0;i<Q;i++){
    int64_t T;
    int64_t X1,Y1,X2,Y2;
    scanf("%I64d %I64d %I64d %I64d %I64d",&T,&X1,&Y1,&X2,&Y2);
    T%=(C+1);
    X1--,Y1--;
    int64_t total=bright[T][X2][Y2]-bright[T][X2][Y1]-bright[T][X1][Y2]+bright[T][X1][Y1];
    printf("%I64d\n",total);
  }
  return 0;
}