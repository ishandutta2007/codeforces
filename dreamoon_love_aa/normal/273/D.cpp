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
long long dp[151][4][152][152],sum[4][152][152];
int main(){
    int i,j,k,n,m;
    long long res=0;
    cin>>m>>n;
    for(k=1;k<=m;k++){
        for(i=1;i<=n;i++)
            for(j=i;j<=n;j++)dp[k][0][i][j]++;
        memset(sum,0,sizeof(sum));
        for(int r=0;r<4;r++){
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++){
                    sum[r][i][j]=sum[r][i-1][j]+sum[r][i][j-1]-sum[r][i-1][j-1]+dp[k-1][r][i][j];
                    sum[r][i][j]%=MOD;
                    if(sum[r][i][j]<0)sum[r][i][j]+=MOD;
                }
        }
        //0
        for(i=1;i<=n;i++)
            for(j=i;j<=n;j++){
                dp[k][0][i][j]+=sum[0][j][j]+sum[0][i-1][i-1]-sum[0][i-1][j]-sum[0][j][i-1];
                dp[k][0][i][j]%=MOD;
                if(dp[k][0][i][j]<0)dp[k][0][i][j]+=MOD;
            }
        //1
        for(i=1;i<=n;i++)
            for(j=i;j<=n;j++){
                dp[k][1][i][j]+=sum[1][i][j]+sum[1][0][i-1]-sum[1][0][j]-sum[1][i][i-1];
                dp[k][1][i][j]+=sum[0][i-1][j]+sum[0][0][i-1]-sum[0][0][j]-sum[0][i-1][i-1];
                dp[k][1][i][j]%=MOD;
                if(dp[k][1][i][j]<0)dp[k][1][i][j]+=MOD;
            }
        //2
        for(i=1;i<=n;i++)
            for(j=i;j<=n;j++){
                dp[k][2][i][j]+=sum[2][j][n]+sum[2][i-1][j-1]-sum[2][i-1][n]-sum[2][j][j-1];
                dp[k][2][i][j]+=sum[0][j][n]+sum[0][i-1][j]-sum[0][i-1][n]-sum[0][j][j];
                dp[k][2][i][j]%=MOD;
                if(dp[k][2][i][j]<0)dp[k][2][i][j]+=MOD;
            }
        //3
        for(i=1;i<=n;i++)
            for(j=i;j<=n;j++){
                dp[k][3][i][j]+=sum[3][i][n]+sum[3][0][j-1]-sum[3][0][n]-sum[3][i][j-1];
                dp[k][3][i][j]+=sum[2][i-1][n]+sum[2][0][j-1]-sum[2][0][n]-sum[2][i-1][j-1];
                dp[k][3][i][j]+=sum[1][i][n]+sum[1][0][j]-sum[1][0][n]-sum[1][i][j];
                dp[k][3][i][j]+=sum[0][i-1][n]+sum[0][0][j]-sum[0][0][n]-sum[0][i-1][j];
                dp[k][3][i][j]%=MOD;
                if(dp[k][3][i][j]<0)dp[k][3][i][j]+=MOD;
            }

        for(i=1;i<=n;i++)
            for(j=i;j<=n;j++)
                for(int r=0;r<4;r++)
                    res+=dp[k][r][i][j];
    }
    res%=MOD;
    cout<<res<<endl;
    return 0;
}