#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, q, cur, l[max_n], r[max_n];
vector<int> g[max_n], ans;

void dfs(int v) {
    l[v] = cur;
    r[v] = cur;
    ++cur;
    ans.push_back(v);
    for (int i = 0; i < g[v].size(); ++i) {
        dfs(g[v][i]);
        r[v] = max(r[v], r[g[v][i]]);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 2; i <= n; ++i) {
        int p;
        scanf("%d", &p);
        g[p].push_back(i);
    }
    dfs(1);
    while (q--) {
        int v, k;
        scanf("%d%d", &v, &k);
        if (k <= r[v] - l[v] + 1) {
            printf("%d\n", ans[l[v] + k - 1]);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}