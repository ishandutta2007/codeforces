#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    int an[n+1];
    for(int a=1; a<=n; a++)
    {
        int dp[n+1][a+1];
        for(int b=1; b<=n; b++) for(int c=1; c<=a; c++) dp[b][c]=0;
        dp[1][1]=1;
        for(int b=1; b<n; b++)
        {
            for(int c=1; c<=a; c++)
            {
                dp[b+1][1]=(dp[b+1][1]+dp[b][c])%mod;
                if(c+1<=a) dp[b+1][c+1]=(dp[b+1][c+1]+dp[b][c])%mod;
            }
        }
        an[a]=0;
        for(int b=1; b<=a; b++) an[a]=(an[a]+dp[n][b])%mod;
    }
    int su=0;
    for(int a=1; a<=n; a++)
    {
        an[a]-=su;
        if(an[a]<0) an[a]+=mod;
        su=(su+an[a])%mod;
    }
    int tot=0;
    for(int a=1; a<=n; a++)
    {
        for(int b=1; b<=n; b++)
        {
            if(a*b<k) tot=(tot+2ll*an[a]*an[b])%mod;
        }
    }
    cout<<tot;
}