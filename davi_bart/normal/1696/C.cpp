#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define pb push_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int> > v;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        int cur = a, volte = 1;
        while (cur % M == 0) {
            cur /= M;
            volte *= M;
        }
        if (v.size() == 0 || v.back().fi != cur) v.pb({cur, 0});
        v.back().se += volte;
    }

    int K;
    cin >> K;
    vector<int> p;
    for (int i = 0; i < K; i++) {
        int x;
        cin >> x;
        p.pb(x);
    }
    set<int> ok;
    int cur = 1;
    for (int i = 0; i < 35; i++) {
        if (cur > 2e9) break;
        ok.insert(cur);
        cur *= M;
    }
    reverse(p.begin(), p.end());
    for (int x : p) {
        if (v.size() == 0 || x % v.back().fi) {
            cout << "NO\n";
            return;
        }
        // cout << x << endl;
        int k = x / v.back().fi;
        // cout << "K: " << k << endl;
        if (ok.count(k) && k <= v.back().se) {
            v.back().se -= k;
            while (v.size() && v.back().se == 0) v.pop_back();
        } else {
            cout << "NO\n";
            return;
        }
    }
        // for (auto [a, b] : v) cout << a << "," << b << "   ";
        // cout << endl;
    if (v.size())
        cout << "NO\n";
    else
        cout << "YES\n";
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
}