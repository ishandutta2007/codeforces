#include <cstdio>
#include <cstring>

const int mod = 1000000007;

long long fac[1 << 20];
long long facin[1 << 20];

long long qpow(long long v, long long st) {
    long long r = 1;
    while (st) {
        if (st & 1) {
            r = r * v;
            if (r >= mod) {
                r %= mod;
            }
        }
        st /= 2;
        v = v * v;
        if (v >= mod) {
            v %= mod;
        }
    }
    return r;
}

long long getClean(int r, int c) {
    int n = r + c - 2;
    int m = r - 1;
    long long div = facin[m] * facin[n - m];
    if (div >= mod) {
        div %= mod;
    }
    return (div * fac[n]) % mod;
}

int h, w, n;
int x[2048], y[2048];

long long f[2048];

long long getDP(int k) {
    if (f[k] != -1) {
        return f[k];
    }
    f[k] = 0;
    for (int i = 0; i < n; ++i) {
        if (x[i] <= x[k] && y[i] <= y[k] && i != k) {
            // printf("STEP %d %d -> %d %d\n", x[k], y[k], x[i], y[i]);
            if (i == n - 2) {
                f[k] = f[k] + getDP(i) * getClean(x[k] - x[i] + 1, y[k] - y[i] + 1);
            } else {
                f[k] = f[k] - (getDP(i) * getClean(x[k] - x[i] + 1, y[k] - y[i] + 1)) % mod;
                while (f[k] <= mod) {
                    f[k] += mod;
                }
            }
            f[k] %= mod;
        }
    }
    // printf("SS %d %d : %lld\n", x[k], y[k], f[k]);
    return f[k];
}

int main() {
    scanf("%d %d %d", &h, &w, &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &x[i], &y[i]);
    }
    memset(f, -1, sizeof(f));
    x[n] = 1;
    y[n] = 1;
    f[n] = 1;
    n++;
    x[n] = h;
    y[n] = w;
    n++;
    
    fac[0] = 1;
    facin[0] = qpow(fac[0], mod - 2);
    for (int i = 1; i <= 200000; ++i) {
        fac[i] = fac[i - 1] * i;
        if (fac[i] >= mod) {
            fac[i] %= mod;
        }
        facin[i] = qpow(fac[i], mod - 2);
    }

    printf("%lld\n", getDP(n - 1));

    return 0;
}