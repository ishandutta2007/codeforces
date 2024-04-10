#include <cstdio>
#include <algorithm>
#include <utility>
static const int MAXN = 2e5 + 10;

int n, m;
std::pair<int, int> p[MAXN];
int x_idx[MAXN], x[MAXN];
int a_i, l_i;

inline int solve_query(int u, int len) {
    while (true) {
        int last_len = len;
        int p = std::upper_bound(x, x + n, x[u] + len) - x - 1;
        len -= (x[p] - x[u]);
        int q = std::lower_bound(x, x + n, x[p] - len) - x;
        len -= (x[p] - x[q]);
        if (p == q) return q;
        else if (u == q) len %= (last_len - len);
        u = q;
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &p[i].first); p[i].second = i + 1;
    }
    std::sort(p, p + n);
    for (int i = 0; i < n; ++i) {
        x[i] = p[i].first;
        x_idx[p[i].second] = i;
    }

    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a_i, &l_i);
        printf("%d\n", p[solve_query(x_idx[a_i], l_i)].second);
    }

    return 0;
}