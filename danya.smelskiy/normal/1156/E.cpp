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
int ans;
int sz;
int a[200005];
pair<int, int> t[2000005];
int pos[200005];

pair<int, int> get(int l, int r, int ll, int rr, int x) {
    if (l > r || ll > r || l > rr || ll > rr) return make_pair(0, 0);
    if (l >= ll && r <= rr) return t[x];
    int mid = (l + r) >> 1;
    return max(get(l, mid, ll, rr, x + x), get(mid + 1, r, ll, rr, x + x + 1));
}

void solve(int l, int r) {
    if (l >= r) return;
    pair<int, int> c = get(1, sz, l, r, 1);
    int cc = c.first;
    int mid = c.second;
    if (mid - l + 1 <= r - mid + 1) {
        for (int i = l; i <= mid; ++i) if (pos[cc - a[i]] >= mid && pos[cc - a[i]] <= r) ++ans;
        solve(l, mid - 1);
        solve(mid + 1, r);
    } else {
        for (int i = mid; i <= r; ++i) if (pos[cc - a[i]] >= l && pos[cc - a[i]] <= mid) ++ans;
        solve(l, mid - 1);
        solve(mid + 1, r);
    }
    return;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    sz = 1;
    while (sz < n) sz += sz;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
        t[sz + i - 1] = make_pair(a[i], i);
    }
    for (int i = sz - 1; i > 0; --i)
        t[i] = max(t[i + i], t[i + i + 1]);
    solve(1, n);
    cout << ans << '\n';
}