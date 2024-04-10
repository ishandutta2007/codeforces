#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define ri(a) scanf("%d", &a)
#define rii(a, b) scanf("%d%d", &a, &b)
#define riii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define rs(s) scanf("%s", s)
#define pi(n) printf("%d\n", n)
#define pia(a, n) rep(_, n) printf("%d%c", a[_], _ == n - 1 ? '\n' : ' ')
#define ria(a, n) rep(_, n) scanf("%d", &a[_])
#define Ttimes int T; ri(T); for(int ks = 1; ks <= T; ++ks)
#define PB push_back
#define MP make_pair

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int maxn = 200010;
const double eps = 1e-8;
const int mod = 1000000007;
pii a[2020];
int fac[maxn], inv[maxn];
int d[2020];
int p(int x, int y) {
    if(y == 0) return 1;
    ll tmp = p(x, y >> 1);
    tmp = tmp * tmp % mod;
    if(y & 1) tmp = tmp * x % mod;
    return tmp;
}
int C(int a, int b) {
    return (1LL * fac[a + b] * inv[a] % mod) * inv[b] % mod;
}

int main() {
    fac[0] = inv[0] = 1;
    for(int i = 1; i < maxn; ++i) {
        fac[i] = 1LL * fac[i-1] * i % mod;
        inv[i] = p(fac[i], mod - 2);
        assert(1LL * fac[i] * inv[i] % mod == 1);
    }

    int n, m, k; riii(n, m, k);
    rep(i, k) {
        rii(a[i].first, a[i].second);
    }
    sort(a, a + k);
    ll all = C(n - 1, m - 1);
    rep(i, k) {
        d[i] = C(a[i].first - 1, a[i].second - 1);
        rep(j, i) if(a[j].second <= a[i].second) {
            d[i] -= 1LL * d[j] * C(a[i].first - a[j].first, a[i].second - a[j].second) % mod;
            d[i] %= mod;
            if(d[i] < 0) d[i] += mod;
        }
        all -= 1LL * d[i] * C(n - a[i].first, m - a[i].second);
        all = all % mod;
        if(all < 0) all += mod;
    }
    pi((int)all);
    return 0;
}