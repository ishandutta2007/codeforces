#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
#define MOD 1000000007
#define SIZE 2001
long long dp[3][SIZE][SIZE],dp2[SIZE][SIZE];
int main(){
    int i,j,k,n,m;
    cin>>n>>m;
    for(i=2;i<=m;i++){
        dp[0][1][i]=1;
        dp[1][1][i]=dp[0][1][i]+dp[1][1][i-1];
        dp[2][1][i]=dp[1][1][i]+dp[2][1][i-1];
    }
    for(i=2;i<=n;i++){
        for(j=2;j<=m;j++){
            dp[0][i][j]=dp[2][i-1][j];
            dp[1][i][j]=dp[1][i][j-1]+dp[0][i][j];
            if(dp[1][i][j]>=MOD)dp[1][i][j]-=MOD;
            dp[2][i][j]=dp[2][i][j-1]+dp[1][i][j];
            if(dp[2][i][j]>=MOD)dp[2][i][j]-=MOD;
        }
    }
    for(j=2;j<=m;j++)for(i=1;i<=n;i++)dp2[j][i]=dp[0][i][j];
    for(j=2;j<=m;j++){
        for(i=1;i<=n;i++){
            dp2[j][i]=dp2[j][i-1]+dp2[j][i];
            if(dp2[j][i]>=MOD)dp2[j][i]-=MOD;
        }
    }
    long long res=0;
    for(i=1;i<=n;i++){
        for(j=2;j<=m;j++){
            res+=(dp2[j][i])*(dp2[j][n+1-i]-dp2[j][n-i])%MOD*(m-j+1)%MOD;
            if(res>=MOD)res-=MOD;
        }
    }
    cout<<res<<endl;

    return 0;
}