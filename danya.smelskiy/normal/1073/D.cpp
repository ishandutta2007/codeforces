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
long long m;
long long t[800005];
int cnt[800005];
int all, sz;
long long ans, s;
long long a[200005];

int get(int l, int r, int ll, int rr, int x) {
    if (l > r || ll > r || l > rr || ll > rr) return 0;
    if (l >= ll && r <= rr && t[x] <= m) {
        m -= t[x];
        ans += cnt[x];
        return 0;
    }
    if (l == r) return l;
    int mid = (l + r) >> 1;
    int res = get(l, mid, ll, rr, x + x);
    if (res) return res;
    return get(mid + 1, r, ll, rr, x + x + 1);
}

void update(int x) {
    x += sz - 1;
    t[x] = 0;
    cnt[x] = 0;
    x >>= 1;
    while (x) {
        t[x] = t[x + x] + t[x + x + 1];
        cnt[x] = cnt[x + x] + cnt[x + x + 1];
        x >>= 1;
    }
    return;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    sz = 1;
    while (sz < n) sz += sz;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s += a[i];
        ++all;
        t[sz + i - 1] = a[i];
        cnt[sz + i - 1] = 1;
    }
    for (int i = sz - 1; i > 0; --i) {
        t[i] = t[i + i] + t[i + i + 1];
        cnt[i] = cnt[i + i] + cnt[i + i + 1];
    }
    int last = 1;
    while (all > 0) {
        if (m >= s) {
            ans += all * (m / s);
            m %= s;
            continue;
        }
        last = get(1, sz, last, n, 1);
        if (!last) last = 1;
        else {
            s -= a[last];
            --all;
            update(last);
        }
    }
    cout << ans << '\n';
    
    
    
}