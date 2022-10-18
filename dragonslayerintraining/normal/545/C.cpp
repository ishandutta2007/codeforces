#include <cstdio>
#include <algorithm>
#include <stdint.h>

int64_t xs[100000];
int64_t hs[100000];

int64_t left[100000];
int64_t right[100000];

int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=0;i<N;i++){
    scanf("%I64d %I64d",&xs[i],&hs[i]);
  }
  left[0]=1;
  right[0]=0;
  for(int64_t i=1;i<N;i++){
    right[i]=std::max(left[i-1],right[i-1]);
    if(xs[i]>xs[i-1]+hs[i-1]){
      right[i]=std::max(right[i],1+right[i-1]);
    }
    if(xs[i]-hs[i]>xs[i-1]){
      left[i]=1+std::max(left[i-1],right[i-1]);
    }
    if(xs[i]-hs[i]>xs[i-1]+hs[i-1]){
      left[i]=std::max(left[i],2+right[i-1]);
    }
  }
  printf("%I64d\n",std::max(left[N-1],1+right[N-1]));
  return 0;
}