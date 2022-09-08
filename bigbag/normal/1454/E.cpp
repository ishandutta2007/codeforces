#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, p[max_n], used[max_n];
vector<int> g[max_n], all;

void clr() {
    all.clear();
    for (int i = 0; i < n; ++i) {
        g[i].clear();
        used[i] = 0;
    }
}

void dfs(int v) {
    used[v] = 1;
    for (int to : g[v]) {
        if (p[v] == to) {
            continue;
        }
        if (used[to]) {
            int cur = v;
            while (cur != to) {
                all.push_back(cur);
                cur = p[cur];
            }
            all.push_back(to);
            return;
        }
        p[to] = v;
        dfs(to);
        if (!all.empty()) {
            return;
        }
    }
}

int get_sz(int v, int p) {
    int res = 1;
    for (int to : g[v]) {
        if (to == p || used[to]) {
            continue;
        }
        res += get_sz(to, v);
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            --u;
            --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0);
        for (int i = 0; i < n; ++i) {
            used[i] = 0;
        }
        for (int v : all) {
            used[v] = 1;
        }
        long long ans = 1LL * n * (n - 1);
        for (int v : all) {
            int sz = get_sz(v, -1);
            ans -= 1LL * sz * (sz - 1) / 2;
        }
        printf("%I64d\n", ans);
        clr();
    }
    return 0;
}