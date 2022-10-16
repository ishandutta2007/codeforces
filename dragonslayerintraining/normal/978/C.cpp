#include <cstdio>
#include <algorithm>
#include <stdint.h>

int64_t as[200005];

int main(){
  int64_t N,M;
  scanf("%I64d %I64d",&N,&M);
  for(int64_t i=1;i<=N;i++){
    scanf("%I64d",&as[i]);
    as[i]+=as[i-1];
  }
  for(int64_t i=0;i<M;i++){
    int64_t B;
    scanf("%I64d",&B);
    B--;
    int64_t* it=std::upper_bound(as,as+N+1,B);
    --it;
    printf("%I64d %I64d\n",int64_t(it-as)+1,B-*it+1);
  }
}