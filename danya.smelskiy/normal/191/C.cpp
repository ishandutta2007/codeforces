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


int n, m, timer;
int tin[100005];
int tout[100005];
int dp[100005][19];
int q[100005];
vector<pair<int, int> > v[100005];
int ans[100005];
int pred_edge[100005];
int mx[100005], cnt[100005], nxt[100005];
int clr[100005];
int all;
int fir[100005];
int t[500005];
int sz;

void dfs(int x, int y) {
    dp[x][0] = y;
    for (int i = 1; i <= 18; ++i)
        dp[x][i] = dp[dp[x][i - 1]][i - 1];
    cnt[x] = 1;
    mx[x] = nxt[x] = 0;
    for (int i = 0; i < (int)v[x].size(); ++i) {
        int to = v[x][i].first;
        if (to == y) continue;
        pred_edge[to] = v[x][i].second;
        dfs(to, x);
        cnt[x] += cnt[to];
        if (cnt[to] > mx[x]) {
            mx[x] = cnt[to];
            nxt[x] = to;
        }
    }
    return;
}

inline bool f_pred(int x, int y) {
    return (tin[x] <= tin[y] && tout[x] >= tout[y]);
}

inline int get_lca(int x, int y) {
    if (tin[x] > tin[y]) swap(x, y);
    if (f_pred(x, y)) return x;
    for (int i = 18; i >= 0; --i)
        if (dp[x][i] && !f_pred(dp[x][i], y)) x = dp[x][i];
    return dp[x][0];
}

void build_hld(int x, int y, int z) {
    clr[x] = z;
    if (clr[x] != clr[y]) fir[z] = x;
    tin[x] = ++timer;
    if (nxt[x]) build_hld(nxt[x], x, z);
    for (int i = 0; i < (int)v[x].size(); ++i) {
        int to = v[x][i].first;
        if (to == y || to == nxt[x]) continue;
        build_hld(to, x, ++all);
    }
    tout[x] = timer;
    return;
}

void update(int l, int r, int ll, int rr, int x) {
    if (l > r || ll > r || l > rr || ll > rr) return;
    if (l >= ll && r <= rr) {
        t[x]++;
        return;
    }
    int mid = (l + r) >> 1;
    update(l, mid, ll, rr, x + x);
    update(mid + 1, r, ll, rr, x + x + 1);
    return;
}

int get(int x) {
    int res = 0;
    x += sz - 1;
    while (x) {
        res += t[x];
        x >>= 1;
    }
    return res;
}

void update(int x, int y) {
    while (y) {
        if (clr[x] == clr[y]) {
            update(1, sz, tin[x] + 1, tin[y], 1);
            break;
        }
        int z = fir[clr[y]];
        update(1, sz, tin[z], tin[y], 1);
        y = dp[z][0];
    }
    return;
}

void dfs2(int x, int y) {
    for (int i = 0; i < (int)v[x].size(); ++i) {
        int to = v[x][i].first;
        if (to == y) continue;
        dfs2(to, x);
    }
    ans[pred_edge[x]] = get(tin[x]);
    return;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        v[x].push_back({y, i});
        v[y].push_back({x, i});
    }
    dfs(1, 0);
    all = 1;
    build_hld(1, 0, 1);
    sz = 1;
    while (sz < n) sz += sz;
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        if (tin[x] > tin[y]) swap(x, y);
        if (f_pred(x, y)) update(x, y);
        else {
            int z = get_lca(x, y);
            update(z, x);
            update(z, y);
        }
    }
    dfs2(1, 0);
    for (int i = 1; i < n; ++i)
        cout << ans[i] << " ";
    cout << '\n';
    return 0;
}