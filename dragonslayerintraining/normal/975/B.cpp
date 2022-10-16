#include <cstdio>
#include <algorithm>
#include <stdint.h>

int64_t as[14];
int64_t bs[14];

int main(){
  for(int64_t i=0;i<14;i++){
    scanf("%I64d",&as[i]);
  }
  int64_t best=0;
  for(int64_t i=0;i<14;i++){
    for(int64_t j=0;j<14;j++){
      bs[j]=as[j];
    }
    int64_t take=bs[i];
    bs[i]=0;
    for(int64_t j=0;j<14;j++){
      bs[j]+=take/14;
    }
    take%=14;
    for(int64_t j=(i+1)%14;take;j=(j+1)%14){
      bs[j]++;
      take--;
    }
    int64_t score=0;
    for(int64_t j=0;j<14;j++){
      if(bs[j]%2==0) score+=bs[j];
    }
    best=std::max(best,score);
  }
  printf("%I64d\n",best);
  return 0;
}