#include <cstdio>
static const int INF = 0x7fffffff;
static const int MAXN = 500006;

int n, x0, y0;
int bx[MAXN * 2], by[MAXN * 2], bct = 0;
int rx[MAXN * 2], ry[MAXN * 2], rct = 0;
int dga[2], dgb[2], xx[2], yy[2];

inline void upd_nearest(int *m, int v, bool is_greater)
{
    if (is_greater && m[1] > v) m[1] = v;
    if (!is_greater && m[0] < v) m[0] = v;
}

int main()
{
    scanf("%d%d%d", &n, &x0, &y0); getchar();
    char type; int x, y;
    dga[0] = dgb[0] = xx[0] = yy[0] = -INF;
    dga[1] = dgb[1] = xx[1] = yy[1] = +INF;
    for (int i = 0; i < n; ++i) {
        type = getchar(); scanf("%d%d", &x, &y); getchar();
        if (type == 'B' || type == 'Q') bx[bct] = x, by[bct++] = y;
        if (type == 'R' || type == 'Q') rx[rct] = x, ry[rct++] = y;
        if (x + y == x0 + y0) upd_nearest(dga, x, x > x0);
        if (x - y == x0 - y0) upd_nearest(dgb, x, x > x0);
        if (x == x0) upd_nearest(xx, y, y > y0);
        if (y == y0) upd_nearest(yy, x, x > x0);
    }

    bool in_check = false;
    for (int i = 0; i < bct; ++i) {
        if (bx[i] + by[i] == x0 + y0 && (bx[i] == dga[0] || bx[i] == dga[1])) { in_check = true; break; }
        if (bx[i] - by[i] == x0 - y0 && (bx[i] == dgb[0] || bx[i] == dgb[1])) { in_check = true; break; }
    }
    for (int i = 0; i < rct; ++i) {
        if (rx[i] == x0 && (ry[i] == xx[0] || ry[i] == xx[1])) { in_check = true; break; }
        if (ry[i] == y0 && (rx[i] == yy[0] || rx[i] == yy[1])) { in_check = true; break; }
    }

    puts(in_check ? "YES" : "NO");
    return 0;
}