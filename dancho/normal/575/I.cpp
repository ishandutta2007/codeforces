#include <cstdio>
#include <cstring>

void it_add(int n, int it[], int p, int v) {
    for (int i = p; i <= n; i += (i & (-i))) {
        it[i] += v;
    }
}

int it_get(int it[], int p) {
    int res = 0;
    for (int i = p; i > 0; i -= (i & (-i))) {
        res += it[i];
    }
    return res;
}

void it2_add(int n, int m, int it[][5020], int p, int l, int r) {
    for (int i = p; i <= n; i += (i & (-i))) {
        it_add(m, it[i], l, 1);
        it_add(m, it[i], r + 1, -1);
    }
}

int it2_get(int it[][5020], int x, int y) {
    int res = 0;
    for (int i = x; i > 0; i -= (i & (-i))) {
        res += it_get(it[i], y);
    }
    return res;
}

int fl[5020][5020];
int di[10020][5020];

int ans[1 << 17];

int n, q;
int tp[1 << 17], x[1 << 17], y[1 << 17], len[1 << 17], dir[1 << 17];

int rt[] = {0, 1, 3, 2};

void ncor(int d, int ox, int oy, int &nx, int &ny) {
    --d;
    nx = ox;
    ny = oy;
    for (int i = 0; i < rt[d]; ++i) {
        int x, y;
        x = -ny;
        y = nx;

        nx = x + n + 1;
        ny = y;
    }
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < q; ++i) {
        scanf("%d", &tp[i]);
        if (tp[i] == 1) {
            scanf("%d %d %d %d", &dir[i], &x[i], &y[i], &len[i]);
        } else {
            scanf("%d %d", &x[i], &y[i]);
        }
    }

    memset(ans, 0, sizeof(ans));
    for (int dr = 1; dr <= 4; ++dr) {
        memset(fl, 0, sizeof(fl));
        memset(di, 0, sizeof(di));
        for (int i = 0; i < q; ++i) {
            int nx, ny;
            ncor(dr, x[i], y[i], nx, ny);
            if (tp[i] == 1 && dir[i] == dr) {
                it2_add(n, n, fl, nx, ny, ny + len[i]);
                it2_add(n + n, n, di, nx + ny + len[i], ny, ny + len[i]);
            } else {
                ans[i] += it2_get(fl, nx, ny) - it2_get(di, nx + ny - 1, ny);
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        if (tp[i] == 2) {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}