#include <bits/stdc++.h>

using namespace std;

const int max_n = 101111, inf = 1000111222;

struct tree {
    int a[4 * max_n];
    tree() {
        memset(a, 0, sizeof(a));
    }
    void update(int v, int l, int r, int pos, int value) {
        if (l == r) {
            a[v] = value;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) {
            update(2 * v, l, mid, pos, value);
        } else {
            update(2 * v + 1, mid + 1, r, pos, value);
        }
        a[v] = max(a[2 * v], a[2 * v + 1]);
    }
    int get_max(int v, int tl, int tr, int l, int r) {
        if (l == tl && r == tr) {
            return a[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_max(2 * v, tl, mid, l, r);
        }
        if (l > mid) {
            return get_max(2 * v + 1, mid + 1, tr, l, r);
        }
        return max(get_max(2 * v, tl, mid, l, mid), get_max(2 * v + 1, mid + 1, tr, mid + 1, r));
    }
};

int n, m, a[max_n], dp[max_n];
tree t;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        ++a[l];
        --a[r + 1];
    }
    for (int i = 1; i <= n; ++i) {
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; ++i) {
        int len = t.get_max(1, 0, m, 0, a[i]) + 1;
        t.update(1, 0, m, a[i], len);
        dp[i] = len;
    }
    t = tree();
    int ans = 0;
    for (int i = n; i >= 1; --i) {
        int len = t.get_max(1, 0, m, 0, a[i]) + 1;
        t.update(1, 0, m, a[i], len);
        ans = max(ans, dp[i] + len - 1);
    }
    printf("%d\n", ans);
    return 0;
}