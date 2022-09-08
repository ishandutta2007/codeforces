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

const int max_n = 202222, inf = 1111111111;

struct querry {
    int k, z, x;
    querry() {
    }
    querry(int k, int z, int x) : k(k), z(z), x(x) {
    }
};

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

int n, a[max_n], b[max_n], ans[max_n];
map<int, int> mmm;
vector<querry> q[max_n];
tree t;

int get_cnt(int x) {
    if (x == 1) {
        return 0;
    }
    return t.get_sum(1, 1, n, 1, x - 1);
}

void proc() {
    for (int i = 1; i <= n; ++i) {
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    int cnt = 1;
    for (int i = 1; i <= n; ++i) {
        while (i + 1 <= n && b[i] == b[i + 1]) {
            ++i;
        }
        mmm[b[i]] = cnt;
        ++cnt;
    }
    for (int i = 1; i <= n; ++i) {
        a[i] = mmm[a[i]];
        //cout << a[i] << " ";
    }
    //cout << endl;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    proc();
    for (int k = 1; k < n; ++k) {
        for (int j = 2; j <= n; j += k) {
            int l = j;
            int r = min(j + k - 1, n);
            int x = a[(j - 2) / k + 1];
            q[l - 1].push_back(querry(k, -1, x));
            q[r].push_back(querry(k, 1, x));
        }
    }
    for (int i = 1; i <= n; ++i) {
        t.update(1, 1, n, a[i], 1);
        for (int j = 0; j < q[i].size(); ++j) {
            int cnt = get_cnt(q[i][j].x);
            ans[q[i][j].k] += cnt * q[i][j].z;
        }
    }
    for (int i = 1; i < n; ++i) {
        printf("%d ", ans[i]);
    }
    return 0;
}