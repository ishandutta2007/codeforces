#include <cstdio>
#include <vector>
#include <stdint.h>
#include <cassert>

int N;
int as[1000005];

int64_t segmax(){
  std::vector<std::pair<int,int> > stk;
  stk.emplace_back(1e9+1,-1);
  int64_t sum=0;
  for(int i=0;i<=N;i++){
    while(stk.back().first<=as[i]){
      int64_t val=stk.back().first;
      int64_t right=i-stk.back().second;
      int64_t left=stk.back().second-stk[stk.size()-2].second;
      sum+=val*left*right;
      stk.pop_back();
    }
    stk.emplace_back(as[i],i);
  }
  assert(stk.size()==2);
  return sum;
}

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  as[N]=1e9;
  int64_t max=segmax();
  for(int i=0;i<N;i++){
    as[i]=-as[i];
  }
  int64_t min=segmax();
  printf("%I64d\n",max+min);
  return 0;
}