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
int sz;
int t[1200005];
vector<int> v[300005];
int a[300005];


int get(int l, int r, int ll, int rr, int x) {
    if (l > r || ll > r || l > rr || ll > rr) return 0;
    if (l >= ll && r <= rr) return t[x];
    int mid = (l + r) >> 1;
    return max(get(l, mid, ll, rr, x + x), get(mid + 1, r, ll, rr, x + x + 1));
}

void update(int x) {
    x += sz - 1;
    t[x] = 0;
    x >>= 1;
    while (x) {
        t[x] = max(t[x + x], t[x + x + 1]);
        x >>= 1;
    }
    return;
}

void solve() {
    cin >> n;
    sz = 1;
    while (sz < n) sz += sz;
    for (int i = 1; i <= sz + sz; ++i)
        t[i] = 0;
    for (int i = 1; i <= n; ++i) {
        v[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        t[sz + i - 1] = x;
        v[x].push_back(i);
    }
    for (int i = sz - 1; i > 0; --i)
        t[i] = max(t[i + i], t[i + i + 1]);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = n; i > 0; --i) {
        int x = a[i];
        if (v[x].empty()) {
            cout << "NO\n";
            return;
        }
        int y = v[x].back();
        v[x].pop_back();
        int z = get(1, sz, y + 1, n, 1);
        if (z > x) {
            cout << "NO\n";
            return;
        }
        update(y);
    }
    cout << "YES\n";
    return;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}