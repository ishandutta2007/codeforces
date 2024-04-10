#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,(1ll<<60)));
    for(int sz=1;sz<=n;sz++)
    {
        ll w=n-sz+1;
        for(int i=1;i+sz-1<=n;i++)
        {
            int j=i+sz-1;
            if(sz==1) dp[i][j]=0;
            else dp[i][j]=min(dp[i+1][j]+(a[i+1]-a[i])*w,dp[i][j-1]+(a[j]-a[j-1])*w);
        }
    }
    cout << dp[1][n] << "\n";
    return 0;
}