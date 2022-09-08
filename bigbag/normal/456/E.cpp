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

int n, m, q, p[max_n], d[max_n];
vector<int> g[max_n];

int find_set(int v) {
    if (v == p[v]) {
        return v;
    }
    return p[v] = find_set(p[v]);
}

void union_set(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if (u != v) {
        p[u] = v;
    }
}

pair<int, int> dfs(int v, int p) {
    pair<int, int> res(0, v);
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != p) {
            pair<int, int> p = dfs(g[v][i], v);
            res = max(res, make_pair(1 + p.first, p.second));
        }
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
        union_set(u, v);
    }
    for (int i = 1; i <= n; ++i) {
        int s = find_set(i);
        if (d[s] == 0) {
            pair<int, int> p = dfs(i, -1);
            p = dfs(p.second, -1);
            d[s] = p.first;
        }
    }
    for (int i = 0; i < q; ++i) {
        int t, x, y;
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d", &x);
            printf("%d\n", d[find_set(x)]);
        } else {
            scanf("%d%d", &x, &y);
            x = find_set(x);
            y = find_set(y);
            if (x != y) {
                int nd = max(d[x], max(d[y], (d[x] + 1) / 2 + (d[y] + 1) / 2 + 1));
                union_set(x, y);
                x = find_set(x);
                d[x] = nd;
            }
        }
    }
    return 0;
}