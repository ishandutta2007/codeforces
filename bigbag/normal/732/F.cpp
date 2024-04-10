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

const int max_n = 404444, inf = 1111111111;

int n, m, cnt, used[max_n], sz[max_n], u[max_n], v[max_n], tin[max_n], fup[max_n], f[max_n];
int ans[max_n];
vector<int> g[max_n], num[max_n];

void dfs(int v, int p) {
    ++cnt;
    tin[v] = fup[v] = cnt;
    //cout << v << " tin = " << tin[v] << endl;
    for (int i = 0; i < g[v].size(); ++i) {
        if (num[v][i] == p) {
            continue;
        }
        if (tin[g[v][i]] == 0) {
            dfs(g[v][i], num[v][i]);
            fup[v] = min(fup[v], fup[g[v][i]]);
            if (tin[v] < fup[g[v][i]]) {
                f[num[v][i]] = 1;
            }
        } else {
            fup[v] = min(fup[v], tin[g[v][i]]);
        }
    }
    //cout << v << " fup = " << fup[v] << endl;
}

int dfs2(int V) {
    used[V] = cnt;
    int res = 1;
    for (int i = 0; i < g[V].size(); ++i) {
        int nm = num[V][i];
        if (ans[nm] == 0) {
            if (u[nm] == V) {
                ans[nm] = 1;
            } else {
                ans[nm] = -1;
            }
        }
        if (used[g[V][i]] == 0) {
            res += dfs2(g[V][i]);
        }
    }
    return res;
}

void dfs3(int v, int mn, int p, int pnum) {
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != p) {
            dfs3(g[v][i], mn, v, num[v][i]);
        }
    }
    if (p != -1) {
        int U = v, V = p;
        if (f[v] >= mn) {
            f[p] += f[v];
            swap(U, V);
        }
        if (U == used[u[pnum]]) {
            ans[pnum] = 1;
        } else {
            ans[pnum] = -1;
        }
    }
}

bool check(int x) {
    for (int i = 1; i <= cnt; ++i) {
        f[i] = sz[i];
    }
    dfs3(1, x, -1, -1);
    return f[1] >= x;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u[i], &v[i]);
        g[u[i]].push_back(v[i]);
        num[u[i]].push_back(i);
        g[v[i]].push_back(u[i]);
        num[v[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        if (tin[i] == 0) {
            dfs(i, -1);
        }
    }
    for (int i = 1; i <= n; ++i) {
        g[i].clear();
        num[i].clear();
    }
    for (int i = 0; i < m; ++i) {
        //cout << u[i] << " " << v[i] << " : " << f[i] << endl;
        if (f[i] == 0) {
            g[u[i]].push_back(v[i]);
            num[u[i]].push_back(i);
            g[v[i]].push_back(u[i]);
            num[v[i]].push_back(i);
        }
    }
    cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (used[i] == 0) {
            ++cnt;
            sz[cnt] = dfs2(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        g[i].clear();
        num[i].clear();
    }
    for (int i = 0; i < m; ++i) {
        if (f[i]) {
            g[used[u[i]]].push_back(used[v[i]]);
            num[used[u[i]]].push_back(i);
            g[used[v[i]]].push_back(used[u[i]]);
            num[used[v[i]]].push_back(i);
        }
    }
    int l = 0, r = n + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    printf("%d\n", l);
    dfs3(1, l, -1, -1);
    for (int i = 0; i < m; ++i) {
        if (ans[i] == 0) {
            cout << "?" << endl;
            continue;
        }
        if (ans[i] == -1) {
            swap(u[i], v[i]);
        }
        printf("%d %d\n", u[i], v[i]);
    }
    return 0;
}