#include <cstdio>
typedef long long int64;
template <typename T> inline T min(const T a, const T b) { return a < b ? a : b; }

int k2, k3, k5, k6;
int64 ans = 0, cur;

int main()
{
    scanf("%d%d%d%d", &k2, &k3, &k5, &k6);

    for (int i = 0; i <= k2; ++i) {
        int num32 = min(i, k3);
        int num256 = min(min(k2 - i, k5), k6);
        cur = 32LL * num32 + 256LL * num256;
        if (ans < cur) ans = cur;
    }

    printf("%I64d\n", ans);
    return 0;
}