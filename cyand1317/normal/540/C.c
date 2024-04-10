#include <stdio.h>
#define MAXN 503
#define inrange(_v, _l, _h) ((_v) >= (_l) && (_v) < (_h))
#define dist_abs(_a, _b) ((_a) > (_b) ? ((_a) - (_b)) : ((_b) - (_a)))

const int drow[4] = {0, 0, -1, 1};
const int dcol[4] = {-1, 1, 0, 0};

int n, m, r1, c1, r2, c2;
char g[MAXN][MAXN];

int adj_intact(int r, int c)
{
    int i, rr, cc, result = 0;
    for (i = 0; i < 4; ++i) {
        rr = r + drow[i];
        cc = c + dcol[i];
        if (inrange(rr, 0, n) && inrange(cc, 0, m)
            && g[rr][cc] == '.') ++result;
    }
    return result;
}

int check()
{
    int i, rr, cc;
    if (r1 == r2 && c1 == c2) {
        return adj_intact(r1, c1) > 0;
    } else if (dist_abs(r1, r2) + dist_abs(c1, c2) == 1) {
        if (g[r2][c2] == 'X') return 1;
        else return adj_intact(r2, c2) > 0;
    } else {
        // Check whether the path from (r1, c1) to (r2, c2) exists using BFS/Floodfill
        unsigned char v[MAXN * MAXN] = {0}, endpt_flipped = 0;
        if (g[r2][c2] == 'X') { g[r2][c2] = '.'; endpt_flipped = 1; }
        int q[MAXN * MAXN], qfront = 1, qtail = 0;
        q[0] = r1 * m + c1; v[q[0]] = 1;
        do {
            int r = q[qtail++];
            for (i = 0; i < 4; ++i) {
                rr = r / m + drow[i];
                cc = r % m + dcol[i];
                if (inrange(rr, 0, n) && inrange(cc, 0, m)
                        && !v[rr * m + cc] && g[rr][cc] == '.') {
                    v[rr * m + cc] = 1;
                    q[qfront++] = rr * m + cc;
                }
            }
        } while (qfront != qtail);
        if (!v[r2 * m + c2]) return 0;
        if (endpt_flipped) return 1;
        else return adj_intact(r2, c2) > 1;
    }
}

int main()
{
    scanf("%d%d", &n, &m); getchar();
    int i, j;
    for (i = 0; i < n; ++i)
        for (j = 0; j <= m; ++j) g[i][j] = getchar();
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    --r1, --c1, --r2, --c2;
    puts(check() ? "YES" : "NO");
    return 0;
}