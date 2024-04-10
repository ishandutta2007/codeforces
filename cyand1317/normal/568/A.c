#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAXN 1200008

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

unsigned char is_prime[MAXN];
unsigned char is_palin[MAXN];
int pi[MAXN], rub[MAXN];

void calc_primes()
{
    int i, j, upbound = sqrt(MAXN);
    memset(is_prime, TRUE, sizeof(is_prime));
    is_prime[0] = is_prime[1] = 0;
    for (i = 2; i <= upbound; ++i) if (is_prime[i]) {
        j = i + i;
        while (j < MAXN) {
            is_prime[j] = FALSE;
            j += i;
        }
    }
    pi[0] = 0;
    for (i = 1; i < MAXN; ++i) pi[i] = pi[i - 1] + is_prime[i];
}

void calc_palins()
{
    int i, t, r;
    for (i = 0; i < MAXN; ++i) {
        t = i, r = 0;
        while (t) { r = r * 10 + t % 10; t /= 10; }
        is_palin[i] = (r == i);
    }
    rub[0] = 0; // Should be positive
    for (i = 1; i < MAXN; ++i) rub[i] = rub[i - 1] + is_palin[i];
}

int main()
{
    int p, q;
    scanf("%d%d", &p, &q);
    calc_primes();
    calc_palins();

    int i, ans = -1;
    for (i = 0; i < MAXN; ++i) {
        // if (pi[i] / rub[i] <= A = p / q
        if (pi[i] * q <= rub[i] * p) ans = i;
    }
    if (ans > 0) printf("%d\n", ans);
    else puts("Palindromic tree is better than splay tree");
    return 0;
}