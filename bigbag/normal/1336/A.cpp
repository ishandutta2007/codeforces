#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, k, p[max_n], h[max_n], sz[max_n];
vector<int> g[max_n];
long long ans;

void dfs(int v) {
    sz[v] = 1;
    for (int to : g[v]) {
        if (to == p[v]) {
            continue;
        }
        p[to] = v;
        h[to] = h[v] + 1;
        dfs(to);
        sz[v] += sz[to];
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    vector<int> all;
    for (int i = 1; i < n; ++i) {
        all.push_back(h[i] - sz[i] + 1);
    }
    sort(all.begin(), all.end());
    reverse(all.begin(), all.end());
    for (int i = 0; i < k; ++i) {
        ans += all[i];
    }
    printf("%I64d\n", ans);
    return 0;
}