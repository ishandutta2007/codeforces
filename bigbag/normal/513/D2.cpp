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

const int max_n = 1111111, inf = 1111111111;

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

int n, c, p[max_n], mx[max_n], mn[max_n], mxl[max_n], used[max_n];
tree t;
string s;
vector<int> g[2][max_n], q[2][max_n], rg[max_n];

void error() {
    cout << "IMPOSSIBLE" << endl;
    exit(0);
}

void get_ans(int v, int mxx) {
    if (v == mxl[v]) {
        if (v < mxx) {
            g[1][v].push_back(v + 1);
            get_ans(v + 1, mxx);
        }
        return;
    }
    g[0][v].push_back(v + 1);
    get_ans(v + 1, mxl[v]);
    if (mxl[v] + 1 > mn[v]) {
        error();
    }
    if (mxl[v] + 1 > mxx) {
        if (mxl[v] == mxx) {
            return;
        }
        error();
    }
    g[1][v].push_back(mxl[v] + 1);
    get_ans(mxl[v] + 1, mxx);
}

void write(int v) {
    if (g[0][v].size()) {
        write(g[0][v][0]);
    }
    cout << v << " ";
    if (g[1][v].size()) {
        write(g[1][v][0]);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> c;
    for (int i = 0; i < c; ++i) {
        int u, v;
        cin >> u >> v >> s;
        if (u == v) {
            error();
        }
        if (s == "LEFT") {
            q[0][u].push_back(v);
        } else {
            q[1][u].push_back(v);
        }
        rg[v].push_back(u);
    }
    mx[n] = n;
    mxl[n] = n;
    t.update(1, 1, n, n, mx[n]);
    for (int i = n - 1; i > 0; --i) {
        mxl[i] = i;
        for (int j = 0; j < q[0][i].size(); ++j) {
            int v = q[0][i][j];
            if (i + 1 > v) {
                error();
            }
            mxl[i] = max(mxl[i], t.get_max(1, 1, n, i + 1, v));
        }
        mx[i] = mxl[i];
        for (int j = 0; j < q[1][i].size(); ++j) {
            int v = q[1][i][j];
            if (i + 1 > v) {
                error();
            }
            mx[i] = max(mx[i], t.get_max(1, 1, n, i + 1, v));
        }
        t.update(1, 1, n, i, mx[i]);
    }
    for (int i = 1; i <= n; ++i) {
        mn[i] = n + 9;
        for (int j = 0; j < q[1][i].size(); ++j) {
            mn[i] = min(mn[i], q[1][i][j]);
        }
    }
    get_ans(1, n);
    write(1);
    cout << endl;
    return 0;
}