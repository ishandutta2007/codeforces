#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
long long tree[2000005], lz[2000005], a[500005];
int n, sz[500005];
void build(int node,int l,int r) {
    if (l == r) {
        tree[node] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
void pushdown(int node,int l,int r) {
    if (l == r) return;
    tree[node * 2] += lz[node];
    tree[node * 2 + 1] += lz[node];
    lz[node * 2] += lz[node], lz[node * 2 + 1] += lz[node], lz[node] = 0;
}
void update(int node,int l,int r,int L,int R,int v) {
    if (L > R) return;
    if (l >= L && r <= R) {
        tree[node] += v;
        lz[node] += v;
        return;
    }
    pushdown(node, l, r);
    int mid = (l + r) >> 1;
    if (mid >= L) update(node * 2, l, mid, L, R, v);
    if (mid < R) update(node * 2 + 1, mid + 1, r, L, R, v);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
long long query(int node,int l,int r,int L,int R) {
    if (l >= L && r <= R) {
        return tree[node];
    }
    pushdown(node, l, r);
    int mid = (l + r) >> 1;
    long long ans = LLONG_MAX;
    if (mid >= L) ans = min(ans, query(node * 2, l, mid, L, R));
    if (mid < R) ans = min(ans, query(node * 2 + 1, mid + 1, r, L, R));
    return ans;
}
struct qry {
    int l, r, id;
};
struct edge {
    int ed, w;
};
vector <edge> v[500005];
vector <qry> q[500005];
long long ans[500005];
void dfs1(int x,int from,long long now) {
    a[x] = v[x].size() == 1 ? now : LLONG_MAX / 2;
    sz[x] = 1;
    for (int i = 0; i < v[x].size(); i++)
        if (v[x][i].ed != from)
            dfs1(v[x][i].ed, x, now + v[x][i].w), sz[x] += sz[v[x][i].ed];
}
void dfs2(int x,int from) {
    for (int i = 0; i < q[x].size(); i++) ans[q[x][i].id] = query(1, 1, n, q[x][i].l, q[x][i].r);
    for (int i = 0; i < v[x].size(); i++) {
        if (v[x][i].ed != from) {
            update(1, 1, n, v[x][i].ed, v[x][i].ed + sz[v[x][i].ed] - 1, -v[x][i].w);
            update(1, 1, n, 1, v[x][i].ed - 1, v[x][i].w);
            update(1, 1, n, v[x][i].ed + sz[v[x][i].ed], n, v[x][i].w);
            dfs2(v[x][i].ed, x);
            update(1, 1, n, v[x][i].ed, v[x][i].ed + sz[v[x][i].ed] - 1, v[x][i].w);
            update(1, 1, n, 1, v[x][i].ed - 1, -v[x][i].w);
            update(1, 1, n, v[x][i].ed + sz[v[x][i].ed], n, -v[x][i].w);
        }
    }
}
int main() {
    int qq;
    cin >> n >> qq;
    int x, y, w, l, r;
    for (int i = 2; i <= n; i++) {
        scanf("%d%d", &x, &w);
        y = i;
        v[x].push_back(edge{y, w});
        v[y].push_back(edge{x, w});
    }
    for (int i = 1; i <= qq; i++) {
        scanf("%d%d%d", &x, &l, &r);
        q[x].push_back(qry{l, r, i});
    }
    dfs1(1, 0, 0);
    build(1, 1, n);
    dfs2(1, 0);
    for (int i = 1; i <= qq; i++) printf("%lld\n", ans[i]);
    return 0;
}