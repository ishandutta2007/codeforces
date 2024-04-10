#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, m;
set<int> g[max_n], not_vis;

void dfs(int v) {
    not_vis.erase(v);
    while (true) {
        auto it = not_vis.begin();
        while (it != not_vis.end() && g[v].count(*it)) {
            ++it;
        }
        if (it == not_vis.end()) {
            break;
        }
        dfs(*it);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u;
        --v;
        g[u].insert(v);
        g[v].insert(u);
    }
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        not_vis.insert(i);
    }
    for (int i = 0; i < n; ++i) {
        if (not_vis.count(i)) {
            ++ans;
            dfs(i);
        }
    }
    printf("%d\n", ans);
    return 0;
}