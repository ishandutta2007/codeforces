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

const int max_n = 444444, inf = 1111111111;

int n, root, sz[max_n], ans[max_n], mx[max_n];
multiset<int> q;
vector<int> g[max_n];

void dfs(int v, int p) {
    sz[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] == p) {
            continue;
        }
        dfs(g[v][i], v);
        sz[v] += sz[g[v][i]];
        mx[v] = max(mx[v], sz[g[v][i]]);
    }
}

void dfs2(int v, int p, int tp) {
    if (tp == 0) {
        q.erase(q.find(sz[v]));
    } else {
        q.insert(sz[v]);
    }
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] == p) {
            continue;
        }
        dfs2(g[v][i], v, tp);
    }
}

void dfs3(int v, int p, int Q) {
    if (n - sz[v] <= n / 2) {
        ans[v] = 1;
    } else {
        multiset<int>::iterator it = q.upper_bound(n / 2);
        if (it != q.begin()) {
            --it;
            int mx = *it;
            if (n - sz[v] - mx <= n / 2) {
                ans[v] = 1;
            }
        }
    }
    q.insert(Q + 1);
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] == p) {
            continue;
        }
        dfs3(g[v][i], v, Q + 1);
    }
    q.erase(q.find(Q + 1));
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
    }
    dfs(1, -1);
    for (int i = 1; i <= n; ++i) {
        if (max(mx[i], n - sz[i]) <= n / 2) {
            root = i;
        }
    }
    //cout << "#" << root << endl;
    ans[root] = 1;
    dfs(root, -1);
    for (int i = 1; i <= n; ++i) {
        if (i != root) {
            q.insert(sz[i]);
        }
    }
    for (int i = 0; i < g[root].size(); ++i) {
        q.insert(n - sz[g[root][i]]);
        dfs2(g[root][i], root, 0);
        dfs3(g[root][i], root, n - sz[g[root][i]]);
        dfs2(g[root][i], root, 1);
        q.erase(q.find(n - sz[g[root][i]]));
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}