#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string x,y;
    cin >> x >> y;
    int n=x.size();
    int m=y.size();
    x="$"+x;
    y="$"+y;
    ll dp[n+1][m+1][26];
    for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) for(int k=0;k<26;k++) dp[i][j][k]=0;
    for(int i=1;i<=n;i++) dp[i][0][x[i]-'a']++;
    for(int j=1;j<=m;j++) dp[0][j][y[j]-'a']++;
    const ll mod=998244353;
    auto add=[&](ll &a,ll b){a=(a+b)%mod;};
    ll res=0;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            for(int k=0;k<26;k++)
            {
                if(i==0)
                {
                    for(int t=1;t<=n;t++)
                    {
                        if(x[t]!=(k+'a')) add(dp[t][j][x[t]-'a'],dp[i][j][k]);
                    }
                }
                if(j==0)
                {
                    for(int t=1;t<=m;t++)
                    {
                        if(y[t]!=(k+'a')) add(dp[i][t][y[t]-'a'],dp[i][j][k]);
                    }
                }
                if(0<i&&i<n&&x[i+1]!=(k+'a')) add(dp[i+1][j][x[i+1]-'a'],dp[i][j][k]);
                if(0<j&&j<m&&y[j+1]!=(k+'a')) add(dp[i][j+1][y[j+1]-'a'],dp[i][j][k]);
                if(i>0&&j>0) add(res,dp[i][j][k]);
            }
        }
    }
    cout << res << "\n";
    return 0;
}