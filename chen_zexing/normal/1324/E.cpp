#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string.h>
#include <limits.h>
using namespace std;
int dp[2005][2005],a[2005];
int main() {
    int n,h,l,r;
    scanf("%d%d%d%d",&n,&h,&l,&r);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=0;i<=n;i++)
        for(int j=0;j<h;j++)
            dp[i][j]=INT_MIN;
    dp[0][0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<h;j++)
        {
            if((j+a[i+1])%h>=l&&(j+a[i+1])%h<=r)
                dp[i+1][(j+a[i+1])%h]=max(dp[i+1][(j+a[i+1])%h],dp[i][j]+1);
            else
                dp[i+1][(j+a[i+1])%h]=max(dp[i+1][(j+a[i+1])%h],dp[i][j]);
            if((j+a[i+1]-1)%h>=l&&(j+a[i+1]-1)%h<=r)
                dp[i+1][(j+a[i+1]-1)%h]=max(dp[i+1][(j+a[i+1]-1)%h],dp[i][j]+1);
            else
                dp[i+1][(j+a[i+1]-1)%h]=max(dp[i+1][(j+a[i+1]-1)%h],dp[i][j]);
        }
    }
    int ans=0;
    for(int i=0;i<h;i++) ans=max(ans,dp[n][i]);
    printf("%d\n",ans);
    return 0;
}