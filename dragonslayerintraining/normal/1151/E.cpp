#include <cstdio>
#include <algorithm>
#include <stdint.h>

int as[100005];
int64_t ans=0;

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
    ans+=1LL*as[i]*(N-as[i]+1);
  }
  for(int i=0;i<N-1;i++){
    int bs[2]={as[i],as[i+1]};
    if(bs[0]>bs[1]) std::swap(bs[0],bs[1]);
    ans-=1LL*bs[0]*(N-bs[1]+1);
  }
  printf("%I64d\n",ans);
  return 0;
}