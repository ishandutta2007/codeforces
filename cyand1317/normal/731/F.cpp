#include <cstdio>
typedef long long int64;
static const int MAXN = 200004;
static const int MAXA = 200004;
template <typename T> inline T min(const T a, const T b) { return a < b ? a : b; }

int n, ai;
int a[MAXN] = { 0 }, s[MAXN] = { 0 };

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &ai); ++a[ai];
    }
    for (int i = 1; i < MAXA; ++i) s[i] = s[i - 1] + a[i - 1];

    int64 ans = 0, cur;
    for (int i = 1; i < MAXA; ++i) if (a[i] > 0) {
        cur = 0;
        for (int j = i; j < MAXA; j += i) {
            cur += (int64)(s[min(j + i, MAXA - 1)] - s[j]) * (j / i);
        }
        cur *= i;
        if (ans < cur) ans = cur;
    }

    printf("%I64d\n", ans);
    return 0;
}