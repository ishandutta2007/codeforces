#include <cstdio>
#include <cassert>

const int MOD=1e9+7;

int N,Q;

int fact[3000006];
int inv[3000006];
int invfact[3000006];

int dp[3000006][3];

int choose(int n,int k){
  if(k<0||k>n) return 0;
  return 1LL*fact[n]*invfact[k]%MOD*invfact[n-k]%MOD;
}

int brute(int x,int s=0){
  int ans=0;
  for(int a=0;a<=N*3;a++){
    if(a%3==s){
      ans=(ans+choose(a,x))%MOD;
    }
  }
  return ans;
}

int main(){
  fact[0]=1;
  fact[1]=1;
  invfact[0]=1;
  inv[1]=1;
  invfact[1]=1;
  scanf("%d %d",&N,&Q);
  for(int i=2;i<=3000003;i++){
    fact[i]=1LL*fact[i-1]*i%MOD;
    inv[i]=1LL*(MOD-MOD/i)*inv[MOD%i]%MOD;
    invfact[i]=1LL*invfact[i-1]*inv[i]%MOD;
  }
  dp[0][0]=N+1;
  dp[0][1]=N;
  dp[0][2]=N;
  for(int x=1;x<=N*3;x++){
    int sum=choose(N*3+1,x+1);
    int d[3]={dp[x-1][2],dp[x-1][0],dp[x-1][1]};
    d[2-(x+0)%3]=(d[2-(x+0)%3]+MOD-choose(N*3+1,x))%MOD;
    /*for(int s=0;s<3;s++){
      fprintf(stderr,"%d vs %d\n",(brute(x,s)+MOD-brute(x,(s+2)%3))%MOD,d[s]);
    }
    for(int s=0;s<3;s++){
      fprintf(stderr,"%d vs %d\n",(brute(x,s)+MOD-brute(x,(s+2)%3))%MOD,d[s]);
    }
    */
    for(int s=0;s<3;s++){
      dp[x][s]=1LL*inv[3]*((sum+d[s])%MOD+(MOD-d[(s+2)%3]))%MOD;
    }
    /*
    for(int s=0;s<3;s++){
      printf("dp[%d][%d]=%d=%d\n",x,s,dp[x][s],brute(x,s));
    }
    */
  }
  for(int i=0;i<Q;i++){
    int X;
    scanf("%d",&X);
    printf("%d\n",dp[X][2-(X+2)%3]);
  }
}