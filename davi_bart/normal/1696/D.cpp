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
    int N;
    cin >> N;
    vector<int> v;
    vector<int> mi(N, N), ma(N, N);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.pb(a);
    }
    vector<pair<int, int> > m;
    m.pb({0, N});
    for (int i = N - 1; i >= 0; i--) {
        while (m.size() && m.back().fi > v[i]) m.pop_back();
        mi[i] = m.back().se;
        m.pb({v[i], i});
    }
    vector<pair<int, int> > M;
    M.pb({N + 2, N});
    for (int i = N - 1; i >= 0; i--) {
        while (M.size() && M.back().fi < v[i]) M.pop_back();
        ma[i] = M.back().se;
        M.pb({v[i], i});
    }
    int tot = 0;
    int pos = 0;
    while (pos < N - 1) {
        tot++;
        int next_mi = mi[pos];
        int next_ma = ma[pos];
        int ans = pos + 1;
        if (next_mi > next_ma) {
            int k = pos;
            while (ma[k] < mi[pos]) {
                k = ma[k];
            }
            ans = k;
        } else {
            int k = pos;
            while (mi[k] < ma[pos]) {
                k = mi[k];
            }
            ans = k;
        }
        pos = ans;
    }
    cout << tot << '\n';
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
}