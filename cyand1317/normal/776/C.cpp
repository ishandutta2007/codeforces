#include <cstdio>
#include <map>
typedef long long int64;
static const int MAXN = 1e5 + 4;

int n, k, a[MAXN];
std::map<int64, int> m;
int64 p[64];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    int powers = 0; p[0] = 1;
    if (k == 1) {
        // Pass
    } else if (k == -1) {
        p[++powers] = -1;
    } else {
        for (; p[powers] <= 1e15; ++powers) p[powers + 1] = p[powers] * k;
    }

    int64 ans = 0, sum = 0;
    m[0] = 1;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        for (int j = 0; j <= powers; ++j) ans += m[sum - p[j]];
        ++m[sum];
    }

    printf("%I64d\n", ans);
    return 0;
}