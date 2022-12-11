#include <cstdio>
#include <algorithm>
typedef long long int64;
static const int MAXM = 1004;
static const int MAXB = 10005;

int m, b;

inline int64 calc(int64 w, int64 h)
{
    int64 row = w * (w + 1) / 2;
    int64 ans = row * (h + 1) + h * (h + 1) / 2 * (w + 1);
    return ans;
}

int main()
{
    scanf("%d%d", &m, &b);

    int64 ans = 0;
    for (int i = 0; i <= b * m; ++i) {
        ans = std::max(ans, calc(i, (b * m - i) / m));
    }
    printf("%I64d\n", ans);

    return 0;
}