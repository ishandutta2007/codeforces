#include <cstdio>
#include <stdint.h>

int64_t N,M,K;

int64_t prefix[100001];

int64_t ls[100000],rs[100000],ds[100000];
int64_t times[100001];

int main(){
  scanf("%I64d %I64d %I64d",&N,&M,&K);
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&prefix[i]);
  }
  for(int64_t i=N-1;i>0;i--){
    prefix[i]-=prefix[i-1];
  }
  for(int64_t i=0;i<M;i++){
    scanf("%I64d %I64d %I64d",&ls[i],&rs[i],&ds[i]);
  }
  for(int64_t i=0;i<K;i++){
    int64_t X,Y;
    scanf("%I64d %I64d",&X,&Y);
    times[X-1]++;
    times[Y]--;
  }
  for(int64_t i=1;i<M;i++){
    times[i]+=times[i-1];
  }
  for(int64_t i=0;i<M;i++){
    prefix[ls[i]-1]+=ds[i]*times[i];
    prefix[rs[i]]-=ds[i]*times[i];
  }
  for(int64_t i=1;i<N;i++){
      prefix[i]+=prefix[i-1];
  }
  for(int64_t i=0;i<N;i++){
    if(i>0){
      printf(" ");
    }
    printf("%I64d",prefix[i]);
  }
  printf("\n");
  return 0;
}