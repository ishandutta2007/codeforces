#include <bits/stdc++.h>

using namespace std;

const int max_n = 200111, inf = 1000111222;

struct segment_tree {
    int f[4 * max_n];
    long long sum[4 * max_n];
    int mn[4 * max_n];

    void pull(int v) {
        sum[v] = sum[2 * v] + sum[2 * v + 1];
        mn[v] = min(mn[2 * v], mn[2 * v + 1]);
    }

    void build(int v, int l, int r, int a[]) {
        f[v] = 0;
        if (l == r) {
            sum[v] = mn[v] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, a);
        build(2 * v + 1, mid + 1, r, a);
        pull(v);
    }

    void push(int v, int l, int r, int mid) {
        if (f[v]) {
            mn[2 * v] = f[v];
            mn[2 * v + 1] = f[v];
            sum[2 * v] = 1LL * f[v] * (mid - l + 1);
            sum[2 * v + 1] = 1LL * f[v] * (r - mid);
            f[2 * v] = f[v];
            f[2 * v + 1] = f[v];
            f[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, int value) {
        if (tl == l && tr == r) {
            f[v] = value;
            mn[v] = value;
            sum[v] = 1LL * value * (r - l + 1);
            return;
        }
        int mid = (tl + tr) / 2;
        push(v, tl, tr, mid);
        if (r <= mid) {
            update(2 * v, tl, mid, l, r, value);
        } else if (l > mid) {
            update(2 * v + 1, mid + 1, tr, l, r, value);
        } else {
            update(2 * v, tl, mid, l, mid, value);
            update(2 * v + 1, mid + 1, tr, mid + 1, r, value);
        }
        pull(v);
    }

    int first_smaller_eq(int v, int tl, int tr, int x) {
        if (mn[v] > x) {
            return max_n;
        }
        if (tl == tr) {
            return tl;
        }
        int mid = (tl + tr) / 2;
        push(v, tl, tr, mid);
        int res = first_smaller_eq(2 * v, tl, mid, x);
        if (res != max_n) {
            return res;
        }
        return first_smaller_eq(2 * v + 1, mid + 1, tr, x);
    }

    pair<int, int> sum_smaller_eq(int v, int tl, int tr, int pos, int x) {
        //cout << "#(" << v << " " << tl << " " << tr << " " << pos << " " << x << ")" << endl;
        if (pos <= tl && sum[v] <= x) {
            return {sum[v], tr + 1};
        }
        if (tl == tr) {
            //assert(pos <= tl);
            return {0, tl};
        }
        int mid = (tl + tr) / 2;
        push(v, tl, tr, mid);
        if (mid < pos) {
            return sum_smaller_eq(2 * v + 1, mid + 1, tr, pos, x);
        }
        auto res = sum_smaller_eq(2 * v, tl, mid, pos, x);
        if (res.second == mid + 1) {
            auto res2 = sum_smaller_eq(2 * v + 1, mid + 1, tr, pos, x - res.first);
            res2.first += res.first;
            return res2;
        }
        return res;
    }
};

int n, q, a[max_n];
segment_tree t;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    t.build(1, 0, n - 1, a);
    while (q--) {
        int tp, x, y;
        scanf("%d%d%d", &tp, &x, &y);
        --x;
        if (tp == 1) {
            int pos = t.first_smaller_eq(1, 0, n - 1, y);
            if (pos <= x) {
                t.update(1, 0, n - 1, pos, x, y);
            }
        } else {
            int pos = t.first_smaller_eq(1, 0, n - 1, y);
            pos = max(pos, x);
            int ans = 0;
            while (pos < n) {
                auto p = t.sum_smaller_eq(1, 0, n - 1, pos, y);
                int nxt = p.second - 1;
                //cout << "[" << pos << " " << nxt << "] ";
                ans += nxt - pos + 1;
                if (nxt + 1 == n) {
                    break;
                }
                y -= p.first;
                //cout << "$" << y << "$ ";
                pos = t.first_smaller_eq(1, 0, n - 1, y);
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}