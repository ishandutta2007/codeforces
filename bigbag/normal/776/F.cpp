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

const int max_n = 101111, inf = 1011111111;

int n, m, vcmp, ans[max_n], p[max_n], used[max_n], sz[max_n], mx[max_n];
vector<int> g[max_n];
vector<vector<int> > all;
vector<pair<pair<int, int>, int> > alle;
map<int, int> pos[max_n];

int num(int a, int vcmp) {
    return (a - vcmp + n) % n;
}

bool cmp(int a, int b) {
    return num(a, vcmp) < num(b, vcmp);
}

bool cmp2(int a, int b) {
    return all[a] < all[b];
}

void add_edge(int u, int v) {
    g[u].push_back(v);
    g[v].push_back(u);
}

void dfs1(int v, int p) {
    sz[v] = 1;
    mx[v] = 0;
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != p && used[g[v][i]] == 0) {
            dfs1(g[v][i], v);
            sz[v] += sz[g[v][i]];
            mx[v] = max(mx[v], sz[g[v][i]]);
        }
    }
}

int dfs2(int v, int p) {
    if (max(mx[v], n - sz[v]) <= n / 2) {
        return v;
    }
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != p && used[g[v][i]] == 0) {
            int res = dfs2(g[v][i], v);
            if (res != -1) {
                return res;
            }
        }
    }
    return -1;
}

void dfs(int v, int col) {
    dfs1(v, -1);
    n = sz[v];
    int root = dfs2(v, -1);
    ans[root] = col;
    used[root] = 1;
    for (int i = 0; i < g[root].size(); ++i) {
        int to = g[root][i];
        if (used[to] == 0) {
            dfs(to, col + 1);
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
        g[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        g[i].push_back((i + 1) % n);
        g[(i + 1) % n].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        vcmp = i;
        sort(g[i].begin(), g[i].end(), cmp);
        for (int j = 0; j < g[i].size(); ++j) {
            pos[i][g[i][j]] = j;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j + 1 < g[i].size(); ++j) {
            if (i < g[i][j] && i < g[i][j + 1]) {
                vector<int> q;
                int v = i, to = g[i][j];
                while (to != g[i][j + 1]) {
                    q.push_back(v);
                    int nto = g[to][pos[to][v] - 1];
                    v = to;
                    to = nto;
                }
                q.push_back(v);
                q.push_back(to);
                for (int k = 0; k < q.size(); ++k) {
                    int mn = q[k], mx = q[(k + 1) % q.size()];
                    if (mn > mx) {
                        swap(mn, mx);
                    }
                    alle.push_back(make_pair(make_pair(mn, mx), all.size()));
                }
                all.push_back(q);
            }
        }
    }
    sort(alle.begin(), alle.end());
    for (int i = 0; i < all.size(); ++i) {
        g[i].clear();
    }
    for (int i = 0; i + 1 < alle.size(); ++i) {
        if (alle[i].first == alle[i + 1].first) {
            add_edge(alle[i].second, alle[i + 1].second);
        }
    }
    for (int i = 0; i < all.size(); ++i) {
        p[i] = i;
        sort(all[i].begin(), all[i].end());
        reverse(all[i].begin(), all[i].end());
    }
    sort(p, p + all.size(), cmp2);
    dfs(0, 1);
    for (int i = 0; i < all.size(); ++i) {
        printf("%d ", ans[p[i]]);
    }
    printf("\n");
    return 0;
}