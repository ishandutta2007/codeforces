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

const int max_n = 200222, mx = (1 << 20) + 11, inf = 1011111111;

int last[mx], cnt[mx], ok[mx];
int n, cur, used[max_n], sz[max_n];
long long mn[max_n], tot[max_n][2], ans[max_n];
char a[max_n];
vector<int> g[max_n];

void calc_size(int v, int par) {
    sz[v] = 1;
    for (int to : g[v]) {
        if (to != par && !used[to]) {
            calc_size(to, v);
            sz[v] += sz[to];
        }
    }
}

int find_root(int v, int par, int tot) {
    int mx = tot - sz[v];
    for (int to : g[v]) {
        if (to != par && !used[to]) {
            int res = find_root(to, v, tot);
            if (res != -1) {
                return res;
            }
            mx = max(mx, sz[to]);
        }
    }
    if (mx * 2 <= tot) {
        return v;
    }
    return -1;
}

inline void upd(int root, int v, int x, bool simple) {
    //cout << "upd " << root << " " << v << "   " << x << ",   simple = " << simple << endl;
    tot[v][0] += x;
    tot[root][1] -= x;
    if (!simple) {
        mn[root] -= x;
    }
}

inline void check(int v, int root, int pmask, bool simple) {
    if (last[pmask] < cur) {
        return;
    }
    upd(root, v, cnt[pmask], simple);
}

bool get_bit(int mask, int pos) {
    return (bool) (mask & (1 << pos));
}

void dfs1(int v, int par, int root, int mask, bool simple) {
    mask ^= (1 << a[v]);
    if (simple && ok[mask ^ (1 << a[root])]) {
        upd(root, v, 1, simple);
    }
    check(v, root, mask, simple);
    for (int i = 0; i < 20; ++i) {
        check(v, root, mask ^ (1 << i), simple);
    }
    for (int to : g[v]) {
        if (to != par && !used[to]) {
            dfs1(to, v, root, mask, simple);
        }
    }
}

void dfs_upd(int v, int par, int mask) {
    mask ^= (1 << a[v]);
    if (last[mask] < cur) {
        last[mask] = cur;
        cnt[mask] = 0;
    }
    ++cnt[mask];
    //cout << "++" << mask << endl;
    for (int to : g[v]) {
        if (to != par && !used[to]) {
            dfs_upd(to, v, mask);
        }
    }
}

long long find_ans(int v, int par) {
    //cout << v << ": " << tot[v][0] << " " << tot[v][1] << endl;
    long long res = tot[v][0];
    for (int to : g[v]) {
        if (to != par && !used[to]) {
            res += find_ans(to, v);
        }
    }
    ans[v] += res;
    res += tot[v][1];
    tot[v][0] = tot[v][1] = 0;
    return res;
}

void rec(int v) {
    calc_size(v, -1);
    v = find_root(v, -1, sz[v]);
    ++cur;
    //cout << v << endl;
    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (used[to]) {
            continue;
        }
        //cout << "to = " << to << endl;
        dfs1(to, v, v, 0, true);
        dfs_upd(to, v, 1 << a[v]);
    }
    ++cur;
    for (int i = g[v].size() - 1; i >= 0; --i) {
        int to = g[v][i];
        if (used[to]) {
            continue;
        }
        //cout << "@to = " << to << endl;
        dfs1(to, v, v, 0, false);
        dfs_upd(to, v, 1 << a[v]);
    }
    find_ans(v, -1);
    used[v] = 1;
    for (int to : g[v]) {
        if (!used[to]) {
            rec(to);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ok[0] = 1;
    for (int i = 0; i < 20; ++i) {
        ok[1 << i] = 1;
    }
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    scanf("%s", a + 1);
    for (int i = 1; i <= n; ++i) {
        a[i] -= 'a';
    }
    rec(1);
    for (int i = 1; i <= n; ++i) {
        printf("%I64d ", ans[i] + mn[i] + 1);
    }
    printf("\n");
    return 0;
}