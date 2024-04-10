#include <cstdio>
#include <algorithm>
typedef long long int64;
static const int BASE = 7;

int n, m;
int dig_n = 1, dig_m = 1;
int a[BASE];

int main()
{
    scanf("%d%d", &n, &m);
    int64 pow_n = BASE, pow_m = BASE;
    while (pow_n < n) { pow_n *= BASE; ++dig_n; }
    while (pow_m < m) { pow_m *= BASE; ++dig_m; }

    for (int i = 0; i < BASE; ++i) a[i] = i;
    int ans = 0;
    do {
        pow_n = pow_m = 0;
        for (int i = 0; i < dig_n; ++i) pow_n = pow_n * BASE + a[i];
        for (int i = 0; i < dig_m; ++i) pow_m = pow_m * BASE + a[i + dig_n];
        if (pow_n < n && pow_m < m) ++ans;
    } while (std::next_permutation(a, a + BASE));

    for (int i = 0; i < BASE - dig_n - dig_m; ++i) ans /= (i + 1);
    printf("%d\n", ans);
    return 0;
}