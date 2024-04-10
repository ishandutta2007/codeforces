#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, q=0;
    string s;
    cin>>n>>s>>m;
    int pref[n+1][2], dp[n+1][2], ty=(m-1)%2;
    pref[0][0]=0, pref[0][1]=0, dp[0][0]=0, dp[0][1]=0;
    for(int a=1; a<=n; a++)
    {
        pref[a][0]=0, pref[a][1]=0;
        if(s[a-1]=='a' or s[a-1]=='?')
        {
            pref[a][0]=1+pref[a-1][1];
        }
        if(s[a-1]=='b' or s[a-1]=='?')
        {
            pref[a][1]=1+pref[a-1][0];
        }
        if(s[a-1]=='?') q++;
        if(a-1-m>=0)
        {
            if(s[a-1-m]=='?') q--;
        }
        dp[a][0]=0, dp[a][1]=0;
        if(pref[a][ty]>=m)
        {
            dp[a][0]=1+dp[a-m][0];
            dp[a][1]=q+dp[a-m][1];
        }
        if(dp[a][0]<dp[a-1][0])
        {
            dp[a][0]=dp[a-1][0];
            dp[a][1]=dp[a-1][1];
        }
        else if(dp[a][0]==dp[a-1][0])
        {
            if(dp[a][1]>dp[a-1][1])
            {
                dp[a][0]=dp[a-1][0];
                dp[a][1]=dp[a-1][1];
            }
        }
    }
    cout<<dp[n][1];
}