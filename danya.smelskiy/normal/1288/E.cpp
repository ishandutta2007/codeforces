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


int n, m;
int ans1[300005];
int ans2[300005];
int sz;
int a[300005];
vector<int> q[300005];
vector<pair<int, int> > v1[300005];
vector<int> v2[300005];
int last[300005];
int t[1500005];
int f[300005];

void add1(int l, int r, int x) {
    if (l > r) return;
    v1[r].push_back({l, x});
}

void add2(int l, int x) {
    v2[l].push_back(x);
}



void update(int l, int r, int ll, int x, int y) {
    if (l == r) {
        t[x] = y;
        return;
    }
    int mid = (l + r) >> 1;
    if (ll <= mid) {
        update(l, mid, ll, x + x, y);
    } else {
        update(mid + 1, r, ll, x + x + 1, y);
    }
    t[x] = t[x + x] + t[x + x + 1];
    return;
}

int get(int l, int r, int ll, int rr, int x) {
    if (l > r || ll > r || l > rr || ll > rr) return 0;
    if (l >= ll && r <= rr) return t[x];
    int mid = (l + r) >> 1;
    return get(l, mid, ll, rr, x + x) + get(mid + 1, r, ll, rr, x + x + 1);
}

void add_point(int x) {
    while (x <= n) {
        f[x] += 1;
        x = (x | (x + 1));
    }
}

int get_point(int x) {
    int res = 0;
    while (x >= 0) {
        res += f[x];
        x = ((x & (x + 1)) - 1);
    }
    return res;
}

int get_sum(int l, int r) {
    return get_point(r) - get_point(l - 1);
}

void solve() {
    for (int i = 1; i <= n; ++i) {
        if (q[i].empty()) {
            add2(m, i);
        } else {
            add2(q[i][0] - 1, i);
            for (int j = 1; j < q[i].size(); ++j) {
                add1(q[i][j - 1] + 1, q[i][j] - 1, i);
            }
            add1(q[i].back() + 1, m, i);
        }
    }
    int x;
    for (int i = 1; i <= m; ++i) {
        x = a[i];
        if (last[x]) update(1, sz, last[x], 1, 0);
        else add_point(x);
        last[x] = i;
        update(1, sz, last[x], 1, 1);
        for (int j = 0; j < v1[i].size(); ++j) {
            int cur = get(1, sz, v1[i][j].first, i, 1);
            ans2[v1[i][j].second] = max(ans2[v1[i][j].second], cur + 1);
        }
        for (int j = 0; j < v2[i].size(); ++j) {
            int cur = get_sum(v2[i][j] + 1, n);
            ans2[v2[i][j]] = max(ans2[v2[i][j]], v2[i][j] + cur);
        }
    }
}

int main(int argc, const char * argv[]) {
    #ifdef __APPLE__
        freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
        //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        ans1[i] = ans2[i] = i;
    }
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
        q[a[i]].push_back(i);
        ans1[a[i]] = 1;
    }
    sz = 1;
    while (sz < m) sz += sz;
    solve();
    for (int i = 1; i <= n; ++i) {
        cout << ans1[i] << " " << ans2[i] << '\n';
    }
    return 0;
}