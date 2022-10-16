#include <cstdio>
#include <algorithm>
#include <stdint.h>

int as[200000];
int prefix[200001];

int main(){
  int N,Q;
  scanf("%d %d",&N,&Q);
  
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  for(int i=0;i<Q;i++){
    int L,R;
    scanf("%d %d",&L,&R);
    prefix[L-1]++;
    prefix[R]--;
  }
  for(int i=1;i<N;i++){
    prefix[i]+=prefix[i-1];
  }
  std::sort(as,as+N);
  std::sort(prefix,prefix+N);
  int64_t max=0;
  for(int i=0;i<N;i++){
    max+=as[i]*static_cast<int64_t>(prefix[i]);
  }
  printf("%I64d\n",max);
  return 0;
}