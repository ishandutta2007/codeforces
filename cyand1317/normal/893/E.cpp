#include <cstdio>

typedef long long int64;

static const int MAXX = 2e6 + 5;
static const int MAXP = MAXX / 10;
static const int MODULUS = 1e9 + 7;
#define _  %  MODULUS
#define __ %= MODULUS

static int not_prime[MAXX] = { false };
static int primes[MAXP], prime_ct = 0;
static int min_p[MAXX];

inline void sieve()
{
    not_prime[0] = not_prime[1] = true;
    min_p[0] = min_p[1] = -1;
    for (int i = 2; i < MAXX; ++i) {
        if (!not_prime[i]) { primes[prime_ct++] = i; min_p[i] = i; }
        for (int j = 0; j < prime_ct && i * primes[j] < MAXX; ++j) {
            if (!not_prime[i * primes[j]]) {
                not_prime[i * primes[j]] = true;
                min_p[i * primes[j]] = primes[j];
            }
            if (i % primes[j] == 0) break;
        }
    }
    //printf("%d\n", prime_ct);
    //for (int i = 2; i < 25; ++i) printf("%d | min_p=%d\n", i, primes[min_p[i]]);
}

static int64 fact[MAXX], fact_inv[MAXX];

inline int64 qpow(int64 base, int exp)
{
    int64 ans = 1;
    for (; exp; exp >>= 1, (base *= base)__) if (exp & 1) (ans *= base)__;
    return ans;
}

inline void calc_factorials()
{
    fact[0] = 1;
    for (int i = 1; i < MAXX; ++i) fact[i] = fact[i - 1] * i _;
    fact_inv[MAXX - 1] = qpow(fact[MAXX - 1], MODULUS - 2);
    for (int i = MAXX - 2; i >= 0; --i) fact_inv[i] = fact_inv[i + 1] * (i + 1)_;
}

inline int64 binom(int n, int m)
{
    if (n < m || m < 0) return 0;
    return fact[n] * fact_inv[m]_ * fact_inv[n - m]_;
}

int main()
{
    sieve();
    calc_factorials();

    int T;
    scanf("%d", &T);

    do {
        int x, y;
        scanf("%d%d", &x, &y);

        int64 ans = 1;
        // Factorize x
        int p = -1, count = 0;
        while (x != 1) {
            if (min_p[x] != p) {
                (ans *= binom(count + y - 1, y - 1))__;
                p = min_p[x];
                count = 1;
            } else {
                ++count;
            }
            x /= p;
        }
        (ans *= binom(count + y - 1, y - 1))__;
        (ans *= qpow(2, y - 1))__;
        printf("%I64d\n", ans);
    } while (--T);

    return 0;
}