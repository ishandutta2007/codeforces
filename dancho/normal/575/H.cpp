#include <cstdio>
#include <cstring>

const int mod = 1000000007;

long long qpow(long long v, long long st) {
    long long r = 1;
    while (st) {
        if (st & 1) {
            r = r * v;
            if (r >= mod) {
                r %= mod;
            }
        }
        v = v * v;
        if (v >= mod) {
            v %= mod;
        }
        st /= 2;
    }
    return r;
}

long long fac[1 << 22];
long long ifac[1 << 22];

long long gcom(int n, int k) {
    return (((fac[n] * ifac[k]) % mod) * ifac[n - k]) % mod;
}

int n;

int main() {
    scanf("%d", &n);

    fac[0] = 1;
    ifac[0] = 1;
    for (int i = 1; i <= 2 * n; ++i) {
        fac[i] = (fac[i - 1] * i) % mod;
        ifac[i] = qpow(fac[i], mod - 2);
    }

    long long res = 0;
    long long p2 = 1;
    long long rm = 0;
    for (int st = 0; st <= n; ++st) {
        res += p2;
        res %= mod;
        if (st < n) {
            p2 = (p2 * 2) % mod;
        }
    }
    long long prm = 0;
    for (int i = 0; i < n; ++i) {
        rm = (2LL * gcom(n + i, i)) % mod;
        // Total # dead.
        long long ned = (rm - prm + mod) % mod;
        p2 = (p2 - ned + mod) % mod;
        p2 = (p2 * 2) % mod;
        res = (res + rm + p2) % mod;
        prm = rm;
    }

    printf("%lld\n", res);
    return 0;
}