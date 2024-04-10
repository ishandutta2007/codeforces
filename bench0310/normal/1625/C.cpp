#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,l,k;
    cin >> n >> l >> k;
    vector<int> x(n+1,0);
    for(int i=0;i<n;i++) cin >> x[i];
    x[n]=l;
    vector<int> a(n+1,0);
    for(int i=0;i<n;i++) cin >> a[i];
    const int inf=(1<<30);
    vector dp(n+1,vector(k+1,int(inf)));
    dp[0][0]=0;
    auto chmin=[&](int &u,int v){u=min(u,v);};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            for(int ni=i+1;ni<=n;ni++)
            {
                int rm=ni-i-1;
                if(j+rm>k) continue;
                chmin(dp[ni][j+rm],dp[i][j]+(x[ni]-x[i])*a[i]);
            }
        }
    }
    int res=inf;
    for(int i=0;i<=k;i++) chmin(res,dp[n][i]);
    cout << res << "\n";
    return 0;
}