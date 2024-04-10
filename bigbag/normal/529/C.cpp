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

const int max_n = 111111, inf = 111111111;

struct tree {
    int maxs[4 * max_n];
    void update(int v, int l, int r, int x, int value) {
        if (l == r) {
            maxs[v] = value;
            return;
        }
        int mid = (l + r) / 2;
        if (x <= mid) {
            update(2 * v, l, mid, x, value);
        } else {
            update(2 * v + 1, mid + 1, r, x, value);
        }
        maxs[v] = max(maxs[2 * v], maxs[2 * v + 1]);
    }
    int get_max(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return maxs[v];
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

tree t;
bool ans[2 * max_n];
int n, m, k, q, x[2 * max_n], y[2 * max_n], lx[2 * max_n], rx[2 * max_n], ly[2 * max_n], ry[2 * max_n];

struct querry {
    int lx, rx, ry, num;
    querry() {
    }
    querry(int lx, int rx, int ry, int num) : lx(lx), rx(rx), ry(ry), num(num) {
    }
};

void solve() {
    vector<int> v[max_n], a[max_n];
    int pozs[max_n];
    for (int i = 0; i < k; ++i) {
        v[x[i]].push_back(y[i]);
    }
    for (int i = 1; i <= n; ++i) {
        v[i].push_back(inf);
        sort(v[i].begin(), v[i].end());
    }
    vector<querry> qs[max_n];
    for (int i = 0; i < q; ++i) {
        qs[ly[i]].push_back(querry(lx[i], rx[i], ry[i], i));
    }
    for (int i = 1; i <= n; ++i) {
        int mn = v[i][0];
        pozs[i] = 0;
        t.update(1, 1, n, i, mn);
        if (mn != inf) {
            a[mn].push_back(i);
        }
    }
    for (int i = 1; i <= m; ++i) {
        //cout << i << " " << m << endl;
        for (int j = 0; j < qs[i].size(); ++j) {
            int mx = t.get_max(1, 1, n, qs[i][j].lx, qs[i][j].rx);
            if (mx <= qs[i][j].ry) {
                ans[qs[i][j].num] = 1;
            }
        }
        for (int j = 0; j < a[i].size(); ++j) {
            ++pozs[a[i][j]];
            int val = v[a[i][j]][pozs[a[i][j]]];
            t.update(1, 1, n, a[i][j], val);
            if (val != inf) {
                a[val].push_back(a[i][j]);
            }
        }
    }
}

int main() {
    //freopen("rvq.in", "r", stdin);
    //freopen("rvq.out", "w", stdout);
    scanf("%d%d%d%d", &n, &m, &k, &q);
    for (int i = 0; i < k; ++i) {
        scanf("%d%d", &x[i], &y[i]);
    }
    for (int i = 0; i < q; ++i) {
        scanf("%d%d%d%d", &lx[i], &ly[i], &rx[i], &ry[i]);
    }
    solve();
    swap(n, m);
    for (int i = 0; i < k; ++i) {
        swap(x[i], y[i]);
    }
    for (int i = 0; i < q; ++i) {
        swap(lx[i], ly[i]);
        swap(rx[i], ry[i]);
    }
    solve();
    for (int i = 0; i < q; ++i) {
        if (ans[i]) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}