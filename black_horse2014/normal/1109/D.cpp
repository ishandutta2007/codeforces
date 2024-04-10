#include <bits/stdc++.h>
using namespace std;

const int P = 1e9+7;
const int N = 1100000;

int f[N], g[N], r[N];

int C(int n, int m) {
    if (m < 0 || m > n) return 0;
    return 1LL * f[n] * g[m] % P * g[n-m] % P;
}

int q[N], pw[N], qw[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m, a, b; cin >> n >> m >> a >> b;
    for (int i = 0; i < N; i++) {
        f[i] = i == 0 ? 1 : f[i-1] * 1LL * i % P;
        r[i] = i < 2 ? i : r[P%i] * 1LL * (P-P/i) % P;
        g[i] = i == 0 ? 1 : g[i-1] * 1LL * r[i] % P;
    }
    for (int i = 0; i <= n; i++) pw[i] = i == 0 ? 1 : pw[i-1] * 1LL * n % P;
    for (int i = 0; i <= n; i++) qw[i] = i == 0 ? 1 : qw[i-1] * 1LL * m % P;
    for (int i = 1; i <= n; i++) q[i] = i == n ? 1 : pw[n-1-i] * 1LL * i % P;
    int ans = 0;
    for (int i = 1; i <= n-1 && i <= m; i++) {
        ans = (1LL * C(m-1, i-1) * C(n-2, i-1) % P * f[i-1] % P * q[i+1] % P * qw[n-1-i] + ans) % P;
    }
    cout << ans << endl;
    return 0;
}