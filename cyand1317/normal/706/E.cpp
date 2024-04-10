#include <cstdio>
static const int MAXN = 1024;
template <typename T> inline void swap(T &a, T &b) {
    static T t; t = a; a = b; b = t;
}

int n, m, q;
struct node {
    int val;
    int next_rg, next_dn;
} a[MAXN * MAXN];
int head;

inline int locate(int start, int row, int col) {
    int cur = start;
    while (row--) cur = a[cur].next_dn;
    while (col--) cur = a[cur].next_rg;
    return cur;
}
inline int locate(int row, int col) {
    return locate(head, row, col);
}

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i * m + j].val);
            a[i * m + j].next_rg = (j == m - 1 ? -1 : i * m + j + 1);
            a[i * m + j].next_dn = (i == n - 1 ? -1 : i * m + j + m);
        }

    for (int i = 0; i < n; ++i) {
        a[n * m + i].val = -1;
        a[n * m + i].next_rg = i * m;
        a[n * m + i].next_dn = (i == n - 1 ? -1 : n * m + i + 1);
    }
    for (int i = 0; i < m; ++i) {
        a[n * m + n + i].val = -1;
        a[n * m + n + i].next_rg = (i == m - 1 ? -1 : n * m + n + i + 1);
        a[n * m + n + i].next_dn = i;
    }
    head = n * m + n + m;
    a[head].val = -2;
    a[head].next_rg = n * m + n;
    a[head].next_dn = n * m;

    int _a, b, c, d, h, w;
    do {
        scanf("%d%d%d%d%d%d", &_a, &b, &c, &d, &h, &w);
        int tl_corner1 = locate(_a - 1, b - 1),
            tl_corner2 = locate(c - 1, d - 1),
            tl_corner1r = a[tl_corner1].next_rg,
            tl_corner1d = a[tl_corner1].next_dn,
            tl_corner2r = a[tl_corner2].next_rg,
            tl_corner2d = a[tl_corner2].next_dn,
            bl_corner1 = locate(tl_corner1, h, 1),
            bl_corner2 = locate(tl_corner2, h, 1),
            tr_corner1 = locate(tl_corner1, 1, w),
            tr_corner2 = locate(tl_corner2, 1, w);
        int p1, p2;
        p1 = bl_corner1, p2 = bl_corner2;
        for (int i = 0; i < w; ++i) {
            swap(a[p1].next_dn, a[p2].next_dn);
            p1 = a[p1].next_rg;
            p2 = a[p2].next_rg;
        }
        p1 = tr_corner1, p2 = tr_corner2;
        for (int i = 0; i < h; ++i) {
            swap(a[p1].next_rg, a[p2].next_rg);
            p1 = a[p1].next_dn;
            p2 = a[p2].next_dn;
        }
        p1 = tl_corner1r, p2 = tl_corner2r;
        for (int i = 0; i < w; ++i) {
            swap(a[p1].next_dn, a[p2].next_dn);
            p1 = a[p1].next_rg;
            p2 = a[p2].next_rg;
        }
        p1 = tl_corner1d, p2 = tl_corner2d;
        for (int i = 0; i < h; ++i) {
            swap(a[p1].next_rg, a[p2].next_rg);
            p1 = a[p1].next_dn;
            p2 = a[p2].next_dn;
        }
    } while (--q);

    int head_left = head, cur;
    for (int i = 0; i < n; ++i) {
        cur = head_left = a[head_left].next_dn;
        for (int j = 0; j < m; ++j) {
            cur = a[cur].next_rg;
            printf("%d%c", a[cur].val, j == m - 1 ? '\n' : ' ');
        }
    }

    return 0;
}