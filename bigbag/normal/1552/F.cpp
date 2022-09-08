/**
 *  created: 25/07/2021, 19:08:11
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, mod = 998244353;

template<typename T>
struct segment_tree {
    T sum[4 * max_n];

    void build(int v, int l, int r, T a[]) {
        if (l == r) {
            sum[v] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, a);
        build(2 * v + 1, mid + 1, r, a);
        sum[v] = sum[2 * v] + sum[2 * v + 1];
    }

    void update(int v, int l, int r, int x, T value) {
        if (l == r) {
            sum[v] = value;
            return;
        }
        int mid = (l + r) / 2;
        if (x <= mid) {
            update(2 * v, l, mid, x, value);
        } else {
            update(2 * v + 1, mid + 1, r, x, value);
        }
        sum[v] = sum[2 * v] + sum[2 * v + 1];
    }

    T get_sum(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return sum[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_sum(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_sum(2 * v + 1, mid + 1, tr, l, r);
        }
        return get_sum(2 * v, tl, mid, l, mid) + get_sum(2 * v + 1, mid + 1, tr, mid + 1, r);
    }
};

struct portal {
    int x, y, tp;

    portal() {
    }

    portal(int x, int y, int tp): x(x), y(y), tp(tp) {
    }

    void read() {
        scanf("%d%d%d", &x, &y, &tp);
    }

    bool operator < (const portal &p) const {
        return x < p.x;
    }
};

int n, dp[max_n], dp2[max_n];
portal a[max_n];
segment_tree<long long> st;

void inc(int &x, int y) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        a[i].read();
    }
    int last = 0, pr_dp = 0;
    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(a, a + n, portal(a[i].y, 0, 0)) - a;
        dp2[i] = a[i].x - a[i].y;
        if (pos < i) {
            inc(dp2[i], st.get_sum(1, 0, n - 1, pos, i - 1) % mod);
        }
        st.update(1, 0, n - 1, i, dp2[i]);

        dp[i] = (a[i].x - last + pr_dp) % mod;
        if (a[i].tp) {
            inc(dp[i], dp2[i]);
        }
        last = a[i].x;
        pr_dp = dp[i];
    }
    int ans = dp[n - 1];
    inc(ans, 1);
    printf("%d\n", ans);
    return 0;
}