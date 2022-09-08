#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222;
const long long inf = 1000111222000111222LL;

struct tree {
    long long mx[4 * max_n], add[4 * max_n];

    tree() {
        memset(mx, 0, sizeof(mx));
        memset(add, 0, sizeof(add));
    }

    void push(int v) {
        if (add[v]) {
            mx[2 * v] += add[v];
            mx[2 * v + 1] += add[v];
            add[2 * v] += add[v];
            add[2 * v + 1] += add[v];
            add[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, long long x) {
        if (tl == l && tr == r) {
            add[v] += x;
            mx[v] += x;
            return;
        }
        push(v);
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            update(2 * v, tl, mid, l, r, x);
        } else if (l > mid) {
            update(2 * v + 1, mid + 1, tr, l, r, x);
        } else {
            update(2 * v, tl, mid, l, mid, x);
            update(2 * v + 1, mid + 1, tr, mid + 1, r, x);
        }
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    }

    int get_more(int v, int l, int r, long long x) {
        if (l == r) {
            return l;
        }
        push(v);
        int mid = (l + r) / 2;
        if (mx[2 * v] >= x) {
            return get_more(2 * v, l, mid, x);
        }
        return get_more(2 * v + 1, mid + 1, r, x);
    }
};

int n, ans[max_n];
long long s[max_n];
tree t;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", &s[i]);
    }
    for (int i = 1; i < n; ++i) {
        t.update(1, 1, n, i + 1, n, i);
    }
    for (int i = n - 1; i >= 0; --i) {
        ans[i] = t.get_more(1, 1, n, s[i]);
        t.update(1, 1, n, ans[i], ans[i], -inf);
        if (ans[i] + 1 < n) {
            t.update(1, 1, n, ans[i] + 1, n, -ans[i]);
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", ans[i]);
    }
    puts("");
    return 0;
}