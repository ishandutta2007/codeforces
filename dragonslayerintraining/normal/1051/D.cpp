#include <cstdio>

const int MOD=998244353;

int dp[1005][4][2005];

int increase[4][4]={{0,1,1,1},
		    {0,0,2,0},
		    {0,2,0,0},
		    {1,1,1,0}};

void add_mod(int& x,int y){
  x=(x+y)%MOD;
}

int main(){
  dp[1][0][1]=1;
  dp[1][1][2]=1;
  dp[1][2][2]=1;
  dp[1][3][1]=1;
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=1;i<N;i++){
    for(int s=0;s<4;s++){
      for(int k=1;k<=i*2;k++){
	for(int t=0;t<4;t++){
	  add_mod(dp[i+1][t][k+increase[s][t]],dp[i][s][k]);
	}
      }
    }
  }
  int sum=0;
  for(int s=0;s<4;s++){
    add_mod(sum,dp[N][s][K]);
  }
  printf("%d\n",sum);
  return 0;
}