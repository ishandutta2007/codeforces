// (`)
#include <cstdio>
typedef long long int64;
static const int MAXN = 2e5 + 4;
static const int MODULUS = 1e9 + 7;
#define _  % MODULUS
#define __ %= MODULUS

int f, w, h;
int fact[MAXN], fact_inv[MAXN];

inline int fpow(int64 base, int exp) {
    int64 ans = 1;
    for (; exp; exp >>= 1) { if (exp & 1) (ans *= base)__; (base *= base)__; }
    return ans;
}
inline int inv(int x) { return fpow(x, MODULUS - 2); }
inline void preprocess() {
    fact[0] = fact_inv[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = (int64)fact[i - 1] * i _;
        fact_inv[i] = inv(fact[i]);
    }
}
inline int64 binom(int n, int r) {
    if (n < r || n < 0) return 0;
    else return (int64)fact[n] * fact_inv[r]_ * fact_inv[n - r]_;
}

inline int64 every(int all, int parts) {
    if (all == 0) return 1;
    else return binom(all - 1, parts - 1);
}
// Partition `all` objects into `parts` partitions
// A solution is valid iff each partition has at least h+1 objects
inline int64 count(int all, int parts) {
    int64 remains = all - (int64)parts * (h + 1);
    if (remains < 0) return 0;
    return every(remains + parts, parts);
}

int main()
{
    preprocess();
    scanf("%d%d%d", &f, &w, &h);

    int64 tot = 0, valid = 0;
    // (1) HW...HW / WH...WH
    for (int i = 1; i <= w && i <= f; ++i) {
        (tot += every(w, i) * every(f, i) * 2)__;
        (valid += count(w, i) * every(f, i) * 2)__;
    }
    // (2) WH...HW
    for (int i = !!f; i + 1 <= w && i <= f; ++i) {
        (tot += every(w, i + 1) * every(f, i))__;
        (valid += count(w, i + 1) * every(f, i))__;
    }
    // (3) HW...WH
    for (int i = !!w; i <= w && i + 1 <= f; ++i) {
        (tot += every(w, i) * every(f, i + 1))__;
        (valid += count(w, i) * every(f, i + 1))__;
    }

    //printf("%I64d %I64d\n", valid, tot);
    printf("%I64d\n", (int64)valid * inv(tot)_);
    return 0;
}