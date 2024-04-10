#include <bits/stdc++.h>

using namespace std;

#define llong long long
#define ve vector
#define vi ve<int>
#define sz(v) ((int)v.size())
#define ii pair<int, int>
#define xx first
#define yy second
#define inf(t) numeric_limits<t>::max()
#define rep(i,n) for (int i = -1; ++i < n; )

// because I use __builtin_popcount to count long long number to much time :|
#define bitcnt(t) __builtin_popcountll(t)

namespace sol {

int n, m;
vi c[27], p, a, b;
int main() {
    cin >> n;
    p.resize(n); a.resize(n); b.resize(n);
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> a[i], a[i] --;
    rep(i, n) cin >> b[i], b[i] --;
    rep(i, n) c[a[i] * 3 + b[i]].push_back(p[i]);
    rep(i, 27) sort(c[i].rbegin(), c[i].rend());
    cin >> m;
    while (m--) {
        int t; cin >> t; t--;
        int x = -1;
        rep(i, 3) {
            if (sz(c[t * 3 + i]) and (x == -1 or c[t * 3 + i].back() < c[x].back())) x = t * 3 + i;
            if (sz(c[i * 3 + t]) and (x == -1 or c[i * 3 + t].back() < c[x].back())) x = i * 3 + t;
        }
        if (x == -1) cout << -1 << ' ';
        else {
            cout << c[x].back() << ' ';
            c[x].pop_back();
        }
    }

    return 0;
} }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //int t; cin >> t;
    //while (t--)
    sol::main();
    return 0;
}