#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define y1 y114514
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
const int M = 1000000007;

const int maxn = 3000009;
int n, q;
ll f[maxn];
ll fac[maxn], inv[maxn], finv[maxn];

inline ll C(int n, int m) { return fac[n] * finv[m] % M * finv[n - m] % M; }

inline void add(ll& a, ll b) {
    a += b;
    if (a >= M) a -= M;
}
inline void del(ll& a, ll b) {
    a -= b;
    if (a < 0) a += M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    fac[0] = fac[1] = inv[0] = inv[1] = finv[0] = finv[1] = 1;
    for (int i = 2; i <= 3 * (n + 1); ++i) {
        fac[i] = fac[i - 1] * i % M;
        inv[i] = (M - M / i) * inv[M % i] % M;
        finv[i] = finv[i - 1] * inv[i] % M;
    }

    for (int i = 1; i <= n; ++i) {
        add(f[0], 1);
        add(f[1], C(3 * i, 1));
        add(f[2], C(3 * i, 2));
    }
    for (int i = 3; i <= 3 * n; ++i) {
        f[i] = C(3 * (n + 1), i + 1) - 3 * f[i - 1] - f[i - 2];
        // cout << "f[i]=" << f[i] << "\n";
        f[i] = (f[i] * inv[3] % M + M) % M;
        // cout << "C(3 * (n + 1), i)=" << C(3 * (n + 1), i) << "\n";
    }
    while (q--) {
        static int x;
        cin >> x;
        cout << f[x] << "\n";
    }
    return 0;
}