#include <stdio.h>
#define MAXN 300004
#define max(__a, __b) ((__a) > (__b) ? (__a) : (__b))
#define min(__a, __b) ((__a) < (__b) ? (__a) : (__b))

int n, g[MAXN];
int _max[MAXN], _min[MAXN], ct[2 * MAXN] = {0};
#define lmax _max
#define rmax _max
#define lmin _min
#define rmin _min
long long ans = 0;

void solve(int l, int r)
{
    // Divide and conquer!
    if (l == r) { ans++; return; }

    int m = (l + r) >> 1, i;
    lmax[m] = lmin[m] = g[m];
    rmax[m + 1] = rmin[m + 1] = g[m + 1];
    for (i = m + 2; i <= r; i++) {
        rmax[i] = max(rmax[i - 1], g[i]);
        rmin[i] = min(rmin[i - 1], g[i]);
    }
    for (i = m - 1; i >= l; i--) {
        lmax[i] = max(lmax[i + 1], g[i]);
        lmin[i] = min(lmin[i + 1], g[i]);
    }

    // For detailed explanations see the official editorial.
    // Case 1: max. in L, min. in L
    for (i = l; i < m; i++) {
        int end = i + lmax[i] - lmin[i];
        if (end > m && end <= r && rmax[end] < lmax[i] && rmin[end] > lmin[i]) ans++;
    }
    // Case 2: max. in R, min. in R
    for (i = r; i > m + 1; i--) {
        int begin = i - rmax[i] + rmin[i];
        if (begin <= m && begin >= l && lmax[begin] < rmax[i] && lmin[begin] > rmin[i]) ans++;
    }
    // Case 3: max. in L, min. in R
    // Rmin[x] < Lmin[y], Rmax[x] < Lmax[y]
    // Rmin[x] + x = Lmax[y] + y
    int ymax = m, ymin = m;
    for (i = m + 1; i <= r; i++) {
        while (ymin >= l && rmin[i] < lmin[ymin]) {
            ct[lmax[ymin] + ymin]++; ymin--;
        }
        while (ymax > ymin && rmax[i] > lmax[ymax]) {
            ct[lmax[ymax] + ymax]--; ymax--;
        }
        ans += ct[rmin[i] + i];
    }
    for (i = l; i <= m; i++) ct[lmax[i] + i] = 0;
    // Case 4: max. in R, min. in L
    // Lmin[x] < Rmin[y], Lmax[x] < Rmax[y]
    // Lmin[x] - x = Rmax[y] - y
    ymax = ymin = m + 1;
    for (i = m; i >= l; i--) {
        while (ymax <= r && lmin[i] < rmin[ymax]) {
            ct[rmax[ymax] - ymax + MAXN]++; ymax++;
        }
        while (ymin < ymax && lmax[i] > rmax[ymin]) {
            ct[rmax[ymin] - ymin + MAXN]--; ymin++;
        }
        ans += ct[rmin[i] - i + MAXN];
    }
    for (i = m + 1; i <= r; i++) ct[lmax[i] - i + MAXN] = 0;

    solve(l, m); solve(m + 1, r);
}

int main()
{
    int i, r, c;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d%d", &r, &c);
        g[r - 1] = c - 1;
    }

    solve(0, n - 1);
    printf("%I64d\n", ans);

    return 0;
}