#include <cstdio>
#include <algorithm>

const int INF=1e9+7;

void setmin(int& x,int y){
  x=std::min(x,y);
}

int dp[105][105];

int main(){
  int N,V;
  scanf("%d %d",&N,&V);
  for(int i=0;i<=N;i++){
    for(int v=0;v<=V;v++){
      dp[i][v]=INF;
    }
  }
  dp[0][0]=0;
  for(int i=0;i<N;i++){
    for(int v=1;v<=V;v++){
      setmin(dp[i][v],dp[i][v-1]+i+1);
      setmin(dp[i+1][v-1],dp[i][v]);
    }
  }
  printf("%d\n",dp[N-1][0]);
  return 0;
}