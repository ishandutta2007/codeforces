#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <set>
#include <cmath>
#include <map>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b, ll& c, ll& d) {
    if (b == 0) {
        c = 1;
        d = 0;
        return a;
    }
    ll c1, d1;
    c = 1;
    d = -(a / b);
    ll ans = gcd(b, a % b, c1, d1);
    c *= d1;
    d = d * d1 + c1;
    return ans;
}

void solve() {
    ll a, b, c, d;
    ll n, m;
    cin >> m >> n;
    vector<vector<ll> > md(n + 1);
    vector<ll> dp(n + 1);
    vector<ll> pr(n + 1);
    vector<ll> pd;
    set<ll> forb;
    for (ll i = 0; i < m; ++i) {
        cin >> a;
        forb.insert(a);
    }
    ll k = n;
    for (ll i = 2; i <= n; ++i) {
        if (k % i == 0)
            pd.push_back(i);
        while (k % i == 0)
            k /= i;
    }
    for (ll i = 0; i < n; ++i) {
        if (forb.find(i) == forb.end()) {
            md[gcd(n, i, c, d)].push_back(i);
        }
    }
    for (ll i = 1; i <= n; ++i) {
        pr[i] = -1;
        dp[i] = md[i].size();
    }
    for (ll i = 1; i < n; ++i) {
        for (ll j = 0; j < pd.size(); ++j) {
            if (n % (i * pd[j]) == 0 && dp[i * pd[j]] < dp[i] + md[i * pd[j]].size()) {
                dp[i * pd[j]] = dp[i] + md[i * pd[j]].size();
                pr[i * pd[j]] = i;
            }
        }
    }
    ll mx = 0, pos = 0;
    for (ll i = 1; i <= n; ++i) {
        if (mx < dp[i]) {
            mx = dp[i];
            pos = i;
        }
    }
    if (mx == 0) {
        cout << 0 << endl;
        return;
    }
    vector<ll> path;
    while (pos != -1) {
        path.push_back(pos);
        pos = pr[pos];
    }
    vector<ll> ans;
    reverse(path.begin(), path.end());
    ll mult = 1, gd = 1;
    for (auto pos: path) {
        for (ll i = 0; i < md[pos].size(); ++i) {
            gd = gcd(n, mult, c, d);
            d *= md[pos][i] / gd;
            d = (d % n);
            if (d < 0)
                d += n;
            ans.push_back(d);
            mult = (mult * d) % n;
        }
    }
//    for (auto t: pd) {
//        cout << t << ' ';
//    }
//    cout << endl;
//    for (int i = 0; i <= n; ++i) {
//        cout << md[i].size() << ' ';
//    }
//    cout << endl;
//    for (int i = 0; i <= n; ++i) {
//        cout << i << ' ';
//    }
//    cout << endl;
//    for (int i = 0; i <= n; ++i) {
//        cout << dp[i] << ' ';
//    }
//    cout << endl;
//    for (int i = 0; i <= n; ++i) {
//        cout << pr[i] << ' ';
//    }
//    cout << endl;
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}

int main() {
    iostream::sync_with_stdio(false);
    cout.precision(20);
    solve();
}