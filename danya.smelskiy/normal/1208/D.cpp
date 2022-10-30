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
long long a[200005];
pair<long long, int> t[1000005];
int ans[200005];
long long q[1000005];

void push(int x) {
    q[x + x] += q[x];
    t[x + x].first += q[x];
    t[x + x + 1].first += q[x];
    q[x + x + 1] += q[x];
    q[x] = 0;
    return;
}

void update(int l, int r, int ll, int rr, int x, long long y) {
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
    t[x] = min(t[x + x], t[x + x + 1]);
    return;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    sz = 1;
    while (sz < n) sz += sz;
    for (int i = 1; i <= sz + sz; ++i)
        t[i] = {1e15, i};
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        t[sz + i - 1] = {a[i], -i};
    }
    for (int i = sz - 1; i > 0; --i)
        t[i] = min(t[i + i], t[i + i + 1]);
    for (int i = 1; i <= n; ++i) {
        int x = -t[1].second;
        ans[x] = i;
        update(1, sz, x + 1, n, 1, -i);
        update(1, sz, x, x, 1, 1e15);
    }
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << '\n';
    return 0;
}