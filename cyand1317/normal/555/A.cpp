#include <cstdio>
static const int MAXN = 1e5 + 3;

int n, k;
int m, a[MAXN];
int ans;

int main()
{
    scanf("%d%d", &n, &k);
    ans = n - 1;
    for (int i = 0; i < k; ++i) {
        scanf("%d", &m);
        ans += (m - 1);
        for (int j = 0; j < m; ++j) scanf("%d", &a[j]);
        if (a[0] == 1) {
            for (int j = 1; j < m && a[j] == j + 1; ++j) ans -= 2;
        }
    }

    printf("%d\n", ans);
    return 0;
}