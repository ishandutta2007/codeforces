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

const int max_n = 333333, inf = 1111111111;

struct tree {
    pair<int, int> mins[4 * max_n];
    void build(int v, int tl, int tr) {
        mins[v] = make_pair(0, tl);
        if (tl == tr) {
            return;
        }
        int mid = (tl + tr) / 2;
        build(2 * v, tl, mid);
        build(2 * v + 1, mid + 1, tr);
    }
    void update(int v, int l, int r, int x, int value) {
        if (l == r) {
            mins[v] = make_pair(value, l);
            return;
        }
        int mid = (l + r) / 2;
        if (x <= mid) {
            update(2 * v, l, mid, x, value);
        } else {
            update(2 * v + 1, mid + 1, r, x, value);
        }
        mins[v] = min(mins[2 * v], mins[2 * v + 1]);
    }
    pair<int, int> get_min(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return mins[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_min(2 * v, tl, mid, l, r);
        }
        if (l > mid) {
            return get_min(2 * v + 1, mid + 1, tr, l, r);
        }
        return min(get_min(2 * v, tl, mid, l, mid), get_min(2 * v + 1, mid + 1, tr, mid + 1, r));
    }
};

int n, m, k, f[2][max_n], used[max_n];
vector<int> g[max_n];
tree t;

void dfs(int v, int num) {
    used[v] = num;
    t.update(1, 1, n, v, 1);
    for (int i = 0; i + 1 < g[v].size(); ++i) {
        int l = g[v][i] + 1, r = g[v][i + 1] - 1;
        if (l <= r) {
            while (true) {
                pair<int, int> p = t.get_min(1, 1, n, l, r);
                if (p.first == 0) {
                    dfs(p.second, num);
                } else {
                    break;
                }
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    t.build(1, 1, n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 2; i <= n; ++i) {
        g[i].push_back(0);
        g[i].push_back(1);
        g[i].push_back(i);
        g[i].push_back(n + 1);
        sort(g[i].begin(), g[i].end());
        g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
    }
    int cnt = 0;
    for (int i = 2; i <= n; ++i) {
        if (used[i] == 0) {
            ++cnt;
            dfs(i, cnt);
        }
    }
    for (int i = 0; i < g[1].size(); ++i) {
        f[0][g[1][i]] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        if (f[0][i] == 0) {
            f[1][used[i]] = 1;
        }
    }
    int res = 0;
    for (int i = 1; i <= cnt; ++i) {
        res += f[1][i];
    }
    if (res == cnt && n - g[1].size() - 1 >= k && k >= res) {
        printf("possible\n");
    } else {
        printf("impossible\n");
    }
    return 0;
}