#include <cstdio>
#include <queue>
#include <stdint.h>

int main(){
  int64_t N;
  scanf("%I64d",&N);
  int64_t profit=0;
  std::priority_queue<int64_t,std::vector<int64_t>,std::greater<int64_t> > buys;
  for(int64_t i=0;i<N;i++){
    int64_t P;
    scanf("%I64d",&P);
    buys.push(P);
    int64_t cost=buys.top();
    buys.pop();
    profit+=P-cost;
    buys.push(P);
  }
  printf("%I64d\n",profit);
  return 0;
}