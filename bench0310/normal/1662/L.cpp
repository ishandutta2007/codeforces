#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,v;
    cin >> n >> v;
    vector<int> t(n+1,0);
    for(int i=1;i<=n;i++) cin >> t[i];
    vector<array<ll,2>> e;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        if(ll(v)*t[i]>=abs(a)) e.push_back({-(a-ll(v)*t[i]),a+ll(v)*t[i]});
    }
    vector<ll> dp(n+1,(1ll<<60));
    dp[0]=-(1ll<<60);
    ranges::sort(e);
    int res=0;
    for(auto [x,y]:e)
    {
        int p=(ranges::upper_bound(dp,y)-dp.begin());
        dp[p]=y;
        res=max(res,p);
    }
    cout << res << "\n";
    return 0;
}