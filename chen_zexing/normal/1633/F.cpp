#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
using namespace std;
struct edge {
    int ed, id;
};
vector <edge> v[200005], e[200005];
int sz[200005], son[200005], dep[200005], top[200005], fa[200005], id[200005], w[200005], rw[200005], cnt, n, f[200005], temp_sz[200005];
vector <int> ans;
void dfs1(int x,int from,int id) {
    dep[x] = dep[from] + 1, sz[x] = 1, fa[x] = from, w[x] = id;
    for (auto t:v[x])
        if (t.ed != from) {
            dfs1(t.ed, x, t.id);
            sz[x] += sz[t.ed];
            if (sz[t.ed] > sz[son[x]]) son[x] = t.ed;
        }
}
void dfs2(int x,int ttop) {
    top[x] = ttop, id[x] = ++cnt, rw[id[x]] = w[x];
    if (son[x]) dfs2(son[x], ttop);
    for (auto t:v[x]) if (t.ed != son[x] && t.ed != fa[x]) dfs2(t.ed, t.ed);
}
struct Seg_tree {
    long long sum[800005], cnt[800005], lz[800005], pre[200005];

    void build(int node, int l, int r) {
        if (node == 1) for (int i = l; i <= r; i++) pre[i] = pre[i - 1] + rw[i];
        if (l == r) {
            sum[node] = 0, cnt[node] = l == 1;
            return;
        }
        int mid = (l + r) >> 1;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
        sum[node] = sum[node * 2] + sum[node * 2 + 1], cnt[node] = cnt[node * 2] + cnt[node * 2 + 1];
    }

    void pushdown(int node, int l, int r) {
        if (lz[node]) {
            int mid = (l + r) >> 1;
            sum[node * 2] = pre[mid] - pre[l - 1] - sum[node * 2], sum[node * 2 + 1] =
                                                                           pre[r] - pre[mid] - sum[node * 2 + 1];
            cnt[node * 2] = -cnt[node * 2], cnt[node * 2 + 1] = -cnt[node * 2 + 1];
            lz[node * 2] ^= 1, lz[node * 2 + 1] ^= 1, lz[node] = 0;
        }
    }

    void flip(int node, int l, int r, int L, int R) {
        if (l >= L && r <= R) {
            sum[node] = pre[r] - pre[l - 1] - sum[node], cnt[node] = -cnt[node], lz[node] ^= 1;
            return;
        }
        pushdown(node, l, r);
        int mid = (l + r) >> 1;
        if (mid >= L) flip(node * 2, l, mid, L, R);
        if (mid < R) flip(node * 2 + 1, mid + 1, r, L, R);
        sum[node] = sum[node * 2] + sum[node * 2 + 1], cnt[node] = cnt[node * 2] + cnt[node * 2 + 1];
    }

    void insert(int node, int l, int r, int pos) {
        if (l == r) {
            sum[node] = rw[l], cnt[node] = 1;
            return;
        }
        pushdown(node, l, r);
        int mid = (l + r) >> 1;
        if (pos <= mid) insert(node * 2, l, mid, pos);
        else insert(node * 2 + 1, mid + 1, r, pos);
        sum[node] = sum[node * 2] + sum[node * 2 + 1], cnt[node] = cnt[node * 2] + cnt[node * 2 + 1];
    }
}seg_tree;
void flip_path(int x) {
    while (top[x] != top[1]) {
        seg_tree.flip(1, 1, n, id[top[x]], id[x]);
        x = fa[top[x]];
    }
    seg_tree.flip(1, 1, n, id[1], id[x]);
}
void add(int x) {
    flip_path(fa[x]);
    seg_tree.insert(1, 1, n, id[x]), f[x] = 1;
    if (seg_tree.cnt[1] == 0) printf("%lld\n", seg_tree.sum[1]);
    else puts("0");
    fflush(stdout);
}
void count_sz(int x) {
    temp_sz[x] = 1;
    for (auto t:v[x]) if (t.ed != fa[x] && f[t.ed]) count_sz(t.ed), temp_sz[x] += temp_sz[t.ed];
}
void solve(int x) {
    for (auto t:v[x])
        if (t.ed != fa[x] && f[t.ed]) {
            solve(t.ed);
            if (temp_sz[t.ed] % 2 && temp_sz[x] % 2 == 0) ans.push_back(t.id);
        }
}
void query() {
    if (seg_tree.cnt[1]) puts("0");
    else {
        ans.clear();
        count_sz(1);
        solve(1);
        sort(ans.begin(), ans.end());
        printf("%d ", ans.size());
        for (auto t:ans) printf("%d ", t);
        puts("");
    }
    fflush(stdout);
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        f[1] = 1;
        cin >> n;
        for (int i = 1, x, y; i < n; i++) {
            scanf("%d%d", &x, &y);
            v[x].push_back(edge{y, i}), v[y].push_back(edge{x, i});
        }
        dfs1(1, 0, 0), dfs2(1, 1);
        seg_tree.build(1, 1, n);
        int type;
        while (1) {
            scanf("%d", &type);
            if (type == 1) {
                int x;
                scanf("%d", &x);
                add(x);
            }
            else if (type == 2) query();
            else break;
        }
    }
    return 0;
}
//unordered_map