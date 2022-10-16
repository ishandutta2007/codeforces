#include <cstdio>
#include <algorithm>
#include <stdint.h>

const int64_t INF=1e18+7;

bool blocked[1000005];
int64_t last[1000005];
int64_t cost[1000005];

int main(){
  int64_t N,M,K;
  scanf("%I64d %I64d %I64d",&N,&M,&K);
  while(M-->0){
    int64_t S;
    scanf("%I64d",&S);
    blocked[S]=true;
  }
  if(blocked[0]){
    printf("-1\n");
    return 0;
  }
  last[0]=0;
  for(int64_t i=1;i<=N;i++){
    last[i]=blocked[i]?last[i-1]:i;
    //printf("last[%I64d]=%I64d\n",i,last[i]);
  }
  int64_t best=INF;
  for(int64_t k=0;k<K;k++){
    scanf("%I64d",&cost[k]);
    int64_t power=k+1;
    int64_t lamps=0;
    for(int64_t i=0;i<N;i=last[std::min(N,i+power)]){
      //printf("%I64d: %I64d\n",k,i);
      lamps++;
      if(i==last[std::min(N,i+power)]){
	lamps=INF;
	break;
      }
    }
    if(lamps<INF){
      best=std::min(best,lamps*cost[k]);
    }
  }
  if(best==INF){
    printf("-1\n");
  }else{
    printf("%I64d\n",best);
  }
  return 0;
}