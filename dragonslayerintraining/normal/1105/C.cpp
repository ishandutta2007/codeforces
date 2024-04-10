#include <cstdio>

const int MOD=1e9+7;

int N,L,R;

int cnt[3];

int dp[3]={1,0,0};
int next[3];

int main(){
  scanf("%d %d %d",&N,&L,&R);
  R++;
  while((R-L)%3!=0){
    cnt[(--R)%3]++;
  }
  for(int i=0;i<3;i++){
    cnt[i]+=(R-L)/3;
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<3;j++){
      for(int k=0;k<3;k++){
	next[k]=(next[k]+1LL*dp[j]*cnt[(k+3-j)%3])%MOD;
      }
    }
    for(int j=0;j<3;j++){
      dp[j]=next[j];
      next[j]=0;
    }
  }
  printf("%d\n",dp[0]);
  return 0;
}