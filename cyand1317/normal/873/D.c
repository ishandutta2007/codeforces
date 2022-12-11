#include <stdio.h>
#define MAXN    100003

int n, k;
int a[MAXN];

void dfs(int l, int r, int nl, int nr)
{
    if (l == r - 1) {
        a[l] = nl;
    } else if (k == 0) {
        for (; l < r; ++l, ++nl) a[l] = nl;
    } else {
        --k;
        int m = (l + r) / 2;
        dfs(l, m, nr - (m - l), nr);
        dfs(m, r, nl, nr - (m - l));
    }
}

int main()
{
    scanf("%d%d", &n, &k);
    if (k % 2 == 0 || k >= n * 2) {
        puts("-1"); return 0;
    }

    k /= 2;
    dfs(0, n, 1, n + 1);
    int i;
    for (i = 0; i < n; ++i) printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');

    return 0;
}