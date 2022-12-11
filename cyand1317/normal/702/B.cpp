#include <cstdio>
#include <map>
static const int MAXN = 1e5 + 5;

int n, a[MAXN];
std::map<int, int> m;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= 30; ++j) ans += m[(1 << j) - a[i]];
        ++m[a[i]];
    }

    printf("%I64d\n", ans);
    return 0;
}