#include <cstdio>
static const int MAXN = 200006;
static const int INF = 0x7fffffff;

int n;
int c[MAXN], d[MAXN];
int start_min = -INF, start_max = INF;
int tot = 0;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &c[i], &d[i]);
        if (d[i] == 1) {
            if (start_min < 1900 - tot) start_min = 1900 - tot;
        } else {
            if (start_max > 1899 - tot) start_max = 1899 - tot;
        }
        tot += c[i];
    }
    if (start_min > start_max) puts("Impossible");
    else if (start_max == INF) puts("Infinity");
    else printf("%d\n", start_max + tot);
    return 0;
}