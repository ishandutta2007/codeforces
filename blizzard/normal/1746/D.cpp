#include <bits/stdc++.h>

#ifdef LOCAL
#define err cerr
#else
#define err if (false) cerr
#endif

using namespace std;
using ll = long long;

using bs = bitset<200000>;

const int MAXN = 200000;
vector<int> e[MAXN];
vector<unordered_map<int, ll>> m(MAXN);
//map<pair<int, int>, ll> m;
vector<int> s;

ll dfs(int u, int k) {
    if (e[u].size() == 0) {
        return (ll)k * s[u];
    }
    auto it = m[u].find(k);
    if (it != m[u].end()) return it->second;
    int t = k / e[u].size();
    vector<ll> profit(e[u].size());
    int i = 0;
    ll have = 0;
    int rem = k % e[u].size();
    for (int v : e[u]) {
        ll t1 = dfs(v, t);
        if (rem != 0) {
            ll t2 = dfs(v, t + 1);
            profit[i++] = t2 - t1;
//            assert(t1 <= t2);
        }
        have += t1;
    }
    if (rem != 0) {
        auto it = profit.begin() + e[u].size() - rem;
        nth_element(profit.begin(), it, profit.end());
        for (it; it < profit.end(); it++) {
            have += *it;
        }
    }
    err << u << " " << k << " " << have << "+" << (ll)k * s[u] << endl;
    m[u][k] = have + (ll)k * s[u];
    return have + (ll)k * s[u];
}

void solve() {
    int n, k;
    cin >> n >> k;
//    m.clear();
    for (int i = 0; i < n; i++) {
        e[i].clear();
        m[i].clear();
    }
    vector<int> a(n);
    s.resize(n, 0);

    for (int i = 1; i < n; i++) {
        int x; cin >> x;
        x--;
        e[x].emplace_back(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    cout << dfs(0, k) << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}