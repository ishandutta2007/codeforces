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

const int max_n = 222222, max_lev = 20, inf = 1111111111;

struct tree {
    vector<int> a;
    tree(int sz) {
        a.resize(4 * sz);
    }
    void update(int v, int l, int r, int x, int value) {
        if (l == r) {
            a[v] = value;
            return;
        }
        int mid = (l + r) / 2;
        if (x <= mid) {
            update(2 * v, l, mid, x, value);
        } else {
            update(2 * v + 1, mid + 1, r, x, value);
        }
        a[v] = min(a[2 * v], a[2 * v + 1]);
    }
    int get_min(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return a[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_min(2 * v, tl, mid, l, r);
        }
        if (l > mid) {
            return get_min(2 * v + 1, mid + 1, tr, l, r);
        }
        return min(get_min(2 * v, tl, mid, l, mid), get_min(2 * v + 1, mid + 1, tr, mid + 1, r));
    }
};

int n, m, sz[max_n], u[max_n], v[max_n], num[max_n], num1[max_n], num2[max_n], f[max_n], used[max_n], poz[max_n];
int cnt, tin[max_n], tout[max_n], p[max_lev][max_n], nxt[max_n];
vector<int> g[max_n];
vector<long long> q[max_n];
vector<tree> t;
vector<vector<int> > alls;
long long x[max_n];

void dfs(int v, int pp) {
    sz[v] = 1;
    p[0][v] = pp;
    ++cnt;
    tin[v] = cnt;
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] == pp) {
            num[v] = i;
            continue;
        }
        dfs(g[v][i], v);
        sz[v] += sz[g[v][i]];
    }
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] == pp) {
            continue;
        }
        if (sz[g[v][i]] >= (sz[v] + 1) / 2) {
            f[g[v][i]] = 1;
        }
    }
    ++cnt;
    tout[v] = cnt;
}

void get_all_p() {
    p[0][1] = 0;
    for (int lev = 1; lev < max_lev; ++lev) {
        for (int i = 1; i <= n; ++i) {
            p[lev][i] = p[lev - 1][p[lev - 1][i]];
        }
    }
}

bool is_ancestor(int u, int v) {
    if (u == 0) {
        return true;
    }
    if (v == 0) {
        return false;
    }
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) {
        return u;
    }
    if (is_ancestor(v, u)) {
        return v;
    }
    for (int i = max_lev - 1; i >= 0; --i) {
        if (!is_ancestor(p[i][u], v)) {
            u = p[i][u];
        }
    }
    return p[0][u];
}

void go(int v) {
    vector<int> all;
    while (true) {
        used[v] = cnt;
        all.push_back(v);
        if (f[v] == 0) {
            nxt[cnt] = p[0][v];
            break;
        }
        v = p[0][v];
    }
    t.push_back(tree(all.size()));
    alls.push_back(all);
    int c = 0;
    /*cout << cnt << " : ";
    for (int i = 0; i < all.size(); ++i) {
        cout << all[i] << " ";
    }
    cout << endl;*/
    for (int i = 0; i < all.size(); ++i) {
        v = all[i];
        poz[v] = i;
        if (q[v][num[v]] == 1) {
            t[cnt].update(1, 0, all.size() - 1, i, inf);
        } else {
            t[cnt].update(1, 0, all.size() - 1, i, i);
        }
    }
    ++cnt;
}

void build() {
    cnt = 0;
    for (int i = 1; i <= n; ++i) {
        int fff = 0;
        for (int j = 0; j < g[i].size(); ++j) {
            if (g[i][j] != p[0][i] && f[g[i][j]]) {
                fff = 1;
                break;
            }
        }
        if (fff == 0) {
            go(i);
        }
    }
}

void proc(int v, int last, long long &x) {
    //cout << v << " " << last << " : ";
    while (x) {
        int v2 = alls[used[v]].back();
        if (is_ancestor(v2, last)) {
            int l = poz[v], r = poz[last] - 1;
            while (x && l <= r) {
                int mn = t[used[v]].get_min(1, 0, alls[used[v]].size() - 1, l, r);
                if (mn == inf) {
                    break;
                }
                int vv = alls[used[v]][mn];
                //cout << q[vv][num[vv]] << " ";
                x /= q[vv][num[vv]];
                l = mn + 1;
            }
            break;
        } else {
            int l = poz[v], r = alls[used[v]].size() - 1;
            while (x && l <= r) {
                int mn = t[used[v]].get_min(1, 0, alls[used[v]].size() - 1, l, r);
                if (mn == inf) {
                    break;
                }
                int vv = alls[used[v]][mn];
                //cout << q[vv][num[vv]] << " ";
                x /= q[vv][num[vv]];
                l = mn + 1;
            }
            v = nxt[used[v]];
        }
    }
    //cout << endl;
}

void update(int u, int v, long long x) {
    if (is_ancestor(v, u)) {
        swap(u, v);
    }
    if (x == 1) {
        t[used[v]].update(1, 0, alls[used[v]].size() - 1, poz[v], inf);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; ++i) {
        scanf("%d%d%I64d", &u[i], &v[i], &x[i]);
        num1[i] = q[u[i]].size();
        num2[i] = q[v[i]].size();
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
        q[u[i]].push_back(x[i]);
        q[v[i]].push_back(x[i]);
    }
    dfs(1, -1);
    get_all_p();
    build();
    while (m--) {
        int tp;
        scanf("%d", &tp);
        if (tp == 1) {
            int v1, v2;
            long long x;
            scanf("%d%d%I64d", &v1, &v2, &x);
            int lc = lca(v1, v2);
            //cout << v1 << " " << v2 << " : lca = " << lc << "  ";
            proc(v1, lc, x);
            proc(v2, lc, x);
            printf("%I64d\n", x);
        } else {
            int num;
            long long x;
            scanf("%d%I64d", &num, &x);
            update(u[num], v[num], x);
            q[u[num]][num1[num]] = x;
            q[v[num]][num2[num]] = x;
        }
    }
    return 0;
}