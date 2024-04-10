#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 303, inf = 1111111111;

struct tree {
    int tm, mn[max_n][max_n], last[max_n][max_n];
    tree() {
        tm = 1;
        memset(last, 0, sizeof(last));
    }
    void clr() {
        ++tm;
    }
    void update(int x, int y, int q) {
        for (int i = x; i < max_n; i = (i | (i + 1))) {
            for (int j = y; j < max_n; j = (j | (j + 1))) {
                if (last[i][j] < tm) {
                    last[i][j] = tm;
                    mn[i][j] = inf;
                }
                mn[i][j] = min(mn[i][j], q);
            }
        }
    }
    int get(int x, int y) {
        int res = inf;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1) {
                if (last[i][j] < tm) {
                    last[i][j] = tm;
                    mn[i][j] = inf;
                }
                res = min(res, mn[i][j]);
            }
        }
        return res;
    }
};

int n, m, p, a[max_n][max_n], dist[max_n][max_n], l[max_n * max_n], r[max_n * max_n];
int x[max_n * max_n], y[max_n * max_n];
tree t[2][2];

void upd(int x, int y) {
    for (int f1 = 0; f1 < 2; ++f1) {
        for (int f2 = 0; f2 < 2; ++f2) {
            int nx = x, ny = y, r1 = -x, r2 = -y;
            if (f1) {
                nx = n - x;
                r1 *= -1;
            }
            if (f2) {
                ny = m - y;
                r2 *= -1;
            }
            t[f1][f2].update(nx, ny, dist[x][y] + r1 + r2);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
            ++r[a[i][j]];
            dist[i][j] = inf;
        }
    }
    for (int i = 2; i <= p; ++i) {
        l[i] = r[i - 1];
        r[i] = l[i] + r[i];
    }
    for (int i = 1; i <= p; ++i) {
        r[i] = l[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            x[r[a[i][j]]] = i;
            y[r[a[i][j]]] = j;
            ++r[a[i][j]];
        }
    }
    for (int i = 0; i < r[1]; ++i) {
        dist[x[i]][y[i]] = x[i] + y[i];
        upd(x[i], y[i]);
    }
    for (int i = 2; i <= p; ++i) {
        for (int j = l[i]; j < r[i]; ++j) {
            int xx = x[j], yy = y[j];
            for (int f1 = 0; f1 < 2; ++f1) {
                for (int f2 = 0; f2 < 2; ++f2) {
                    int nx = xx, ny = yy, r1 = xx, r2 = yy;
                    if (f1) {
                        nx = n - xx;
                        r1 *= -1;
                    }
                    if (f2) {
                        ny = m - yy;
                        r2 *= -1;
                    }
                    dist[xx][yy] = min(dist[xx][yy], t[f1][f2].get(nx, ny) + r1 + r2);
                }
            }
        }
        for (int f1 = 0; f1 < 2; ++f1) {
            for (int f2 = 0; f2 < 2; ++f2) {
                t[f1][f2].clr();
            }
        }
        for (int j = l[i]; j < r[i]; ++j) {
            upd(x[j], y[j]);
            //cout << x[j] << " " << y[j] << " : " << dist[x[j]][y[j]] << endl;
        }
    }
    printf("%d\n", dist[x[l[p]]][y[l[p]]]);
    return 0;
}