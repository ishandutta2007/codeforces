#include <cstdio>
#include <algorithm>

const int64_t INF=1e18+7;

int64_t as[100000];

int main(){
  int64_t N,W;
  scanf("%I64d %I64d",&N,&W);
  int64_t low=0,high=W;
  int64_t sum=0;
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&as[i]);
    sum+=as[i];
    low=std::max(low,-sum);
    high=std::min(high,W-sum);
  }
  printf("%I64d\n",std::max<int64_t>(0,high-low+1));
  return 0;
}