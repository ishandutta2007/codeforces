#include <cstdio>
#include <algorithm>
#include <stdint.h>

int64_t vs[2][100001];

int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=1;i<=N;i++){
    scanf("%I64d",&vs[0][i]);
    vs[1][i]=vs[0][i];
  }
  std::sort(vs[1]+1,vs[1]+N+1);
  for(int64_t i=1;i<=N;i++){
    vs[0][i]+=vs[0][i-1];
    vs[1][i]+=vs[1][i-1];
  }
  int64_t M;
  scanf("%I64d",&M);
  for(int64_t i=0;i<M;i++){
    int64_t t,L,R;
    scanf("%I64d %I64d %I64d",&t,&L,&R);
    t--;
    printf("%I64d\n",vs[t][R]-vs[t][L-1]);
  }
  return 0;
}