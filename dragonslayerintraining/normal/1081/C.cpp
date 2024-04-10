#include <cstdio>

const int MOD=998244353;

int combo[2005][2005];

int main(){
  int N,M,K;
  scanf("%d %d %d",&N,&M,&K);
  for(int i=0;i<=N;i++){
    combo[i][0]=combo[0][i]=1;
  }
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      combo[i][j]=(combo[i-1][j]+combo[i][j-1])%MOD;
      //printf("combo[%d][%d]=%d\n",i,j,combo[i][j]);
    }
  }
  int ans=1LL*combo[N-1-K][K]*M%MOD;
  for(int i=0;i<K;i++){
    ans=1LL*ans*(M-1)%MOD;
  }
  printf("%d\n",ans);
  return 0;
}