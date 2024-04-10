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

int n, m, sz, timer;
int p[1000005];
vector<int> v[1000005];
int tin[1000005], tout[1000005];
int t[4000005], tt[4000005];
int depth[1000005];
int a[1000005];
pair<int, int> q[1000005];
bool used[1000005];

void dfs(int x, int y = 0) {
    used[x] = true;
    tin[x] = ++timer;
    depth[x] = depth[y] + 1;
    for (int i = 0; i < v[x].size(); ++i) {
        int to = v[x][i];
        dfs(to, x);
    }
    tout[x] = timer;
    return;
}

void update(int x, int y) {
    x += sz - 1;
    t[x] = y;
    x >>= 1;
    while (x) {
        t[x] = max(t[x + x], t[x + x + 1]);
        x >>= 1;
    }
    return;
}

int get(int l, int r, int ll, int rr, int x) {
    if (l > r || ll > r || l > rr || ll > rr) return 0;
    if (l >= ll && r <= rr) return t[x];
    int mid = (l + r) >> 1;
    return max(get(l, mid, ll, rr, x + x), get(mid + 1, r, ll, rr, x + x + 1));
}

void update2(int x, int y) {
    x += sz - 1;
    tt[x] = y;
    x >>= 1;
    while (x) {
        tt[x] = max(tt[x + x], tt[x + x + 1]);
        x >>= 1;
    }
    return;
}

int get_pred(int x) {
    if (x == p[x]) return x;
    return p[x] = get_pred(p[x]);
}

void update_val(int x) {
    int val = get(1, sz, tin[x], tout[x], 1) - depth[x] + 1;
    update2(x, val);
    return;
}

void add_vertex(int x) {
    for (int i = 0; i < v[x].size(); ++i) {
        int to = v[x][i];
        update2(to, 0);
        to = get_pred(to);
        p[to] = x;
    }
    update(tin[x], depth[x]);
    update_val(x);
    return;
}

void del_vertex(int x) {
    update(tin[x], 0);
    x = get_pred(x);
    update_val(x);
    return;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    q[0] = {1e9, n + 1};
    for (int i = n; i > 0; --i) {
        while (sz > 0 && q[sz].first <= a[i]) --sz;
        v[q[sz].second].push_back(i);
        q[++sz] = {a[i], i};
    }
    for (int i = n + 1; i > 0; --i)
        if (!used[i]) dfs(i);
    for (int i = 1; i <= n + 1; ++i)
        p[i] = i;
    sz = 1;
    while (sz < n + 1) sz += sz;
    for (int i = 1; i <= m; ++i) {
        add_vertex(i);
    }
    cout << tt[1] << " ";
    for (int i = m + 1; i <= n; ++i) {
        add_vertex(i);
        del_vertex(i - m);
        cout << tt[1] << " ";
    }
    cout << '\n';
}