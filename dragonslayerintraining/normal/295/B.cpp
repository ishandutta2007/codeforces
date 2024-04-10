#include <cstdio>
#include <stdint.h>

#include <algorithm>
int64_t N;
int64_t vs[500];

int64_t tmp[500][500];
int64_t dist[500][500];

int64_t sum[500];

int main(){
  scanf("%I64d",&N);
  for(int64_t i=0;i<N;i++){
    for(int64_t j=0;j<N;j++){
      scanf("%I64d",&tmp[i][j]);
    }
  }
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&vs[i]);
    vs[i]--;
  }
  for(int64_t i=0;i<N;i++){
    for(int64_t j=0;j<N;j++){
      dist[i][j]=tmp[vs[N-i-1]][vs[N-j-1]];
    }
  }
  for(int64_t k=0;k<N;k++){
    for(int64_t i=0;i<N;i++){
      for(int64_t j=0;j<N;j++){
	dist[i][j]=std::min(dist[i][j],dist[i][k]+dist[k][j]);
      }
    }
    for(int64_t i=0;i<=k;i++){
      for(int64_t j=0;j<=k;j++){
	sum[k]+=dist[i][j];
      }
    }
  }
  for(int64_t i=0;i<N;i++){
    if(i>0){
      printf(" ");
    }
    printf("%I64d",sum[N-1-i]);
  }
  printf("\n");
  return 0;
}