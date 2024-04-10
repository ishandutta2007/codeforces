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

const int max_n = 111111, inf = 111111111;

struct tree {
    long long a[7 * max_n], f[7 * max_n];
    tree() {
        memset(a, 0, sizeof(a));
        memset(f, 0, sizeof(f));
    }
    void push(int v, int l, int r) {
        if (f[v] != 0) {
            f[2 * v] = f[2 * v] + f[v];
            f[2 * v + 1] = f[2 * v + 1] + f[v];
            int mid = (l + r) / 2;
            a[2 * v] = a[2 * v] + (mid - l + 1) * f[v];
            a[2 * v + 1] = a[2 * v + 1] + (r - mid) * f[v];
            a[v] = a[2 * v] + a[2 * v + 1];
            f[v] = 0;
        }
    }
    void update(int v, int tl, int tr, int l, int r, long long value) {
        if (tl == l && tr == r) {
            a[v] = (a[v] + (r - l + 1) * value);
            f[v] = (f[v] + value);
            return;
        }
        push(v, tl, tr);
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            update(2 * v, tl, mid, l, r, value);
        } else if (l > mid) {
            update(2 * v + 1, mid + 1, tr, l, r, value);
        } else {
            update(2 * v, tl, mid, l, mid, value);
            update(2 * v + 1, mid + 1, tr, mid + 1, r, value);
        }
        a[v] = (a[2 * v] + a[2 * v + 1]);
    }
    long long get_sum(int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (tl == l && tr == r) {
            return a[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_sum(2 * v, tl, mid, l, r);
        }
        if (l > mid) {
            return get_sum(2 * v + 1, mid + 1, tr, l, r);
        }
        return get_sum(2 * v, tl, mid, l, mid) + get_sum(2 * v + 1, mid + 1, tr, mid + 1, r);
    }
};

int n, m, k;
tree t1, t2, t3;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int l, r, x;
        cin >> l >> r >> x;
        t1.update(1, 1, n, l, r, x);
        t2.update(1, 1, n, l, r, l);
        t3.update(1, 1, n, l, r, 1);
    }
    long long ans = 0;
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        ans += t1.get_sum(1, 1, n, x, x) + t3.get_sum(1, 1, n, x, x) * x - t2.get_sum(1, 1, n, x, x);
        //cout << t1.get_sum(1, 1, n, x, x) << ' ' << t3.get_sum(1, 1, n, x, x) * x << ' ' << t2.get_sum(1, 1, n, x, x) << endl;
    }
    cout << ans << endl;
    return 0;
}