#include <bits/stdc++.h>

using namespace std;

const int max_n = 202222, inf = 1000111222;

int n, m, mn[2][max_n], used[max_n];
vector<int> g[max_n], rg[max_n], order;

void dfs(int v) {
    used[v] = 1;
    for (int to : g[v]) {
        if (used[to] == 1) {
            puts("-1");
            exit(0);
        }
        if (!used[to]) {
            dfs(to);
        }
    }
    used[v] = 2;
    order.push_back(v);
}

void solve(vector<int> g[max_n], int mn[max_n]) {
    for (int v : order) {
        mn[v] = v;
        for (int to : g[v]) {
            mn[v] = min(mn[v], mn[to]);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u;
        --v;
        g[u].push_back(v);
        rg[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i);
        }
    }
    solve(g, mn[0]);
    reverse(order.begin(), order.end());
    solve(rg, mn[1]);
    string ans;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int x = min(mn[0][i], mn[1][i]);
        if (x < i) {
            ans += "E";
        } else {
            ans += "A";
            ++cnt;
        }
    }
    printf("%d\n", cnt);
    puts(ans.c_str());
    return 0;
}