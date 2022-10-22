#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 998244353;

ll a[100002];

void solve()
{
    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];

    vector<pair<ll, ll>> v;
    v.push_back({a[n], 1});

    ll ans = 0;
    for(int i=n-1;i>=1;i--)
    {
        vector<pair<ll, ll>> nxt;
        nxt.push_back({a[i], 1});
        int m = v.size();
        for(int j=0;j<m;j++)
        {
            ll x = v[j].first, y = v[j].second;
            ll k = (a[i] - 1) / x;
            ans += k * y * i;
            ans %= mod;
            ll tmp = a[i] / (k+1);
            int s = nxt.size() - 1;
            if(nxt[s].first == tmp) nxt[s].second += y;
            else nxt.push_back({tmp, y});
        }
        v = nxt;
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}