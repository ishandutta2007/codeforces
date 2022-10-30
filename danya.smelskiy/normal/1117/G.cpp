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

int n, m, sz, sz2;
int a[1000005];
pair<int, int> b[1000005];
pair<int, int> q[1000005];
int lft[1000005];
int rght[1000005];
long long ans[1000005];
pair<long long, int> t[4000005];
vector<pair<int, int> > v[1000005];

void update(int x, int y) {
    x += sz - 1;
    t[x].first += y;
    t[x].second++;
    x >>= 1;
    while (x) {
        t[x].first = t[x + x].first + t[x + x + 1].first;
        t[x].second = t[x + x].second + t[x + x + 1].second;
        x >>= 1;
    }
    return;
}

pair<long long, int> get(int l, int r, int ll, int rr, int x) {
    if (l > r || ll > r || l > rr || ll > rr) return make_pair(0, 0);
    if (l >= ll && r <= rr) return t[x];
    int mid = (l + r) >> 1;
    pair<long long, int> res, res2;
    res = get(l, mid, ll, rr, x + x);
    res2 = get(mid + 1, r, ll, rr, x + x + 1);
    res.first += res2.first;
    res.second += res2.second;
    return res;
}

inline long long f(long long x) {
    return (x * (x + 1ll)) / 2ll;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        while (sz > 0 && q[sz].first < a[i]) --sz;
        lft[i] = q[sz].second + 1;
        q[++sz] = make_pair(a[i], i);
    }
    sz = 0;
    q[0] = make_pair(1e9, n + 1);
    for (int i = n; i > 0; --i) {
        while (sz > 0 && q[sz].first < a[i]) --sz;
        rght[i] = q[sz].second - 1;
        q[++sz] = make_pair(a[i], i);
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i].first;
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i].second;
        v[b[i].second].push_back(make_pair(b[i].first, i));
    }
    sz = 1;
    while (sz < n) sz += sz;
    long long x, ll;
    pair<long long, int> cur;
    for (int i = 1; i <= n; ++i) {
        x = lft[i] - 1;
        if (x) update(x, x);
        for (int j = 0; j < v[i].size(); ++j) {
            ll = v[i][j].first;
            cur = get(1, sz, ll, i, 1);
            x = v[i][j].second;
            ans[x] += f(i) - f(ll - 1);
            ans[x] -= cur.first;
            ans[x] -= (ll - 1) * 1ll * (i - ll + 1 - cur.second);
        }
        v[i].clear();
    }
    for (int i = 1; i <= sz + sz; ++i)
        t[i] = make_pair(0, 0);
    for (int i = 1; i <= m; ++i)
        v[b[i].first].push_back(make_pair(b[i].second, i));
    for (int i = n; i > 0; --i) {
        x = rght[i];
        if (x <= n) update(x, x);
        for (int j = 0; j < v[i].size(); ++j) {
            ll = v[i][j].first;
            cur = get(1, sz, i, ll, 1);
            x = v[i][j].second;
            ans[x] -= f(ll) - f(i - 1);
            ans[x] += cur.first;
            ans[x] += ll * 1ll * (ll - i + 1 - cur.second);
        }
    }
    for (int i = 1; i <= m; ++i)
        cout << ans[i] << " ";
    cout << '\n';
    
}