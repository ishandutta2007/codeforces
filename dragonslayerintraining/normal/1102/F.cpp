#include <cstdio>
#include <algorithm>

const int INF=1e9+7;

int as[16][10000];

int inner[16][16];
int outer[16][16];
int dp[16][1<<16];

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      scanf("%d",&as[i][j]);
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      inner[i][j]=INF;
      outer[i][j]=INF;
      for(int k=0;k<M;k++){
	inner[i][j]=std::min(inner[i][j],std::abs(as[i][k]-as[j][k]));
      }
      for(int k=0;k<M-1;k++){
	outer[i][j]=std::min(outer[i][j],std::abs(as[i][k]-as[j][k+1]));
      }
    }
  }
  int ans=0;
  for(int j=0;j<N;j++){
    for(int i=0;i<N;i++){
      for(int m=0;m<(1<<N);m++){
	dp[i][m]=0;
      }
    }
    for(int i=0;i<N;i++){
      dp[i][1<<i]=outer[j][i];
    }
    for(int m=0;m<(1<<N);m++){
      for(int i=0;i<N;i++){
	for(int k=0;k<N;k++){
	  if((m&(1<<k))==0){
	    dp[k][m|(1<<k)]=std::max(dp[k][m|(1<<k)],std::min(dp[i][m],inner[i][k]));
	  }
	}
      }
    }
    ans=std::max(ans,dp[j][(1<<N)-1]);
  }
  printf("%d\n",ans);
  return 0;
}