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

const int max_n = 555555, inf = 1011111111;

int n, res[1 << 22], a[max_n], ans[max_n], sz[max_n], mask[max_n], h[max_n];
vector<int> g[max_n], c[max_n];

void dfs(int v, int msk) {
    mask[v] = msk;
    sz[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        h[g[v][i]] = h[v] + 1;
        dfs(g[v][i], msk ^ (1 << c[v][i]));
        sz[v] += sz[g[v][i]];
    }
}

void update(int v, int f) {
    if (f) {
        res[mask[v]] = max(res[mask[v]], h[v]);
    } else {
        res[mask[v]] = -inf;
    }
    for (int i = 0; i < g[v].size(); ++i) {
        update(g[v][i], f);
    }
}

int get_ans(int v) {
    int x = res[mask[v]] + h[v];
    for (int i = 0; i < 22; ++i) {
        x = max(x, res[mask[v] ^ (1 << i)] + h[v]);
    }
    return x;
}

int get_mx(int v) {
    int x = get_ans(v);
    for (int i = 0; i < g[v].size(); ++i) {
        x = max(x, get_mx(g[v][i]));
    }
    return x;
}

void dfs1(int v, bool keep) {
    int to = -1;
    //cout << v << " " << keep << endl;
    for (int i = 0; i < g[v].size(); ++i) {
        if (to == -1 || (sz[g[v][i]] > sz[to])) {
            to = g[v][i];
        }
    }
    for (int i = 0; i < g[v].size(); ++i) {
        if (to != g[v][i]) {
            dfs1(g[v][i], 0);
        }
    }
    if (to != -1) {
        dfs1(to, 1);
    }
    res[mask[v]] = max(res[mask[v]], h[v]);
    a[v] = get_ans(v) - 2 * h[v];
    for (int i = 0; i < g[v].size(); ++i) {
        if (to != g[v][i]) {
            a[v] = max(a[v], get_mx(g[v][i]) - 2 * h[v]);
            update(g[v][i], 1);
        }
    }
    if (keep == 0) {
        update(v, 0);
    }
}

void dfs2(int v) {
    ans[v] = a[v];
    for (int i = 0; i < g[v].size(); ++i) {
        dfs2(g[v][i]);
        ans[v] = max(ans[v], ans[g[v][i]]);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < (1 << 22); ++i) {
        res[i] = -inf;
    }
    scanf("%d", &n);
    for (int i = 2; i <= n; ++i) {
        int p;
        char cc;
        scanf("%d%c%c", &p, &cc, &cc);
        g[p].push_back(i);
        c[p].push_back(cc - 'a');
    }
    dfs(1, 0);
    dfs1(1, 1);
    dfs2(1);
    for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
    }
    return 0;
}