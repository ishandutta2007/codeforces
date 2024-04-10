#include <stdint.h>
#include <stdio.h>

#define MODULUS 1000000007
#define _       % MODULUS

#define MAX_RG  76543
#define MAX_PR  7654

int prime_ct = 0, primes[MAX_PR];
unsigned char not_prime[MAX_RG] = { 0 };

void sieve()
{
    int i, j;
    not_prime[0] = not_prime[1] = 1;
    for (i = 2; i < MAX_RG; ++i) {
        if (!not_prime[i]) primes[prime_ct++] = i;
        for (j = 0; j < prime_ct && i * primes[j] < MAX_RG; ++j)
            not_prime[i * primes[j]] = 1;
    }
}

int mu(int n)
{
    int i, ret = 1;
    for (i = 0; i < prime_ct; ++i) {
        if (n % primes[i] == 0) {
            n /= primes[i];
            ret = -ret;
            if (n % primes[i] == 0) return 0;
        }
    }
    if (n > 1) ret = -ret;
    return ret;
}

int qpow(int base, int exp)
{
    int ans = 1;
    for (; exp; exp >>= 1, base = ((int64_t)base * base)_)
        if (exp & 1) ans = ((int64_t)ans * base)_;
    return ans;
}

int count_seqs(int sum, int gcd_mul)
{
    if (sum % gcd_mul != 0) return 0;
    return qpow(2, sum / gcd_mul - 1);
}

int main()
{
    int x, y;
    scanf("%d%d", &x, &y);

    if (y % x != 0) { puts("0"); return 0; }
    y /= x;

    sieve();

    int64_t ans = 0;
    int i;
    for (i = 1; i * i <= y; ++i) if (y % i == 0) {
        ans += count_seqs(y, i) * mu(i);
        if (i * i != y)
            ans += count_seqs(y, y / i) * mu(y / i);
    }

    printf("%I64d\n", (ans _ + MODULUS)_);

    return 0;
}