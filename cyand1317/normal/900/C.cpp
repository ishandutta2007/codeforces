#include <cstdio>
#include <algorithm>
#include <functional>
static const int MAXN = 1e5 + 4;

static int n, p[MAXN];

static int pfx_m[MAXN], pfx_r[MAXN];
static int stk[MAXN], top = 0;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &p[i]);

    pfx_m[0] = p[0];
    pfx_r[0] = 1;
    for (int i = 1; i < n; ++i) {
        pfx_m[i] = ((p[i] > pfx_m[i - 1]) ? p[i] : pfx_m[i - 1]);
        pfx_r[i] = ((p[i] > pfx_m[i - 1]) ? 1 : 0) + pfx_r[i - 1];
    }

    int ans = -1, rm = n + 1;
    for (int i = n - 1; i >= 0; --i) {
        int cur = (i > 0 ? pfx_r[i - 1] : 0) +
            std::distance(stk,
                std::lower_bound(stk, stk + top, (i > 0 ? pfx_m[i - 1] : 0), std::greater<int>())
            );
        if (ans < cur || (ans == cur && rm > p[i])) { ans = cur; rm = p[i]; }
        while (top > 0 && stk[top - 1] < p[i]) --top;
        stk[top++] = p[i];
    }

    printf("%d\n", rm);
    return 0;
}