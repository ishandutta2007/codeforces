#include <bits/stdc++.h>

using namespace std;

const int max_n = 2011, inf = 1000111222;

int n, m, c, comp[max_n], used[max_n], ans[max_n];
vector<int> eq[max_n], g[max_n], order;
char s[max_n][max_n];

void dfs1(int v, int col) {
    comp[v] = col;
    for (int to : eq[v]) {
        if (comp[to] == -1) {
            dfs1(to, col);
        }
    }
}

void dfs2(int v) {
    used[v] = 1;
    for (int to : g[v]) {
        if (!used[to]) {
            dfs2(to);
        }
    }
    order.push_back(v);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i]);
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '=') {
                eq[i].push_back(n + j);
                eq[n + j].push_back(i);
            }
        }
    }
    memset(comp, -1, sizeof(comp));
    for (int i = 0; i < n + m; ++i) {
        if (comp[i] == -1) {
            dfs1(i, c);
            ++c;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '>') {
                g[comp[i]].push_back(comp[n + j]);
            } else if (s[i][j] == '<') {
                g[comp[n + j]].push_back(comp[i]);
            }
        }
    }
    for (int i = 0; i < c; ++i) {
        if (!used[i]) {
            dfs2(i);
        }
    }
    for (int v : order) {
        int mx = 0;
        for (int to : g[v]) {
            if (ans[to] == 0) {
                puts("No");
                return 0;
            }
            mx = max(mx, ans[to]);
        }
        ans[v] = mx + 1;
    }
    puts("Yes");
    for (int i = 0; i < n; ++i) {
        printf("%d ", ans[comp[i]]);
    }
    puts("");
    for (int i = 0; i < m; ++i) {
        printf("%d ", ans[comp[n + i]]);
    }
    puts("");
    return 0;
}