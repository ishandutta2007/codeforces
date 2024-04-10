#include <stdio.h>
#define MAXN 2002

int n, x, t[MAXN], h[MAXN], m[MAXN];

int work(int type)
{
    int max, maxidx, i, ablt = x, ans = 0;
    int b[MAXN] = {0};
    do {
        max = -1;
        for (i = 0; i < n; ++i) {
            if (!b[i] && t[i] == type && h[i] <= ablt && m[i] > max) {
                max = m[i]; maxidx = i;
            }
        }
        if (max == -1) return ans;
        ablt += max; b[maxidx] = 1;
        ++ans; type = !type;
    } while (1);
}

int main()
{
    int i;
    scanf("%d%d", &n, &x);
    for (i = 0; i < n; ++i) scanf("%d%d%d", &t[i], &h[i], &m[i]);
    int ans = -1, cur;
    if ((cur = work(0)) > ans) ans = cur;
    if ((cur = work(1)) > ans) ans = cur;
    printf("%d\n", ans);
    return 0;
}