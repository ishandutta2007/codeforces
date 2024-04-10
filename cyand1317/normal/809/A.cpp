#include <cstdio>
#include <algorithm>
typedef long long int64;
static const int MAXN = 3e5 + 2;
static const int MODULUS = 1e9 + 7;
#define _  %  MODULUS
#define __ %= MODULUS

int n, x[MAXN];
int pow2[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &x[i]);

    std::sort(x, x + n);
    pow2[0] = 1;
    for (int i = 1; i <= n; ++i) pow2[i] = (pow2[i - 1] + pow2[i - 1])_;
    int64 ans = 0;
    for (int i = 0; i < n; ++i) {
        (ans += (int64)x[i] * (pow2[i] - pow2[n - i - 1]))__;
    }
    printf("%I64d\n", (ans + MODULUS)_);

    return 0;
}