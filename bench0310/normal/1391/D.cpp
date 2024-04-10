#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int inf=(1<<30);
    int n,m;
    cin >> n >> m;
    vector<string> v(n);
    for(int o=0;o<n;o++) cin >> v[o];
    if(n>=4)
    {
        cout << "-1\n";
        return 0;
    }
    if(n==1)
    {
        cout << "0\n";
        return 0;
    }
    vector<vector<int>> dp(m+1,vector<int>((1<<n),inf));
    for(int i=0;i<(1<<n);i++) dp[0][i]=0;
    for(int o=0;o<n;o++) v[o]="$"+v[o];
    auto cnt=[&](int x,int a)->int
    {
        int c=0;
        for(int o=0;o<n;o++) c+=((v[o][x]-'0')!=((a>>o)&1));
        return c;
    };
    for(int i=1;i<=m;i++)
    {
        for(int a=0;a<(1<<n);a++)
        {
            for(int b=0;b<(1<<n);b++)
            {
                bool ok=1;
                for(int x=0;x<n-1;x++)
                {
                    int c=((a>>x)&1)+((b>>x)&1)+((a>>(x+1))&1)+((b>>(x+1))&1);
                    ok&=(c&1);
                }
                if(ok) dp[i][b]=min(dp[i][b],dp[i-1][a]+cnt(i,b));
            }
        }
    }
    int res=inf;
    for(int a=0;a<(1<<n);a++) res=min(res,dp[m][a]);
    cout << res << "\n";
    return 0;
}