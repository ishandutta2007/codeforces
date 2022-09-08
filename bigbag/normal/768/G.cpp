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

struct tree {
    int last, t[max_n], tm[max_n];
    tree() {
        last = 0;
        memset(t, 0, sizeof(t));
        memset(tm, 0, sizeof(tm));
    }
    void clr() {
        ++last;
    }
    void update(int i, int x) {
        for (; i < max_n; i = (i | (i + 1))) {
            if (tm[i] < last) {
                tm[i] = last;
                t[i] = 0;
            }
            t[i] += x;
        }
    }
    int get_sum(int r) {
        int res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            if (tm[r] < last) {
                tm[r] = last;
                t[r] = 0;
            }
            res += t[r];
        }
        return res;
    }
    int get_sum(int l, int r) {
        if (l > r) {
            return 0;
        }
        if (l == 0) {
            return get_sum(r);
        }
        return get_sum(r) - get_sum(l - 1);
    }
    void write() {
        for (int i = 1; i <= 10; ++i) {
            cout << get_sum(i, i) << " ";
        }
        cout << endl;
    }
};

int n, root, sz[max_n], ans[max_n];
tree all, last, path;
vector<int> g[max_n];

void dfs1(int v) {
    sz[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        dfs1(g[v][i]);
        sz[v] += sz[g[v][i]];
    }
    all.update(sz[v], 1);
}

void dfs3(int v) {
    last.update(sz[v], 1);
    for (int i = 0; i < g[v].size(); ++i) {
        dfs3(g[v][i]);
    }
}

void update(int v, int to) {
    last.update(sz[v], 1);
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != to) {
            dfs3(g[v][i]);
        }
    }
}

void dfs2(int v) {
    int to = -1;
    int mn = n - sz[v], mx = n - sz[v], mx2 = 0;
    if (v == root) {
        mn = inf;
        mx = -inf;
    }
    for (int i = 0; i < g[v].size(); ++i) {
        if (to == -1 || sz[to] < sz[g[v][i]]) {
            to = g[v][i];
        }
        mn = min(mn, sz[g[v][i]]);
        mx = max(mx, sz[g[v][i]]);
    }
    if (mx == n - sz[v]) {
        for (int i = 0; i < g[v].size(); ++i) {
            mx2 = max(mx2, sz[g[v][i]]);
        }
    } else {
        mx2 = n - sz[v];
        for (int i = 0; i < g[v].size(); ++i) {
            if (to != g[v][i]) {
                mx2 = max(mx2, sz[g[v][i]]);
            }
        }
    }
    path.update(sz[v], 1);
    all.update(sz[v], -1);
    last.clr();
    for (int i = 0; i < g[v].size(); ++i) {
        if (to != g[v][i]) {
            dfs2(g[v][i]);
        }
    }
    if (to != -1) {
        dfs2(to);
    }
    path.update(sz[v], -1);
    all.update(sz[v], 1);
    if (mx == mn) {
        ans[v] = mx;
        update(v, to);
        return;
    }
    if (to != -1 && sz[to] == mx) {
        int l = 0, r = n;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (last.get_sum(mx - mid, mid - mn)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        ans[v] = r;
        update(v, to);
    } else {
        /*if (v == 2) {
            cout << "#" << mn << " " << mx << "  to = " << to << endl;
        }*/
        update(v, to);

        int l = 0, r = n;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            /*if (v == 2 && mid == 4) {
                cout << "$" << path.get_sum(mx - mid + sz[v], mid - mn + sz[v]) << endl;
                cout << "$" << all.get_sum(mx - mid, mid - mn) << " " << last.get_sum(mx - mid, mid - mn) << endl;
            }*/
            if (path.get_sum(mx - mid + sz[v], mid - mn + sz[v]) || (all.get_sum(mx - mid, mid - mn) - last.get_sum(mx - mid, mid - mn))) {
                r = mid;
            } else {
                l = mid;
            }
        }
        ans[v] = r;
    }
    ans[v] = max(ans[v], mx2);
    //cout << v << ": ";
    //last.write();
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        int p, v;
        scanf("%d%d", &p, &v);
        if (p == 0) {
            root = v;
        } else {
            g[p].push_back(v);
        }
    }
    dfs1(root);
    dfs2(root);
    for (int i = 1; i <= n; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}