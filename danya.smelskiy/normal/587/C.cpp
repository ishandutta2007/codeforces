# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <unordered_set>
# include <unordered_map>
using namespace std;


int n, m, k, sz;
int all;
int lft[6000005], rght[6000005], t[6000005];
vector<int> v[100005], q[100005];
int c[100005];
int timer, tin[100005], tout[100005];
int dp[100005][19];
int root[100005];

inline int vcopy(int x) {
    ++all;
    lft[all] = lft[x];
    rght[all] = rght[x];
    t[all] = t[x];
    return all;
}

void update(int l, int r, int ll, int x) {
    if (l == r) {
        t[x]++;
        return;
    }
    int mid = (l + r) >> 1;
    if (ll <= mid) {
        lft[x] = vcopy(lft[x]);
        update(l, mid, ll, lft[x]);
    } else {
        rght[x] = vcopy(rght[x]);
        update(mid + 1, r, ll, rght[x]);
    }
    t[x] = t[lft[x]] + t[rght[x]];
    return;
}

void dfs(int x, int y) {
    tin[x] = ++timer;
    root[x] = vcopy(root[y]);
    dp[x][0] = y;
    for (int i = 1; i <= 18; ++i)
        dp[x][i] = dp[dp[x][i - 1]][i - 1];
    c[x] = c[y] + (int)q[x].size();
    for (int i = 0; i < q[x].size(); ++i) {
        int to = q[x][i];
        update(1, sz, to, root[x]);
    }
    for (int i = 0; i < v[x].size(); ++i) {
        int to = v[x][i];
        if (to != y) dfs(to, x);
    }
    tout[x] = timer;
    return;
}

inline bool f_pred(int x, int y) {
    return (tin[x] <= tin[y] && tout[x] >= tout[y]);
}

inline int get_lca(int x, int y) {
    if (f_pred(x, y)) return x;
    if (f_pred(y, x)) return y;
    for (int i = 18; i >= 0; --i)
        if (dp[x][i] && !f_pred(dp[x][i], y)) x = dp[x][i];
    return dp[x][0];
}

void get(int l, int r, int x, int y, int xx, int yy, int z) {
    if (l > r || z < 1) return;
    if (l == r) {
        cout << l << " ";
        return;
    }
    int mid = (l + r) >> 1;
    int c = t[lft[x]] + t[lft[y]] - t[lft[xx]] - t[lft[yy]];
    if (c >= z) get(l, mid, lft[x], lft[y], lft[xx], lft[yy], z);
    else {
        get(l, mid, lft[x], lft[y], lft[xx], lft[yy], c);
        get(mid + 1, r, rght[x], rght[y], rght[xx], rght[yy], z - c);
    }
    return;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 1; i <= m; ++i) {
        int x;
        cin >> x;
        q[x].push_back(i);
    }
    sz = 1;
    while (sz < m) sz += sz;
    root[0] = 1;
    all = sz + sz;
    for (int i = 1; i < sz; ++i) {
        lft[i] = i + i;
        rght[i] = i + i + 1;
    }
    dfs(1, 0);
    while (k--) {
        int x, y, z;
        cin >> x >> y >> z;
        int xx = get_lca(x, y);
        z = min(z, c[x] + c[y] - c[xx] - c[dp[xx][0]]);
        cout << z << " ";
        get(1, sz, root[x], root[y], root[xx], root[dp[xx][0]], z);
        cout << '\n';
    }
}