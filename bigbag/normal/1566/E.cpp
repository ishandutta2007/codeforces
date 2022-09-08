/**
 *  created: 12/09/2021, 18:20:12
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200111, inf = 1000111222;

int t, n, is_leaf[max_n], is_deleted[max_n];
vector<int> g[max_n];

void dfs(int v, int p) {
    is_leaf[v] = 1;
    is_deleted[v] = 0;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, v);
        is_leaf[v] = 0;
        is_deleted[v] |= !is_deleted[to];
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i < n; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            --u;
            --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0, -1);
        int k = accumulate(is_deleted + 1, is_deleted + n, 0);
        const int leaves = n - 1 - k;
        bool has_leaf = 0;
        for (int to : g[0]) {
            has_leaf |= !is_deleted[to];
        }
        int ans = leaves - k + !has_leaf;
        for (int i = 0; i < n; ++i) {
            g[i].clear();
        }
        printf("%d\n", ans);
    }
    return 0;
}