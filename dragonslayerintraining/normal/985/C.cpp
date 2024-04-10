#include <cstdio>
#include <stdint.h>
#include <algorithm>

int64_t as[100000];

int main(){
  int64_t N,K,L;
  scanf("%I64d %I64d %I64d",&N,&K,&L);
  for(int64_t i=0;i<N*K;i++){
    scanf("%I64d",&as[i]);
  }
  std::sort(as,as+N*K);
  int64_t sum=0;
  int64_t need=N;
  for(int64_t i=0;i<N*K;i+=K){
    if(as[i]>as[0]+L){
      for(int64_t j=i;j>=0;j--){
	if((j%K!=0)&&(as[j]<=as[0]+L)){
	  sum+=as[j];
	  if(--need==0){
	    break;
	  }
	}
      }
      break;
    }
    sum+=as[i];
    need--;
  }
  if(need>0){
    printf("0\n");
  }else{
    printf("%I64d\n",sum);
  }
  return 0;
}