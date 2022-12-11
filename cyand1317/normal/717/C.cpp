#include <cstdio>
#include <algorithm>
typedef long long int64;
static const int MAXN = 100005;
static const int MODULUS = 10007;

int n;
int a[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    std::sort(a, a + n);

    int64 ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = (ans + (int64)a[i] * a[n - i - 1]) % MODULUS;
    }
    printf("%I64d\n", ans);

    return 0;
}