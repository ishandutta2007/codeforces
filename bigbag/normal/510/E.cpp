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

const int max_n = 222, inf = 1111111111;

bool is_prime(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

struct edge {
    int v, c, f, numr;
    edge() {
    }
    edge(int v, int c, int f, int numr) : v(v), c(c), f(f), numr(numr) {
    }
};

int n, s, t, cnt, a[max_n], used[max_n];
vector<edge> g[max_n];//SIZE can be 2 * max_N!!!
vector<int> q[max_n], ans[max_n];

void add_edge(int u, int v, int c) {
    int rg1 = g[v].size();
    int rg2 = g[u].size();
    g[u].push_back(edge(v, c, 0, rg1));
    g[v].push_back(edge(u, 0, 0, rg2));
}

bool dfs(int v, int t, int fl) {
    if (v == t) {
        return true;
    }
    if (used[v] == 1) {
        return false;
    }
    used[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i].c >= g[v][i].f + fl && dfs(g[v][i].v, t, fl)) {
            g[v][i].f += fl;
            g[g[v][i].v][g[v][i].numr].f -= fl;
            return true;
        }
    }
    return false;
}

void dfs2(int v, int p) {
    ans[cnt].push_back(v);
    used[v] = 1;
    for (int i = 0; i < q[v].size(); ++i) {
        if (used[q[v][i]] == 0) {
            dfs2(q[v][i], v);
            if (p == -1) {
                break;
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    s = n;
    t = s + 1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            add_edge(s, i, 2);
        } else {
            add_edge(i, t, 2);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) {
            for (int j = 0; j < n; ++j) {
                if (is_prime(a[i] + a[j])) {
                    add_edge(i, j, 1);
                }
            }
        }
    }
    int cur = inf, res = 0;
    while (cur) {
        memset(used, 0, sizeof(used));
        while (dfs(s, t, cur)) {
            memset(used, 0, sizeof(used));
            res += cur;
        }
        cur /= 2;
    }
    if (res < n) {
        cout << "Impossible" << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            if (g[i][j].v < n && g[i][j].f == 1) {
                q[i + 1].push_back(g[i][j].v + 1);
                q[g[i][j].v + 1].push_back(i + 1);
            }
        }
    }
    memset(used, 0, sizeof(used));
    for (int i = 1; i <= n; ++i) {
        if (used[i] == 0) {
            dfs2(i, -1);
            ++cnt;
        }
    }
    cout << cnt << endl;
    for (int i = 0; i < cnt; ++i) {
        cout << ans[i].size() << " ";
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}