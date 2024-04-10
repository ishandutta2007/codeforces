#include <cstdio>
#include <stdint.h>
#include <map>

int64_t as[200005];

int main(){
  int64_t N,K;
  scanf("%I64d %I64d",&N,&K);
  int64_t mask=(1<<K)-1;
  std::map<int64_t,int64_t> freq;
  freq[0]++;
  for(int64_t i=1;i<=N;i++){
    scanf("%I64d",&as[i]);
    as[i]^=as[i-1];
    if(as[i]&1) as[i]^=mask;
    freq[as[i]]++;
  }
  int64_t ans=(N+1)*(N+1);
  for(auto it:freq){
    int64_t val=it.first;
    int64_t cnt=it.second;
    int64_t cnt1=cnt/2;
    int64_t cnt2=(cnt+1)/2;
    ans-=cnt1*cnt1;
    ans-=cnt2*cnt2;
  }
  printf("%I64d\n",ans/2);
  return 0;
}