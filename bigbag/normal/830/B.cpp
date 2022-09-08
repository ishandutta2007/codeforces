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

const int max_n = 100011, inf = 1011111111;

struct tree1 {
    pair<int, int> mins[4 * max_n];
    void build(int v, int tl, int tr) {
        mins[v] = make_pair(0, tl);
        if (tl == tr) {
            return;
        }
        int mid = (tl + tr) / 2;
        build(2 * v, tl, mid);
        build(2 * v + 1, mid + 1, tr);
    }
    void update(int v, int l, int r, int x, int value) {
        if (l == r) {
            mins[v] = make_pair(value, l);
            return;
        }
        int mid = (l + r) / 2;
        if (x <= mid) {
            update(2 * v, l, mid, x, value);
        } else {
            update(2 * v + 1, mid + 1, r, x, value);
        }
        mins[v] = min(mins[2 * v], mins[2 * v + 1]);
    }
    pair<int, int> get_min(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return make_pair(inf, inf);
        }
        if (tl == l && tr == r) {
            return mins[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_min(2 * v, tl, mid, l, r);
        }
        if (l > mid) {
            return get_min(2 * v + 1, mid + 1, tr, l, r);
        }
        return min(get_min(2 * v, tl, mid, l, mid), get_min(2 * v + 1, mid + 1, tr, mid + 1, r));
    }
};

struct tree2 {
    int a[4 * max_n];
    tree2() {
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
        if (l > r) {
            return 0;
        }
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

int n, a[max_n];
tree1 t1;
tree2 t2;
long long ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    t1.build(1, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        t1.update(1, 0, n - 1, i, a[i]);
        t2.update(1, 0, n - 1, i, 1);
    }
    int last = 0;
    for (int i = 0; i < n; ++i) {
        pair<int, int> global_mn = t1.get_min(1, 0, n - 1, 0, n - 1);
        pair<int, int> mn_r = t1.get_min(1, 0, n - 1, last, n - 1);
        int pos;
        if (mn_r.first == global_mn.first) {
            pos = mn_r.second;
            ans += t2.get_sum(1, 0, n - 1, last, pos);
        } else {
            pair<int, int> mn_l = t1.get_min(1, 0, n - 1, 0, last);
            pos = mn_l.second;
            ans += t2.get_sum(1, 0, n - 1, last, n - 1);
            ans += t2.get_sum(1, 0, n - 1, 0, pos);
        }
        //cout << i << " " << pos << "   " << ans << endl;
        t1.update(1, 0, n - 1, pos, inf);
        t2.update(1, 0, n - 1, pos, 0);
        last = pos;
    }
    cout << ans << endl;
    return 0;
}