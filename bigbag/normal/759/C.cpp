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

const int max_n = 111111, inf = 1011111111;

struct tree {
    int a[4 * max_n], f[4 * max_n];
    tree() {
        memset(a, 0, sizeof(a));
        memset(f, 0, sizeof(f));
    }
    void push(int v, int l, int r) {
        if (f[v] != 0) {
            f[2 * v] += f[v];
            f[2 * v + 1] += f[v];
            a[2 * v] += f[v];
            a[2 * v + 1] += f[v];
            f[v] = 0;
        }
    }
    void update(int v, int tl, int tr, int l, int r, int value) {
        if (tl == l && tr == r) {
            f[v] += value;
            a[v] += value;
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
        a[v] = max(a[2 * v], a[2 * v + 1]);
    }
    int get(int v, int l, int r) {
        if (l == r) {
            return l;
        }
        push(v, l, r);
        int mid = (l + r) / 2;
        if (a[2 * v + 1] > 0) {
            return get(2 * v + 1, mid + 1, r);
        }
        return get(2 * v, l, mid);
    }
    void write(int v, int l, int r) {
        if (l == r) {
            cout << l << ' ' << r << " - " << a[v] << " (" << f[v] << ")\n";
            return;
        }
        cout << l << ' ' << r << " - " << a[v] << " (" << f[v] << ")\n";
        int mid = (l + r) / 2;
        write(2 * v, l, mid);
        write(2 * v + 1, mid + 1, r);
    }
};

int n, a[max_n];
tree t;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int pos, tp;
        scanf("%d%d", &pos, &tp);
        if (tp == 1) {
            scanf("%d", &a[pos]);
        }
        if (tp == 0) {
            t.update(1, 1, n, 1, pos, -1);
        } else {
            t.update(1, 1, n, 1, pos, 1);
        }
        //cout << "upd " << 1 << " " << pos << " : " << endl;
        //t.write(1, 1, n);
        if (t.a[1] <= 0) {
            printf("-1\n");
        } else {
            printf("%d\n", a[t.get(1, 1, n)]);
        }
    }
    return 0;
}