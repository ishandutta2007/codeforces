#include <bits/stdc++.h>

using namespace std;

#define fn "main"
#define long long long
#define ve vector
#define vi ve<int>
#define xx first
#define yy second
#define sz(v) ((int) v.size())
#define inf(type) (numeric_limits<type>::max())
#define ii pair<int, int>
#define sz(v) ((int) v.size())
#define ll pair<long, long>

#define mod ((long) 1e9 + 7)

#define m1 mod
#define m2 ((long) 1e9 + 8181)

struct pp {
    ve<ll> dd;
    pp() : dd(1,ll(1, 1)) {}
    ll operator[](int i) {
        while (sz(dd) <= i) dd.push_back(ll(
            (dd.back().xx * 111111) % m1,
            (dd.back().yy * 111111) % m2
        ));
        return dd[i];
    }
} pp;

struct fac {
    ve<long> dd;
    fac() : dd(1, 1) {}
    long operator[](int i) {
        while (sz(dd) <= i) dd.push_back((dd.back() * sz(dd)) % mod);
        return dd[i];
    }
} fac;

int n, m;
ve<ll> hs;
vi lastnotcmp;
void solve() {
    cin >> n >> m;
    hs.resize(m, ll(1, 1));
    lastnotcmp.resize(m, -1);
    for (int i = 0; i < n; ++i) {
        int g; cin >> g;
        for (int f = 0; f < g; ++f) {
            int t; cin >> t; --t;
            ll b = pp[i - lastnotcmp[t]];
            hs[t].xx = ((hs[t].xx * b.xx) % m1 + 1) % m1;
            hs[t].yy = ((hs[t].yy * b.yy) % m2 + 1) % m2;
            lastnotcmp[t] = i;
        }
    }
    sort(hs.begin(), hs.end());
    int c = 1;
    long ans = 1;
    for (int i = 1; i < m; ++i) {
        if (hs[i] == hs[i - 1]) ++c;
        else ans = (ans * fac[c]) % mod, c = 1;
    }
    ans = (ans * fac[c]) % mod;
    cout << ans;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();

    return 0;
}