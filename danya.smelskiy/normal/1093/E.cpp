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

int n, m, sz;
vector<int> v[2000001];
vector<int> f[2000001];
int a[200005];
int tp[200005];
int b[200005];
int c[200005];
int pos[200005];
pair<int, int> zp[200005][2];
int x, y, xx, yy, z;

vector<int> mrg(vector<int> x, vector<int> y) {
    vector<int> res;
    int l = 0;
    int r = 0;
    while (l < x.size() || r < y.size()) {
        if (r == y.size() || (l < x.size() && x[l] <= y[r])) res.push_back(x[l++]);
        else res.push_back(y[r++]);
    }
    return res;
}

int get_pos(int x, int y) {
    int l = 0;
    int r = (int)v[x].size() - 1;
    while (l < r - 1) {
        int mid = (l + r) >> 1;
        if (v[x][mid] <= y) l = mid;
        else r = mid;
    }
    if (v[x][r] <= y) l = r;
    return l;
}

void update_f(int x, int y, int z) {
    int xx = (int) f[x].size();
    while (y < xx) {
        f[x][y] += z;
        y = (y | (y + 1));
    }
    return;
}

int get_f(int x, int y) {
    int res = 0;
    while (y >= 0) {
        res += f[x][y];
        y = (y & (y + 1)) - 1;
    }
    return res;
}

void update(int x, int y, int z) {
    int xx;
    while (x) {
        xx = get_pos(x, y);
        update_f(x, xx, z);
        x >>= 1;
    }
    return;
}

int solve(int x, int y, int z) {
    int xx = get_pos(x, z);
    if (v[x][xx] > z || v[x][xx] < y) return 0;
    int yy = get_pos(x, y - 1);
    if (v[x][yy] >= y) return get_f(x, xx);
    return get_f(x, xx) - get_f(x, yy);
}

int get(int l, int r, int ll, int rr, int x, int y, int z) {
    if (l > r || ll > r || l > rr || ll > rr) return 0;
    if (l >= ll && r <= rr) return solve(x, y, z);
    int mid = (l + r) >> 1;
    return get(l, mid, ll, rr, x + x, y, z) + get(mid + 1, r, ll, rr, x + x + 1, y, z);
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    sz = 1;
    while (sz < n) sz += sz;
    for (int i = 1;i <= n; ++i) {
        cin >> b[i];
        c[i] = b[i];
        x = pos[b[i]];
        v[sz + x - 1].push_back(i);
    }
    for (int i = 1;i <= m; ++i) {
        cin >> tp[i];
        if (tp[i] == 1) {
            cin >> zp[i][0].first >> zp[i][0].second >> zp[i][1].first >> zp[i][1].second;
            continue;
        } else {
            cin >> x >> y;
            zp[i][0] = make_pair(x, y);
            swap(c[x], c[y]);
            z = pos[c[x]];
            v[sz + z - 1].push_back(x);
            z = pos[c[y]];
            v[sz + z - 1].push_back(y);
        }
    }
    vector<int> vv;
    for (int i = 1;i <= n; ++i) {
        sort(v[sz + i - 1].begin(), v[sz + i - 1].end());
        vv.clear();
        for (int j = 0;j < v[sz + i - 1].size(); ++j)
            if ((int)vv.size() == 0 || v[sz + i - 1][j] != vv.back()) vv.push_back(v[sz + i - 1][j]);
        v[sz + i - 1] = vv;
    }
    for (int i = sz - 1;i > 0; --i)
        v[i] = mrg(v[i + i], v[i + i + 1]);
    for (int i = 1;i <= sz + sz; ++i) {
        f[i].resize((int)v[i].size() + 2);
        for (int j = 0;j < f[i].size(); ++j)
            f[i][j] = 0;
    }
    for (int i = 1;i <= n; ++i) {
        x = pos[b[i]];
        c[x] = i;
        update(sz + x - 1, i, 1);
    }
    for (int i = 1;i <= m; ++i) {
        if (tp[i] == 1) {
            x = zp[i][0].first;
            y = zp[i][0].second;
            cout << get(1, sz, x, y, 1, zp[i][1].first, zp[i][1].second) << '\n';
            continue;
        }
        x = zp[i][0].first;
        y = zp[i][0].second;
        xx = pos[b[x]];
        update(sz + xx - 1, c[xx], -1);
        xx = pos[b[y]];
        update(sz + xx - 1, c[xx], -1);
        swap(b[x], b[y]);
        xx = pos[b[x]];
        c[xx] = x;
        update(sz + xx - 1, c[xx], 1);
        xx = pos[b[y]];
        c[xx] = y;
        update(sz + xx - 1, c[xx], 1);
    }
}