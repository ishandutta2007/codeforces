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

const int max_n = 555555, inf = 1111111111;

struct tree {
    int a, l, r;
    tree() {
        a = inf;
        l = r = 0;
    }
    tree(int x) {
        a = x;
        l = r = 0;
    }
};

const int max_m = 11111111;

int C;
tree t[max_m];

int get_min(int num) {
    if (num == 0) {
        return inf;
    }
    return t[num].a;
}

int build(int l, int r) {
    ++C;
    int res = C;
    t[res] = tree();
    if (l == r) {
        return res;
    }
    int mid = (l + r) / 2;
    t[res].l = build(l, mid);
    t[res].r = build(mid + 1, r);
    return res;
}

int update(int v, int tl, int tr, int x, int value) {
    ++C;
    int res = C;
    t[res] = tree();
    t[res].l = t[v].l;
    t[res].r = t[v].r;
    if (tl == tr) {
        t[res] = tree(min(value, t[v].a));
        return res;
    }
    int mid = (tl + tr) / 2;
    if (x <= mid) {
        t[res].l = update(t[v].l, tl, mid, x, value);
    } else {
        t[res].r = update(t[v].r, mid + 1, tr, x, value);
    }
    t[res].a = min(get_min(t[res].l), get_min(t[res].r));
    return res;
}

int get_min(int v, int tl, int tr, int l, int r) {
    if (tl == l && tr == r) {
        return get_min(v);
    }
    int mid = (tl + tr) / 2;
    if (r <= mid) {
        return get_min(t[v].l, tl, mid, l, r);
    }
    if (l > mid) {
        return get_min(t[v].r, mid + 1, tr, l, r);
    }
    return min(get_min(t[v].l, tl, mid, l, mid), get_min(t[v].r, mid + 1, tr, mid + 1, r));
}

int n, m, a[max_n], y[max_n];
map<int, int> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    build(0, n - 1);
    y[n] = 1;
    for (int i = n - 1; i >= 0; --i) {
        if (q.count(a[i])) {
            int poz = q[a[i]];
            y[i] = update(y[i + 1], 0, n - 1, poz, poz - i);
        } else {
            y[i] = y[i + 1];
        }
        q[a[i]] = i;
    }
    for (int i = 0; i < m; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        --l;
        --r;
        int ans = get_min(y[l], 0, n - 1, l, r);
        if (ans == inf) {
            ans = -1;
        }
        printf("%d\n", ans);
    }
    return 0;
}