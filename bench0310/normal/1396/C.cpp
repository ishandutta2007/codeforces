#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll r1,r2,r3,d;
    cin >> n >> r1 >> r2 >> r3 >> d;
    vector<ll> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<ll> dp(n+1,(1ll<<60));
    dp[0]=-d;
    auto chmin=[&](ll &x,ll y){x=min(x,y);};
    auto one=[&](int i)->ll{return (a[i]*min(r1,r3)+r3);};
    auto two=[&](int i)->ll{return min(r2,a[i]*min(r1,r3)+r1)+min({r1,r2,r3});};
    for(int i=0;i<n;i++)
    {
        chmin(dp[i+1],dp[i]+d+one(i+1));
        chmin(dp[i+1],dp[i]+3*d+two(i+1));
        if(i+2==n) chmin(dp[n],dp[i]+3*d+two(i+1)+one(i+2));
        if(i+2<=n) chmin(dp[i+2],dp[i]+4*d+two(i+1)+two(i+2));
    }
    cout << dp[n] << "\n";
    return 0;
}