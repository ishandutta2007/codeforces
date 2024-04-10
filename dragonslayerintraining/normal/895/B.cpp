#include <cstdio>
#include <algorithm>
#include <stdint.h>

int as[100000];

int main(){
  int N,X,K;
  scanf("%d %d %d",&N,&X,&K);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  std::sort(as,as+N);
  int low=0,high=0;
  int64_t cnt=0;
  for(int j=0;j<N;j++){
    while((high<N)&&(as[high]<=as[j])&&(as[j]/X-(as[high]+X-1)/X+1>=K)){
      high++;
    }
    while((low<N)&&(as[j]/X-(as[low]+X-1)/X+1>K)){
      low++;
    }
    cnt+=high-low;
  }
  printf("%I64d\n",cnt);
  return 0;
}