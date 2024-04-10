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

int sz;
int n, m, timer;
long long t[2000005], q[2000005];
vector<pair<int, int> > v[500005];
int tin[500005], tout[500005];
long long depth[500005];
long long ans[500005];
vector<pair<pair<int, int>, int> > iv[500005];



void push(int x) {
    t[x + x] += q[x];
    t[x + x + 1] += q[x];
    q[x + x] += q[x];
    q[x + x + 1] += q[x];
    q[x] = 0;
    return;
}

void update_pos(int l, int r, int ll, int x, long long y) {
    if (l == r) {
        t[x] = y;
        return;
    }
    int mid = (l + r) >> 1;
    if (q[x]) push(x);
    if (ll <= mid) update_pos(l, mid, ll, x + x, y);
    else update_pos(mid + 1, r, ll, x + x + 1, y);
    t[x] = min(t[x + x], t[x + x + 1]);
    return;
}

void update(int l, int r, int ll, int rr, int x, int y) {
    if (l > r || ll > r || l > rr || ll > rr) return;
    if (l >= ll && r <= rr) {
        t[x] += y;
        q[x] += y;
        return;
    }
    int mid = (l + r) >> 1;
    if (q[x]) push(x);
    update(l, mid, ll, rr, x + x, y);
    update(mid + 1, r, ll, rr, x + x + 1, y);
    t[x] = min(t[x + x], t[x + x + 1]);
    return;
}

long long get(int l, int r, int ll, int rr, int x) {
    if (l > r || ll > r || l > rr || ll > rr) return 1e18;
    if (l >= ll && r <= rr) return t[x];
    int mid = (l + r) >> 1;
    if (q[x]) push(x);
    return min(get(l, mid, ll, rr, x + x), get(mid + 1, r, ll, rr, x + x + 1));
}

void dfs1(int x, long long xx) {
    tin[x] = ++timer;
    if ((int)v[x].size() == 0) {
        update_pos(1, sz, tin[x], 1, -depth[x]);
    } else {
        update_pos(1, sz, tin[x], 1, 1e18);
    }
    for (int i = 0; i < v[x].size(); ++i) {
        int to = v[x][i].first;
        depth[to] = depth[x];
        depth[to] += v[x][i].second;
        dfs1(to, v[x][i].second);
    }
    for (int i = 0; i < iv[x].size(); ++i) {
        int l = iv[x][i].first.first;
        int r = iv[x][i].first.second;
        long long cur = get(1, sz, l, min(tin[x], r), 1) + depth[x];
        ans[iv[x][i].second] = min(ans[iv[x][i].second], cur);
    }
    tout[x] = timer;
    update(1, sz, tin[x], tout[x], 1, 2ll * xx);
    return;
}

void dfs2(int x, long long y) {
    if ((int)v[x].size() == 0) {
        update_pos(1, sz, tin[x], 1, -depth[x]);
    } else {
        update_pos(1, sz, tin[x], 1, 1e18);
    }
    reverse(v[x].begin(), v[x].end());
    for (int i = 0; i < v[x].size(); ++i) {
        int to = v[x][i].first;
        dfs2(to, v[x][i].second);
    }
    for (int i = 0; i < iv[x].size(); ++i) {
        int l = iv[x][i].first.first;
        int r = iv[x][i].first.second;
        long long cur = get(1, sz, max(l, tin[x]), r, 1) + depth[x];
        ans[iv[x][i].second] = min(ans[iv[x][i].second], cur);
    }
    update(1, sz, tin[x], tout[x], 1, 2ll * y);
    return;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int x, y, z;
    for (int i = 2; i <= n; ++i) {
        cin >> x >> y;
        v[x].push_back({i, y});
    }
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y >> z;
        iv[x].push_back({{y, z}, i});
        ans[i] = 1e18;
    }
    sz = 1;
    while (sz < n) sz += sz;
    dfs1(1, 0);
    for (int i = 1; i <= sz + sz; ++i)
        t[i] = q[i] = 0;
    dfs2(1, 0);
    for (int i = 1; i <= m; ++i)
        cout << ans[i] << '\n';
}