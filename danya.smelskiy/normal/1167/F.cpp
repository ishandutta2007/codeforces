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
const long long md = 1e9 + 7;


int n, sz;
int t[2][2000005];
int cnt[2][2000005];
pair<int, int> a[500005];
long long ans;


void update(int x, int y, int z) {
    y += sz - 1;
    ++cnt[x][y];
    t[x][y] += z;
    if (t[x][y] >= md) t[x][y] -= md;
    y >>= 1;
    while (y) {
        cnt[x][y] = cnt[x][y + y] + cnt[x][y + y + 1];
        t[x][y] = t[x][y + y] + t[x][y + y + 1];
        if (t[x][y] >= md) t[x][y] -= md;
        y >>= 1;
    }
    return;
}

pair<int, int> get(int l, int r, int ll, int rr, int x, int y) {
    if (l > r || ll > r || l > rr || ll > rr) return make_pair(0, 0);
    if (l >= ll && r <= rr) return make_pair(cnt[x][y], t[x][y]);
    int mid = (l + r) >> 1;
    pair<int, int> cur1, cur2;
    cur1 = get(l, mid, ll, rr, x, y + y);
    cur2 = get(mid + 1, r, ll, rr, x, y + y + 1);
    cur1.first += cur2.first;
    cur1.second += cur2.second;
    if (cur1.second >= md) cur1.second -= md;
    return cur1;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    sz = 1;
    while (sz < n) sz += sz;
    pair<long long, long long> cur1;
    long long cur, cur2;
    long long x;
    for (int i = 1; i <= n; ++i) {
        x = a[i].second;
        update(0, x, x);
        update(1, x, n - x + 1);
        cur1 = get(1, sz, 1, x, 0, 1);
        cur = cur1.second;
        cur *= n - x + 1;
        cur %= md;
        cur1 = get(1, sz, x + 1, n, 1, 1);
        cur2 = cur1.second;
        cur2 *= x;
        cur2 %= md;
        cur += cur2;
        if (cur >= md) cur -= md;
        cur *= a[i].first;
        cur %= md;
        ans += cur;
        if (ans >= md) ans -= md;
    }
    cout << ans << '\n';
    return 0;
}