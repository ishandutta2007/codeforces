#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
static const int MAXK = 505;
static const int INF = 0x3fffffff;

int n, m, k;
int x[MAXK], y[MAXK];

std::map<int, int> xs, ys;
int xuq[MAXK * 2], yuq[MAXK * 2];
int g[MAXK * 2][MAXK * 2];

inline bool check(int t)
{
    xs.clear();
    ys.clear();
    for (int i = 0; i < k; ++i) {
        int top = std::max(1, x[i] - t), bottom = std::min(n, x[i] + t),
            left = std::max(1, y[i] - t), right = std::min(m, y[i] + t);
        xs[top] = xs[bottom + 1] = ys[left] = ys[right + 1] = -1;
    }
    xs[1] = xs[n + 1] = ys[1] = ys[m + 1] = -1;
    int xct = 0, yct = 0;
    for (auto &p : xs) { xuq[xct] = p.first; p.second = xct++; }
    for (auto &p : ys) { yuq[yct] = p.first; p.second = yct++; }

    memset(g, 0, sizeof g);
    for (int i = 0; i < k; ++i) {
        int top = std::max(1, x[i] - t), bottom = std::min(n, x[i] + t),
            left = std::max(1, y[i] - t), right = std::min(m, y[i] + t);
        g[xs[top]][ys[left]] += 1;
        g[xs[top]][ys[right + 1]] -= 1;
        g[xs[bottom + 1]][ys[left]] -= 1;
        g[xs[bottom + 1]][ys[right + 1]] += 1;
    }
    int x_min = INF, x_max = -1, y_min = INF, y_max = -1;
    for (int i = 0; i < xct - 1; ++i)
        for (int j = 0; j < yct - 1; ++j) {
            if (i > 0) g[i][j] += g[i - 1][j];
            if (j > 0) g[i][j] += g[i][j - 1];
            if (i && j) g[i][j] -= g[i - 1][j - 1];
            if (g[i][j] == 0) {
                x_min = std::min(x_min, i); x_max = std::max(x_max, i);
                y_min = std::min(y_min, j); y_max = std::max(y_max, j);
            }
        }

    if (x_min > x_max || y_min > y_max) return true;
    x_min = xuq[x_min]; x_max = xuq[x_max + 1] - 1;
    y_min = yuq[y_min]; y_max = yuq[y_max + 1] - 1;
    return (x_max - x_min <= t * 2 && y_max - y_min <= t * 2);
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; ++i)
        scanf("%d%d", &x[i], &y[i]);

    int lo = -1, hi = INF, mid;
    while (lo < hi - 1) {
        mid = (lo + hi) >> 1;
        if (check(mid)) hi = mid; else lo = mid;
    }

    printf("%d\n", hi);
    return 0;
}