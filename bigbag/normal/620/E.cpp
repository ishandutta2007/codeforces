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

int n, m, cnt, last, l[max_n], r[max_n], a[max_n], poz[max_n];
long long t[4 * max_n], f[4 * max_n];
vector<int> g[max_n];

void dfs(int v, int p) {
    l[v] = cnt;
    last = cnt;
    poz[cnt] = v - 1;
    ++cnt;
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != p) {
            dfs(g[v][i], v);
        }
    }
    r[v] = last;
}

void build(int v, int l, int r) {
    if (l == r) {
        t[v] = (1LL << a[poz[l]]);
        return;
    }
    int mid = (l + r) / 2;
    build(2 * v, l, mid);
    build(2 * v + 1, mid + 1, r);
    t[v] = t[2 * v] | t[2 * v + 1];
}

void push(int v) {
    if (f[v] != -1) {
        f[2 * v] = f[v];
        f[2 * v + 1] = f[v];
        t[2 * v] = f[v];
        t[2 * v + 1] = f[v];
        f[v] = -1;
    }
}

void update(int v, int tl, int tr, int l, int r, int col) {
    if (tl == l && tr == r) {
        t[v] = (1LL << col);
        f[v] = t[v];
        return;
    }
    push(v);
    int mid = (tl + tr) / 2;
    if (r <= mid) {
        update(2 * v, tl, mid, l, r, col);
    } else if (l > mid) {
        update(2 * v + 1, mid + 1, tr, l, r, col);
    } else {
        update(2 * v, tl, mid, l, mid, col);
        update(2 * v + 1, mid + 1, tr, mid + 1, r, col);
    }
    t[v] = t[2 * v] | t[2 * v + 1];
}

long long get(int v, int tl, int tr, int l, int r) {
    if (tl == l && tr == r) {
        return t[v];
    }
    push(v);
    int mid = (tl + tr) / 2;
    if (r <= mid) {
        return get(2 * v, tl, mid, l, r);
    } else if (l > mid) {
        return get(2 * v + 1, mid + 1, tr, l, r);
    }
    return get(2 * v, tl, mid, l, mid) | get(2 * v + 1, mid + 1, tr, mid + 1, r);
}

int cnt_bits(long long mask) {
    int res = 0;
    while (mask) {
        mask = (mask & (mask - 1));
        ++res;
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    build(1, 0, n - 1);
    memset(f, -1, sizeof(f));
    while (m--) {
        int tp;
        scanf("%d", &tp);
        if (tp == 1) {
            int v, col;
            scanf("%d%d", &v, &col);
            update(1, 0, n - 1, l[v], r[v], col);
        } else {
            int v;
            scanf("%d", &v);
            long long mask = get(1, 0, n - 1, l[v], r[v]);
            printf("%d\n", cnt_bits(mask));
        }
    }
    return 0;
}