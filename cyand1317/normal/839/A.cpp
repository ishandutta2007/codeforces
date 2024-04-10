#include <cstdio>
#include <algorithm>
static const int MAXN = 102;
static const int MAXA = 10003;

int n, k;
int a[MAXN];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    int i, has = 0, given = 0;
    for (i = 0; i < n; ++i) {
        has += a[i];
        given += std::min(has, 8);
        has -= std::min(has, 8);
        if (given >= k) break;
    }

    if (given < k) puts("-1"); else printf("%d\n", i + 1);

    return 0;
}