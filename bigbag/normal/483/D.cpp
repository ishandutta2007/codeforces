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

const int max_n = 101111, max_lev = 20, inf = 1111111111;

struct tree {
    int a[7 * max_n], f[7 * max_n];
    tree() {
        memset(f, 0, sizeof(f));
        memset(a, 0, sizeof(a));
    }
    void push(int v) {
        if (f[v] != 0) {
            f[2 * v] |= f[v];
            f[2 * v + 1] |= f[v];
            a[2 * v] |= f[v];
            a[2 * v + 1] |= f[v];
            f[v] = 0;
        }
    }
    void update(int v, int tl, int tr, int l, int r, long long value) {
        push(v);
        if (tl == l && tr == r) {
            a[v] |= value;
            f[v] = value;
            return;
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            update(2 * v, tl, mid, l, r, value);
        } else if (l > mid) {
            update(2 * v + 1, mid + 1, tr, l, r, value);
        } else {
            update(2 * v, tl, mid, l, mid, value);
            update(2 * v + 1, mid + 1, tr, mid + 1, r, value);
        }
        a[v] = a[2 * v] | a[2 * v + 1];
    }
    int get_x(int v, int l, int r, int poz) {
        if (l == r) {
            return a[v];
        }
        push(v);
        int mid = (l + r) / 2;
        if (poz <= mid) {
            return get_x(2 * v, l, mid, poz);
        }
        return get_x(2 * v + 1, mid + 1, r, poz);
    }
};

int n, m, l[max_n], r[max_n], q[max_n], ans[max_n];
tree t;

int maxs[max_lev][max_n], num[max_n];

void get_all_maxs() {
    for (int i = 1; i <= n; ++i) {
        maxs[0][i] = ans[i];
    }
    for (int i = 1; i < max_lev; ++i) {
        for (int j = 1; j <= n && j + (1 << (i - 1)) <= n; ++j) {
            maxs[i][j] = maxs[i - 1][j] & maxs[i - 1][j + (1 << (i - 1))];
        }
    }
    for (int i = 1, x = 0; i <= n; i *= 2, ++x) {
        for (int j = i; j <= n && j < i * 2; ++j) {
            num[j] = x;
        }
    }
}

int get_max(int l, int r) {
    if (l > r) {
        return -inf;
    }
    int lev = num[r - l + 1];
    return maxs[lev][l] & maxs[lev][r - (1 << lev) + 1];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &l[i], &r[i], &q[i]);
        t.update(1, 1, n, l[i], r[i], q[i]);
    }
    for (int i = 1; i <= n; ++i) {
        ans[i] = t.get_x(1, 1, n, i);
    }
    get_all_maxs();
    for (int i = 0; i < m; ++i) {
        if (get_max(l[i], r[i]) != q[i]) {
            if (n < 1000000) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}