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

const int max_n = 1000001, inf = 1111111111;

struct tree {
    int a[4 * max_n];
    tree() {
        memset(a, 0, sizeof(a));
    }
    void update(int v, int l, int r, int x, int value) {
        if (l == r) {
            a[v] += value;
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

int n, a[max_n], dp1[max_n], dp2[max_n];
map<int, int> m;
tree t;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (!m.count(a[i])) {
            dp1[i] = 1;
        } else {
            dp1[i] = dp1[m[a[i]]] + 1;
        }
        m[a[i]] = i;
    }
    m.clear();
    for (int i = n - 1; i >= 0; --i) {
        if (!m.count(a[i])) {
            dp2[i] = 1;
        } else {
            dp2[i] = dp2[m[a[i]]] + 1;
        }
        m[a[i]] = i;
    }
    for (int i = 1; i < n; ++i) {
        t.update(1, 1, n, dp2[i], 1);
    }
    long long ans = 0;
    for (int i = 0; i + 1 < n; ++i) {
        if (dp1[i] > 1) {
            ans += t.get_sum(1, 1, n, 1, dp1[i] - 1);
        }
        t.update(1, 1, n, dp2[i + 1], -1);
    }
    cout << ans << endl;
    return 0;
}