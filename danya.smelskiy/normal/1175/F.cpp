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


int n;
int a[300005];
int q[1500005];
pair<int, int> t[1500005];
long long ans;
int sz;
pair<int, int> qq[300005];
int used[300005];

void push(int x) {
    q[x + x] += q[x];
    t[x + x].first += q[x];
    q[x + x + 1] += q[x];
    t[x + x + 1].first += q[x];
    q[x] = 0;
    return;
}

void update(int l, int r, int ll, int rr, int x, int y) {
    if (l > r || ll > r || l > rr || ll > rr) return;
    if (l >= ll && r <= rr) {
        t[x].first += y;
        q[x] += y;
        return;
    }
    int mid = (l + r) >> 1;
    if (q[x]) push(x);
    update(l, mid, ll, rr, x + x, y);
    update(mid + 1, r, ll, rr, x + x + 1, y);
    t[x].first = min(t[x + x].first, t[x + x + 1].first);
    t[x].second = 0;
    if (t[x + x].first == t[x].first) t[x].second += t[x + x].second;
    if (t[x + x + 1].first == t[x].first) t[x].second += t[x + x + 1].second;
    return;
}

pair<int, int> get(int l, int r, int ll, int rr, int x) {
    if (l > r || ll > r || l > rr || ll > rr) return make_pair(1e9, 0);
    if (l >= ll && r <= rr) return t[x];
    if (q[x]) push(x);
    int mid = (l + r) >> 1;
    pair<int, int> y = get(l, mid, ll, rr, x + x), z = get(mid + 1, r, ll, rr, x + x + 1);
    if (z.first < y.first) swap(y, z);
    if (z.first == y.first) y.second += z.second;
    return y;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sz = 1;
    while (sz < n) sz += sz;
    for (int i = 1; i <= n; ++i)
        t[sz + i - 1].second = 1;
    for (int i = sz - 1; i > 0; --i) {
        t[i] = t[i + i];
        t[i].second += t[i + i + 1].second;
    }
    int sz2 = 1;
    qq[sz2] = make_pair(1e9, 0);
    int last = 1;
    int l, r;
    for (int i = 1; i <= n; ++i) {
        last = max(last, used[a[i]] + 1);
        used[a[i]] = i;
        update(1, sz, 1, i, 1, -1);
        update(1, sz, i, i, 1, a[i]);
        qq[++sz2] = make_pair(a[i], i);
        while (sz2 >= 0 && qq[sz2 - 1].first < qq[sz2].first) {
            l = qq[sz2 - 2].second + 1;
            r = qq[sz2 - 1].second;
            update(1, sz, l, r, 1, qq[sz2].first - qq[sz2 - 1].first);
            qq[sz2 - 1] = qq[sz2];
            --sz2;
        }
        pair<int, int> cur = get(1, sz, last, i, 1);
        if (cur.first == 0) ans += cur.second;
    }
    cout << ans << '\n';
    return 0;
}