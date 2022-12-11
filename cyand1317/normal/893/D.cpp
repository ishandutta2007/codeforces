#include <cstdio>

static const int MAXN = 1e5 + 4;

static int n, d;
static int a[MAXN];

int main()
{
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    int c = 0, u = 0;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            if (c < 0) c = 0;
            if (u < 0) { u = d; ++ans; }
        } else {
            c += a[i];
            u += a[i];
            if (c > d) { puts("-1"); return 0; }
            if (u > d) u = d;
        }
    }

    printf("%d\n", ans);

    return 0;
}