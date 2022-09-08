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

const int max_n = 500555, inf = 1011111111;

struct tree {
    int a[4 * max_n];
    tree() {
        memset(a, 0, sizeof(a));
    }
    void build(int v, int l, int r, int arr[]) {
        if (l == r) {
            a[v] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, arr);
        build(2 * v + 1, mid + 1, r, arr);
        a[v] = __gcd(a[2 * v], a[2 * v + 1]);
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
        a[v] = __gcd(a[2 * v], a[2 * v + 1]);
    }
    int get(int v, int tl, int tr, int pos, int g) {
        //cout << v << " " << tl << " " << tr << ", a[v] = " << a[v] << "    " << pos << " " << g << endl;
        if (a[v] % g == 0) {
            return -1;
        }
        if (tl == tr) {
            return tl;
        }
        int mid = (tl + tr) / 2;
        if (pos <= mid) {
            int res = get(2 * v, tl, mid, pos, g);
            if (res != -1) {
                return res;
            }
            return get(2 * v + 1, mid + 1, tr, mid + 1, g);
        } else {
            return get(2 * v + 1, mid + 1, tr, pos, g);
        }
    }
};

int n, a[max_n], q;
tree t;

bool check(int l, int r, int x) {
    int pos = t.get(1, 0, n - 1, l, x);
    if (pos == -1 || pos + 1 == n) {
        return true;
    }
    pos = t.get(1, 0, n - 1, pos + 1, x);
    return pos == -1 || pos > r;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    t.build(1, 0, n - 1, a);
    scanf("%d", &q);
    while (q--) {
        int tp;
        scanf("%d", &tp);
        if (tp == 1) {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            --l;
            --r;
            if (check(l, r, x)) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        } else {
            int pos, x;
            scanf("%d%d", &pos, &x);
            --pos;
            t.update(1, 0, n - 1, pos, x);
        }
    }
    return 0;
}