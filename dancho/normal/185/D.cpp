#include <cstdio>
#include <cstring>

long long qpow(long long v, long long st, long long mod) {
    long long r = 1;
    while (st) {
        if (st & 1) {
            r *= v;
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

long long get(long long k, long long l, long long p) {
    if (l == -1) {
        return 1;
    }
    if (p == 2) {
        return 1 - (k % 2);
    }
    return ((qpow(k, qpow(2, l + 1, p - 1), p) + p - 1) * qpow(k - 1, p - 2, p)) % p;
}

int main() {
    long long k, l, r, p;
    int t, T;
    scanf("%d", &T);
    for (t = 0; t < T; ++t) {
        scanf("%lld %lld %lld %lld", &k, &l, &r, &p);
        long long res = -1;
        if (p == 2) {
            printf("%lld\n", 1 - (k % 2));
            continue;
        }
        if (k % p == 0) {
            res = 1;
        } else if (k % p == 1) {
            res = qpow(2, r - l + 1, p);
        } else {
            long long nk = qpow(k, qpow(2, l, p - 1), p);
            if (nk % p == 1) {
                res = qpow(2, r - l + 1, p);
            } else {
                res = get(nk, r - l, p);
            }
        }
        if (k % 2) {
            res = res * qpow(qpow(2, r - l, p), p - 2, p);
            if (res >= p) {
                res %= p;
            }
        }
        printf("%lld\n", res);
    }
    return 0;
}