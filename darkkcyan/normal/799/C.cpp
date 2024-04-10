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

// because I use __builtin_popcount to count long long number too much time :|
#define bitcnt(t) __builtin_popcountll(t)

namespace sol {


#define maxn 101010

int n, c, d;
ve<ii> a, b;

struct maxbit {
    vi d;
    void resize(int n) { d.assign(n + 1, 0); }
    void operator()(int i, int v) {for (++i; i < sz(d); i += i & -i) d[i] = max(d[i], v); }
    int operator[](int i) { int ans = 0; for (++i; i > 0; i -= i & -i) ans = max(ans, d[i]); return ans;}
} bit;

int solve1() {
    int u = 0, v = 0;
    for (auto i : a) if (i.xx <= c) u = max(u, i.yy);
    for (auto i : b) if (i.xx <= d) v = max(v, i.yy);
    //clog << u << ' ' << v << endl;
    if (u == 0 or v == 0) return 0;
    return u + v;
}

int solve2(int m, ve<ii>& a) {
    bit.resize(maxn);
    int ans = 0;
    for (auto i : a) {
        int r = bit[m - i.xx];
        if (r > 0) ans = max(ans, r + i.yy);
        bit(i.xx, i.yy);
    }
    return ans;
}

int main() {
    cin >> n >> c >> d;
    rep(i, n) {
        int u, v; char t; cin >> u >> v >> t;
        if (t == 'C') a.push_back(ii(v, u));
        else b.push_back(ii(v, u));
    }

    int ans = max(solve1(), max(solve2(c, a), solve2(d, b)));
    cout << ans;

    return 0;
} }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //int t; cin >> t;
    //while (t--)
    sol::main();
    return 0;
}