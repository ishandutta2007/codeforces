#include <cstdio>
#include <algorithm>
#include <cmath>

int xs[2500],ys[2500];
int N;

double dp[2501][2501][2];

double dist(int i,int j){
  double dx=xs[i]-xs[j],dy=ys[i]-ys[j];
  return std::sqrt(dx*dx+dy*dy);
}

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d %d",&xs[i],&ys[i]);
  }
  for(int i=0;i<N;i++){
    dp[1][i][0]=0;
    dp[1][i][1]=0;
  }
  for(int len=2;len<=N;len++){
    for(int i=0;i<N;i++){
      int a=(i-len+1+N)%N;
      int b=(i-1+N)%N;
      dp[len][i][0]=std::max(dp[len-1][a][1]+dist(i,a),
			     dp[len-1][b][0]+dist(i,b));
      int c=(i+len-1)%N;
      int d=(i+1)%N;
      dp[len][i][1]=std::max(dp[len-1][c][0]+dist(i,c),
			     dp[len-1][d][1]+dist(i,d));
      //fprintf(stderr,"dp[%d][%d][%d]=%lf\n",len,i,0,dp[len][i][0]);
      //fprintf(stderr,"dp[%d][%d][%d]=%lf\n",len,i,1,dp[len][i][1]);
    }
  }
  double best=0;
  for(int i=0;i<N;i++){
    best=std::max(best,dp[N][i][0]);
    best=std::max(best,dp[N][i][1]);
  }
  printf("%.10lf\n",best);
  return 0;
}