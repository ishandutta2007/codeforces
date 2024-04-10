#include <cstdio>
#include <algorithm>
#include <stdint.h>

int64_t N;

int64_t as[1<<20];
int64_t inv[21];
int64_t total=0;

void mergesort(int64_t L,int64_t R,int64_t level){
  if(R-L==1){
    return;
  }
  int64_t M=(L+R)/2;
  mergesort(L,M,level-1);
  mergesort(M,R,level-1);
  int64_t j=M;
  for(int64_t i=L;i<M;i++){
    while((j<R)&&(as[i]>as[j])){
      j++;
    }
    inv[level]-=j-M;
    total+=j-M;
  }
  j=L;
  for(int64_t i=M;i<R;i++){
    while((j<M)&&(as[i]>as[j])){
      j++;
    }
    inv[level]+=j-L;
  }
  std::inplace_merge(as+L,as+M,as+R);
}

int main(){
  scanf("%I64d",&N);
  for(int64_t i=0;i<(1<<N);i++){
    scanf("%I64d",&as[i]);
  }
  mergesort(0,1<<N,N);
  int64_t M;
  scanf("%I64d",&M);
  for(int64_t i=0;i<M;i++){
    int64_t Q;
    scanf("%I64d",&Q);
    for(int64_t k=0;k<=Q;k++){
      total+=inv[k];
      inv[k]=-inv[k];
    }
    printf("%I64d\n",total);
  }
  return 0;
}