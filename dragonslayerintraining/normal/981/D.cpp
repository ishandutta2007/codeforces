#include <cstdio>
#include <algorithm>
#include <stdint.h>
#include <set>

int64_t as[60];

bool can[60][60];

int main(){
  int64_t N,K;
  scanf("%I64d %I64d",&N,&K);
  for(int64_t i=1;i<=N;i++){
    scanf("%I64d",&as[i]);
    as[i]+=as[i-1];
  }
  int64_t low=0,high=(1LL<<60);
  while(high-low>1){
    int64_t mid=(low+high)/2;
    for(int64_t k=0;k<=K;k++){
      for(int64_t i=0;i<=N;i++){
	can[i][k]=false;
      }
    }
    can[0][0]=true;
    for(int64_t k=1;k<=K;k++){
      for(int64_t i=0;i<=N;i++){
	for(int64_t j=0;j<i;j++){
	  if(((as[i]-as[j])&mid)==mid){
	    can[i][k]|=can[j][k-1];
	  }
	}
      }
    }
    if(can[N][K]){
      low=mid;
    }else{
      high=mid;
    }
  }
  printf("%I64d\n",low);
  return 0;
}