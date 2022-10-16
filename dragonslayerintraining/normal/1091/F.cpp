#include <cstdio>
#include <algorithm>
#include <stdint.h>

const int64_t INF=1e18;

int64_t ls[100005];
char ts[100005];

int64_t supply[10];

int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&ls[i]);
  }
  scanf("%s",ts);
  int64_t cost=0;
  for(int64_t i=0;i<N;i++){
    int64_t L=ls[i];
    if(ts[i]=='G'){
      supply[2]+=2*L;
      supply[5]=INF;
    }else if(ts[i]=='W'){
      supply[1]+=2*L;
      supply[3]=INF;
    }
    cost+=L;
    for(int64_t k=0;L;k++){
      int64_t use=std::min(L,supply[k]);
      cost+=k*use;
      supply[k]-=use;
      L-=use;
    }
  }
  printf("%I64d\n",cost);
  return 0;
}