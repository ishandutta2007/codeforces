#include <cstdio>
#include <stdint.h>
#include <map>

int as[300005];

std::map<int,int> freq;

int main(){
  int N,P,K;
  scanf("%d %d %d",&N,&P,&K);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
    freq[(1LL*as[i]*as[i]%P*as[i]%P-K+P)%P*as[i]%P]++;
  }
  int64_t ans=0;
  for(auto it:freq){
    ans+=it.second*(it.second-1)/2;
  }
  printf("%I64d\n",ans);
  return 0;
}