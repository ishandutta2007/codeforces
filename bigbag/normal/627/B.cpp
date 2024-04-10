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

const int max_n = 222222, inf = 1111111111;

struct tree {
    int a[4 * max_n];
    tree() {
        memset(a, 0, sizeof(a));
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
        a[v] = a[2 * v] + a[2 * v + 1];
    }
    int get_sum(int v, int tl, int tr, int l, int r) {
        if (l == tl && r == tr) {
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

int n, k, a, b, q, x[max_n];
tree t1, t2;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d%d", &n, &k, &a, &b, &q);
    while (q--) {
        int tp;
        scanf("%d", &tp);
        if (tp == 1) {
            int d, cnt;
            scanf("%d%d", &d, &cnt);
            x[d] += cnt;
            t1.update(1, 1, n, d, min(x[d], b));
            t2.update(1, 1, n, d, min(x[d], a));
        } else {
            int l;
            scanf("%d", &l);
            int ans = 0;
            if (1 < l) {
                ans += t1.get_sum(1, 1, n, 1, l - 1);
            }
            if (l + k <= n) {
                ans += t2.get_sum(1, 1, n, l + k, n);
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}