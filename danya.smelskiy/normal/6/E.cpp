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
int t[5000005];
int lft[100005], rght[100005], a[100005];

int get(int l, int r, int ll, int rr, int x) {
    if (l > r || ll > r || l > rr || ll > r) return 0;
    if (l >= ll && r <= rr) return t[x];
    int mid = (l + r) >> 1;
    return max(get(l, mid, ll, rr, x + x), get(mid + 1, r, ll, rr, x + x + 1));
}

void update(int x, int y) {
    x += sz - 1;
    while (x) {
        t[x] = max(t[x], y);
        x >>= 1;
    }
    return;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sz = 1;
    while (sz < 2e6) sz += sz;
    for (int i = 1; i <= n; ++i) {
        lft[i] = max(get(1, sz, 1, a[i], 1), get(1, sz, a[i] + m + 1, sz, 1)) + 1;
        update(a[i], i);
    }
    for (int i = 1; i <= sz + sz; ++i)
        t[i] = 0;
    for (int i = n; i > 0; --i) {
        rght[i] = max(get(1, sz, 1, a[i] - 1, 1), get(1, sz, a[i] + m + 1, sz, 1)) + 1;
        rght[i] = n - rght[i] + 1;
        update(a[i], n - i + 1);
    }
    vector<pair<int, int> > q;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (rght[i] - lft[i] + 1 > ans) {
            ans = rght[i] - lft[i] + 1;
            q.clear();
            q.push_back({lft[i], rght[i]});
        } else if (rght[i] - lft[i] + 1 == ans) {
            q.push_back({lft[i], rght[i]});
        }
    }
    cout << ans << " " << (int)q.size() << '\n';
    for (int i = 0; i < q.size(); ++i)
        cout << q[i].first << " " << q[i].second << '\n';
}