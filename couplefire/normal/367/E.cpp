#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=330;
const int Mod=1e9+7;
int dp[maxn][maxn][2];
int main()
{
    int N,M,X;
    scanf("%d%d%d",&N,&M,&X);
    if(N>M) return puts("0"),0;
    dp[0][0][0]=1;
    rep(k,1,M){//
      rep(i,0,min(N,M)){ //
        rep(j,0,i){ //
            int p=k&1;
            if(k==X){
                dp[i][j][p]=0;
                if(i>j) (dp[i][j][p]+=dp[i-1][j][p^1])%=Mod; //
                if(i&&j) (dp[i][j][p]+=dp[i-1][j-1][p^1])%=Mod;//+
            }
            else {
                dp[i][j][p]=dp[i][j][p^1]; //
                if(i>j) (dp[i][j][p]+=dp[i-1][j][p^1])%=Mod; //
                if(i&&j) (dp[i][j][p]+=dp[i-1][j-1][p^1])%=Mod;//+
                if(j) (dp[i][j][p]+=dp[i][j-1][p^1])%=Mod;//
            }
        }
      }
    }
    rep(i,1,N) dp[N][N][M&1]=1LL*dp[N][N][M&1]*i%Mod;
    printf("%d\n",dp[N][N][M&1]);
    return 0;
}