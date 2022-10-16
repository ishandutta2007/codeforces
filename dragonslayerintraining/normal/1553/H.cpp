#include <cstdio>
#include <algorithm>
#include <functional>

const int INF=1<<21;

int N,K;

int dp[1<<19];
int min[1<<19];
int max[1<<19];

int main(){
  scanf("%d %d",&N,&K);
  for(int i=0;i<(1<<K);i++){
    dp[i]=INF;
    min[i]=INF;
    max[i]=-INF;
  }
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    min[A]=0;
    max[A]=0;
  }
  for(int k=0;k<K;k++){
    for(int i=0;i<(1<<K);i++){
      if(i&(1<<k)) continue;
      int j=i|(1<<k);
      int in=std::min(dp[i],dp[j]);
      dp[i]=std::min(in,min[j]+(1<<k)-max[i]);
      dp[j]=std::min(in,min[i]+(1<<k)-max[j]);
      std::tie(min[i],min[j])=std::make_pair(std::min(min[i],min[j]+(1<<k)),
					     std::min(min[j],min[i]+(1<<k)));
      std::tie(max[i],max[j])=std::make_pair(std::max(max[i],max[j]+(1<<k)),
					     std::max(max[j],max[i]+(1<<k)));
    }
  }
  for(int i=0;i<(1<<K);i++){
    printf("%d ",dp[i]);
  }
}