#include <cstdio>
#include <algorithm>

double ps[18][18];

double dp[1<<18][18];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      scanf("%lf",&ps[i][j]);
    }
  }
  for(int i=0;i<N;i++){
    dp[(1<<N)-1][i]=(i==0);
  }
  for(int mask=(1<<N)-2;mask>0;mask--){
    for(int i=0;i<N;i++){
      if((mask&(1<<i))==0) continue;
      for(int j=0;j<N;j++){
	if(mask&(1<<j)) continue;
	dp[mask][i]=std::max(dp[mask][i],dp[mask|(1<<j)][j]*ps[j][i]+
			     dp[mask|(1<<j)][i]*ps[i][j]);
      }
      //printf("dp[%d][%d]=%.10lf\n",mask,i,dp[mask][i]);
    }
  }
  double ans=0;
  for(int i=0;i<N;i++){
    ans=std::max(ans,dp[1<<i][i]);
  }
  printf("%.10lf\n",ans);
  return 0;
}