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
#define MOD 1000000007
using namespace std;
int a[10];
int res,C[111][111];
long long dp[10][101];
int main(){
    int i,j,k,l,n,sum=0;
    cin>>n;
    for(i=0;i<111;i++){
        C[i][0]=1;
        for(j=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
    }
    for(i=0;i<10;i++)cin>>a[i];
    for(i=0;i<10;i++)sum+=a[i];
    for(i=1;i<=n;i++){
        if(i<sum)continue;
        memset(dp,0,sizeof(dp));
        for(j=a[0];j<=i;j++)dp[0][j]=C[i][j];
        for(j=1;j<10;j++){
            for(k=0;k<=i;k++)
                for(l=a[j];k+l<=i;l++){
                    dp[j][k+l]+=dp[j-1][k]*C[i-k][l]%MOD;
                    if(dp[j][k+l]>=MOD)dp[j][k+l]-=MOD;
                }
        }
        res+=dp[9][i];
        if(res>=MOD)res-=MOD;

        memset(dp,0,sizeof(dp));
        for(j=a[0];j<=i;j++){
            if(j==0)dp[0][j]=0;
            dp[0][j]=C[i-1][j-1];
        }
        for(j=1;j<10;j++){
            for(k=0;k<=i;k++)
                for(l=a[j];k+l<=i;l++){
                    dp[j][k+l]+=dp[j-1][k]*C[i-k][l]%MOD;
                    if(dp[j][k+l]>=MOD)dp[j][k+l]-=MOD;
                }
        }
        res-=dp[9][i];
        if(res<0)res+=MOD;
    }
    cout<<res<<endl;
    return 0;
}