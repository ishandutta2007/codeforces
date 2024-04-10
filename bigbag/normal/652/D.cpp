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

struct line {
    int l, r, num;
    line() {
        l = r = num = 0;
    }
    line(int l, int r, int num) : l(l), r(r), num(num) {
    }
    bool operator < (const line &a) const {
        return l < a.l;
    }
};

struct tree {
    vector<int> a[4 * max_n];
    void build(int v, int l, int r, int x[]) {
        if (l == r) {
            a[v].push_back(x[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, x);
        build(2 * v + 1, mid + 1, r, x);
        merge(a[2 * v].begin(), a[2 * v].end(), a[2 * v + 1].begin(), a[2 * v + 1].end(), back_inserter(a[v]));
    }
    int get(int v, int tl, int tr, int l, int r, int x) {
        if (tl == l && tr == r) {
            return upper_bound(a[v].begin(), a[v].end(), x) - a[v].begin();
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get(2 * v, tl, mid, l, r, x);
        } else if (l > mid) {
            return get(2 * v + 1, mid + 1, tr, l, r, x);
        }
        return get(2 * v, tl, mid, l, mid, x) + get(2 * v + 1, mid + 1, tr, mid + 1, r, x);
    }
};

int n, x[max_n], ans[max_n];
line a[max_n];
tree t;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        a[i] = line(l, r, i);
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        x[i] = a[i].r;
    }
    t.build(1, 0, n - 1, x);
    int poz = 0;
    for (int i = 0; i < n; ++i) {
        int l = i, r = n;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (a[mid].l <= a[i].r) {
                l = mid;
            } else {
                r = mid;
            }
        }
        ans[a[i].num] = t.get(1, 0, n - 1, i, l, a[i].r) - 1;
    }
    for (int i = 0; i < n; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}