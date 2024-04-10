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

const int max_n = 303333, inf = 1011111111;

long long a[max_n];

struct state {
    int res, a, b, c, d, len;
    state() {
        res = a = b = c = d = len = 0;
    }
    state(int res, int a, int b, int c, int d, int len) : res(res), a(a), b(b), c(c), d(d), len(len) {
    }
    void write() {
        printf("res = %d a = %d b = %d  c = %d  d = %d   len = %d\n", res, a, b, c, d, len);
    }
};

state merge(state x, state y, int v) {
    state z;
    z.res = max(x.res, y.res);
    if (a[v] != 0) {
        z.res = max(z.res, x.b + y.a);
    }
    if (a[v] < 0) {
        z.res = max(z.res, x.c + y.a);
    }
    if (a[v] > 0) {
        z.res = max(z.res, x.b + y.d);
    }

    if (a[v] < 0 && y.a == y.len) {
        z.c = x.c + y.a;
    }
    if (a[v] > 0 && y.d == y.len) {
        z.c = max(z.c, x.b + y.d);
    }

    if (a[v] > 0 && x.b == x.len) {
        z.d = x.b + y.d;
    }
    if (a[v] < 0 && x.d == x.len) {
        z.d = max(z.d, x.d + y.a);
    }

    if (y.b == y.len && a[v] > 0) {
        z.b = x.b + y.b;
    } else {
        z.b = y.b;
    }

    if (x.a == x.len && a[v] < 0) {
        z.a = x.a + y.a;
    } else {
        z.a = x.a;
    }
    z.len = x.len + y.len;
    z.c = max(z.c, z.b);
    z.c = max(z.c, y.c);
    z.d = max(z.d, x.d);
    return z;
}

struct Tree {
    state a[4 * max_n];
    Tree() {
    }
    void build(int v, int l, int r) {
        if (l == r) {
            a[v] = state(1, 1, 1, 1, 1, 1);
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
        a[v] = merge(a[2 * v], a[2 * v + 1], mid + 1);
        //cout << v << " [" << l << " " << r << "] : ";
        //a[v].write();
    }
    void update(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return;
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            update(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            update(2 * v + 1, mid + 1, tr, l, r);
        } else {
            update(2 * v, tl, mid, l, mid);
            update(2 * v + 1, mid + 1, tr, mid + 1, r);
        }
        a[v] = merge(a[2 * v], a[2 * v + 1], mid + 1);
    }
    state get(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return a[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get(2 * v + 1, mid + 1, tr, l, r);
        }
        return merge(get(2 * v, tl, mid, l, mid), get(2 * v + 1, mid + 1, tr, mid + 1, r), mid + 1);
    }
};

int n, m;
Tree t;

int solve() {
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        int j = i;
        int f = 0, len = 1;
        while (i + 1 <= n && a[i + 1] > 0) {
            ++len;
            ++i;
        }
        while (i + 1 <= n && a[i + 1] < 0) {
            ++len;
            ++i;
        }
        res = max(res, len);
        i = j;
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%I64d", &a[i]);
    }
    for (int i = n; i > 0; --i) {
        a[i] -= a[i - 1];
    }
    t.build(1, 1, n);
    state ans = t.get(1, 1, n, 1, n);
    scanf("%d", &m);
    while (m--) {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        a[l] += x;
        a[r + 1] -= x;
        t.update(1, 1, n, l, l);
        if (r + 1 <= n) {
            t.update(1, 1, n, r + 1, r + 1);
        }
        state ans = t.get(1, 1, n, 1, n);
        printf("%d\n", ans.res);
    }
    return 0;
}