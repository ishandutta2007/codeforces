#include <cstdio>
#include <algorithm>
#include <stdint.h>
#include <vector>

const int64_t INF=1e18+7;

bool rain[4005];
int64_t weight[2005];
int64_t cost[4005][2005];
std::vector<int64_t> umbrella[4005];

int main(){
  int64_t A,N,M;
  scanf("%I64d %I64d %I64d",&A,&N,&M);
  for(int64_t i=0;i<N;i++){
    int64_t L,R;
    scanf("%I64d %I64d",&L,&R);
    for(int64_t x=L;x<R;x++){
      rain[x]=true;
    }
  }
  for(int64_t i=1;i<=M;i++){
    int64_t X,P;
    scanf("%I64d %I64d",&X,&P);
    weight[i]=P;
    umbrella[X].push_back(i);
  }
  for(int64_t i=0;i<=A;i++){
    for(int64_t j=0;j<=M;j++){
      cost[i][j]=INF;
    }
  }
  cost[0][0]=0;
  for(int64_t i=0;i<A;i++){
    int64_t mincost=INF;
    for(int64_t j=0;j<=M;j++){
      mincost=std::min(mincost,cost[i][j]);
      //printf("%I64d ",cost[i][j]);
    }
    //printf("\n");
    for(int64_t u:umbrella[i]){
      cost[i][u]=mincost;
    }
    cost[i][0]=mincost;
    for(int64_t j=rain[i];j<=M;j++){
      cost[i+1][j]=std::min(cost[i+1][j],cost[i][j]+weight[j]);
    }
  }
  int64_t mincost=*std::min_element(cost[A],cost[A]+M+1);
  printf("%I64d\n",(mincost<INF)?mincost:-1);
  return 0;
}