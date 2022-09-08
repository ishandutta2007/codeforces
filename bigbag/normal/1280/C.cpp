#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int tests, n, sz[max_n];
long long d[max_n];
vector<int> g[max_n], t[max_n];

void dfs0(int v, int p) {
    for (int i = 0; i < g[v].size(); ++i) {
        const int to = g[v][i];
        if (to == p) {
            continue;
        }
        d[to] = d[v] + t[v][i];
        dfs0(to, v);
    }
}

long long min_sum, max_sum;

void dfs1(int v, int p) {
    sz[v] = 1;
    int cnt = 1;
    int mx_sz = 0;
    for (int i = 0; i < g[v].size(); ++i) {
        const int to = g[v][i];
        if (to == p) {
            continue;
        }
        dfs1(to, v);
        sz[v] += sz[to];
        cnt += sz[to] % 2;
        mx_sz = max(mx_sz, sz[to]);
    }
    min_sum += 1LL * (cnt / 2) * d[v];
}

void dfs2(int v, int p, int need) {
    //cout << "$" << v << endl;
    int mx_sz = 0, mx_to = 0;
    for (int i = 0; i < g[v].size(); ++i) {
        const int to = g[v][i];
        if (to == p) {
            continue;
        }
        if (mx_sz < sz[to]) {
            mx_sz = sz[to];
            mx_to = to;
        }
    }
    int max_cnt = sz[v] / 2;
    if (sz[v] - mx_sz <= mx_sz) {
        max_cnt = sz[v] - mx_sz;
    }
    if (max_cnt >= need) {
        max_sum += 1LL * need * d[v];
    } else {
        max_sum += 1LL * max_cnt * d[v];
        need -= max_cnt;
        dfs2(mx_to, v, need);
    }
}

void clr() {
    for (int i = 0; i < n; ++i) {
        g[i].clear();
        t[i].clear();
        d[i] = 0;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &tests);
    while (tests--) {
        scanf("%d", &n);
        n *= 2;
        for (int i = 1; i < n; ++i) {
            int u, v, d;
            scanf("%d%d%d", &u, &v, &d);
            --u;
            --v;
            g[u].push_back(v);
            g[v].push_back(u);
            t[u].push_back(d);
            t[v].push_back(d);
        }
        dfs0(0, -1);
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += d[i];
        }
        min_sum = max_sum = 0;
        dfs1(0, -1);
        dfs2(0, -1, n / 2);
        min_sum *= 2;
        max_sum *= 2;
        printf("%I64d %I64d\n", ans - min_sum, ans - max_sum);
        clr();
    }
    return 0;
}