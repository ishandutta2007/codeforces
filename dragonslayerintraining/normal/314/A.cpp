#include <cstdio>
#include <vector>
#include <stdint.h>

int64_t as[200005];

std::vector<int64_t> vs;

int64_t ac=0;
int64_t rank=0;

int main(){
  int64_t N,K;
  scanf("%I64d %I64d",&N,&K);
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&as[i]);
  }
  for(int64_t i=0;i<N;i++){
    int64_t change=(ac-(N-vs.size()-rank-1)*as[i]*rank);
    //printf("Change[%I64d]=%I64d\n",i,change);
    if(change<K){
      vs.push_back(i);
    }else{
      ac+=as[i]*rank;
      rank++;
    }
  }
  for(int64_t v:vs){
    printf("%I64d\n",v+1);
  }
  return 0;
}