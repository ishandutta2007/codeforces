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


int n, x, y;
int sz;
int t[1000005];
pair<int, int> a[200005];
vector<int> q;
long long ans;
map<int, int> mt;
int last;
long long all;

void update(int x) {
    x += sz - 1;
    t[x] = 1;
    x >>= 1;
    while (x) {
        t[x] = t[x + x] + t[x + x + 1];
        x >>= 1;
    }
    return;
}

int get(int l, int r, int ll, int rr, int x) {
    if (l > r || ll > r || l > rr || ll > rr) return 0;
    if (l >= ll && r <= rr) return t[x];
    int mid = (l + r) >> 1;
    return get(l, mid, ll, rr, x + x) + get(mid + 1, r, ll, rr, x + x + 1);
}

inline long long f(long long x) {
    return (x * (x + 1ll)) / 2ll;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y;
        q.push_back(x);
        a[i] = make_pair(y, x);
    }
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    sort(q.begin(), q.end());
    for (int i = 0; i < (int)q.size(); ++i)
        if (i == 0 || q[i] != q[i - 1]) mt[q[i]] = ++last;
    sz = 1;
    while (sz < last) sz += sz;
    int l = 1;
    while (l <= n) {
        int r = l;
        while (r <= n && a[r].first == a[l].first) ++r;
        q.clear();
        for (int i = l; i < r; ++i) {
            q.push_back(mt[a[i].second]);
        }
        sort(q.begin(), q.end());
        for (int i = 0; i < (int)q.size(); ++i) {
            update(q[i]);
        }
        ans += f(t[1]);
        x = q[0];
        y = get(1, sz, 1, x - 1, 1);
        ans -= f(y);
        for (int i = 1; i < (int)q.size(); ++i) {
            y = get(1, sz, q[i - 1] + 1, q[i] - 1, 1);
            ans -= f(y);
        }
        x = q.back();
        y = get(1, sz, x + 1, last, 1);
        ans -= f(y);
        l = r;
    }
    cout << ans << '\n';
    return 0;
}