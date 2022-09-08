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

const int max_n = 222222, inf = 1111111111;

int n, mx, res[max_n];
vector<int> g[max_n], num[max_n], ans[max_n];

void add(int a, int b) {
    ans[a].push_back(b);
    res[b] = a;
}

void dfs(int v, int p) {
    if (p == -1) {
        for (int i = 0; i < g[v].size(); ++i) {
            add(i, num[v][i]);
            dfs(g[v][i], v);
        }
        return;
    }
    int bad;
    for (int i = 0; i < g[v].size(); ++i) {
        if (p == g[v][i]) {
            bad = res[num[v][i]];
        }
    }
    int q = 0;
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != p) {
            if (q == bad) {
                ++q;
            }
            add(q, num[v][i]);
            ++q;
            dfs(g[v][i], v);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
        num[u].push_back(i);
        num[v].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        mx = max(mx, (int) g[i].size());
    }
    int root;
    for (int i = 1; i <= n; ++i) {
        if (mx == g[i].size()) {
            root = i;
        }
    }
    //cout << "$" << root << endl;
    dfs(root, -1);
    printf("%d\n", mx);
    for (int i = 0; i < mx; ++i) {
        printf("%d ", ans[i].size());
        for (int j = 0; j < ans[i].size(); ++j) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}