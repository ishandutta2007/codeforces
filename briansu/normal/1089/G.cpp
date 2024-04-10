#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

const ll INF = 1e18;

void solve() {
    int k;
    cin >> k;
    vector<int> v;  
    for (int i = 0; i < 7; i++) {
        int x;
        cin >> x;
        if (x)
            v.pb(i);
    }
    assert(SZ(v));
    ll ans = INF;
    for (int i = 0; i < SZ(v); i++) {
        int t = (k - 1) / SZ(v);
        int p = k - t * SZ(v);
        assert(p > 0 && p <= SZ(v));
        int x = v[i], y = v[(i + p - 1) % SZ(v)];
        ll tt = t * 7 + (y - x + 7) % 7 + 1;
        ans = min(ans, tt);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}