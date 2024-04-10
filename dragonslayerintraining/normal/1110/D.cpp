#include <cstdio>
#include <algorithm>

const int INF=1e9+7;

int cnt[1000005];

int dp[1000005][6][6];

int best=0;
void setmax(int& x,int y){
  x=std::max(x,y);
  best=std::max(best,y);
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    cnt[A]++;
  }
  for(int i=0;i<=M;i++){
    for(int a=0;a<6;a++){
      for(int b=0;b<6;b++){
	dp[i][a][b]=-INF;
      }
    }
  }
  dp[0][0][0]=0;
  for(int i=1;i<=M;i++){
    int c=cnt[i];
    for(int a=0;a<6;a++){
      for(int b=0;b<6;b++){
	for(int h=0;h<3;h++){
	  if(a>=h&&b>=h&&c>=h){
	    setmax(dp[i][b-h][(c-h)%3],dp[i-1][a][b]+(c-h)/3+h);
	    if(c-h>=3){
	      setmax(dp[i][b-h][(c-h)%3+3],dp[i-1][a][b]+(c-h-3)/3+h);
	    }
	  }
	}
      }
    }
  }
  /*
  for(int i=1;i<=M;i++){
    for(int a=0;a<6;a++){
      for(int b=0;b<6;b++){
	if(dp[i][a][b]>=0){
	  printf("dp[%d][%d,%d]=%d\n",i,a,b,dp[i][a][b]);
	}
      }
    }
  }
  */
  printf("%d\n",best);
  return 0;
}