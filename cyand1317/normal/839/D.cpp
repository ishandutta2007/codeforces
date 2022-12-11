#include <cstdio>
typedef long long int64;
static const int MAXN = 200004;
static const int MAXA = 1e6 + 4;
static const int MODULUS = 1e9 + 7;
#define _  %  MODULUS
#define __ %= MODULUS

int n;
int a[MAXN];

int64 f[MAXA] = { 0 }, g[MAXA] = { 0 };

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j * j <= a[i]; ++j) if (a[i] % j == 0) {
            f[j] = (f[j] * 2 + g[j])_;
            g[j] = g[j] * 2 _;
            if (j * j != a[i]) {
                f[a[i] / j] = (f[a[i] / j] * 2 + g[a[i] / j])_;
                g[a[i] / j] = g[a[i] / j] * 2 _;
            }
        }
        for (int j = 1; j * j <= a[i]; ++j) if (a[i] % j == 0) {
            f[j] += 1; g[j] += 1;
            if (j * j != a[i]) { f[a[i] / j] += 1; g[a[i] / j] += 1; }
        }
    }

    int64 ans = 0;
    for (int i = MAXA - 1; i >= 1; --i) if (f[i]) {
        if (i != 1) (ans += f[i] * i)__;
        for (int j = 1; j * j <= i; ++j) if (i % j == 0) {
            f[j] = (f[j] - f[i] + MODULUS)_;
            if (j != 1 && j * j != i)
                f[i / j] = (f[i / j] - f[i] + MODULUS)_;
        }
    }
    printf("%I64d\n", ans);

    return 0;
}