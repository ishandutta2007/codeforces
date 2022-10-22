#include <bits/stdc++.h>

const int P = 1000000007;

int qpow(int a, int b) {
    int s = 1;
    for (; b; b >>= 1) {
        if (b & 1) {
            s = 1ll * s * a % P;
        }
        a = 1ll * a * a % P;
    }
    return s;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<std::vector<int>> p(n, std::vector<int>(1 << n));
    for (int i = 0; i < n; ++i) {
        p[i][0] = 1;
        for (int j = 0; j < n; ++j) {
            p[i][1 << j] = 1ll * a[i] * qpow(a[i] + a[j], P - 2) % P;
        }
        for (int S = 1; S < (1 << n); ++S) {
            p[i][S] = 1ll * p[i][S & (S - 1)] * p[i][S & -S] % P;
        }
    }

    std::vector<int> f(1 << n);
    int all = (1 << n) - 1;
    int ans = 0;
    for (int S = 1; S < (1 << n); ++S) {
        f[S] = 1;
        for (int T = (S - 1) & S; T; T = (T - 1) & S) {
            int prod = 1;
            for (int i = 0; i < n; ++i) {
                if (T >> i & 1) {
                    prod = 1ll * prod * p[i][S ^ T] % P;
                }
            }
            f[S] = (f[S] + 1ll * (P - f[T]) * prod) % P;
        }
        int t = f[S];
        for (int i = 0; i < n; ++i) {
            if (S >> i & 1) {
                t = 1ll * t * p[i][all ^ S] % P;
            }
        }
        ans = (ans + 1ll * t * __builtin_popcount(S)) % P;
    }
    std::cout << ans << "\n";
}