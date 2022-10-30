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



int n, m, sz, a[500005];
vector<int> lp;
bool pr[305];
long long t[5000005], tt[5000005];
long long q[5000005], qq[5000005];


void init() {
    for (int i = 2; i <= 300; ++i) if (!pr[i]) {
        lp.push_back(i);
        for (int j = i + i; j <= 300; j += i)
            pr[j] = true;
    }
    return;
}

long long pw(long long x, long long y) {
    long long res = 1;
    while (y) {
        if (y & 1ll) res = (res * x) % md;
        x = (x * x) % md;
        y >>= 1;
    }
    return res;
}

void push(int x, int l, int r) {
    t[x + x] |= q[x];
    t[x + x + 1] |= q[x];
    q[x + x] |= q[x];
    q[x + x + 1] |= q[x];
    q[x] = 0;
    int mid = (l + r) >> 1;
    qq[x + x] = (qq[x + x] * qq[x]) % md;
    qq[x + x + 1] = (qq[x + x + 1] * qq[x]) % md;
    tt[x + x] *= pw(qq[x], mid - l + 1);
    tt[x + x] %= md;
    tt[x + x + 1] *= pw(qq[x], r - mid);
    tt[x + x + 1] %= md;
    qq[x] = 1;
    return;
}

void update(int l, int r, int ll, int rr, int x, long long y, long long z) {
    if (l > r || ll > r || l > rr || ll > rr) return;
    if (l >= ll && r <= rr) {
        q[x] |= y;
        qq[x] = (qq[x] * z) % md;
        t[x] |= y;
        tt[x] = (tt[x] * pw(z, r - l + 1)) % md;
        return;
    }
    int mid = (l + r) >> 1;
    if (q[x] || qq[x] != 1ll) push(x, l, r);
    update(l, mid, ll, rr, x + x, y, z);
    update(mid + 1, r, ll, rr, x + x + 1, y, z);
    t[x] = (t[x + x] | t[x + x + 1]);
    tt[x] = (tt[x + x] * tt[x + x + 1]) % md;
    return;
}

pair<long long, long long> get(int l, int r, int ll, int rr, int x) {
    if (l > r || ll > r || l > rr || ll > rr) return {0, 1};
    if (l >= ll && r <= rr) return {t[x], tt[x]};
    int mid = (l + r) >> 1;
    if (q[x] || qq[x] != 1) push(x, l, r);
    pair<long long, long long> xx = get(l, mid, ll, rr, x + x), yy = get(mid + 1, r, ll, rr, x + x + 1);
    xx.first |= yy.first;
    xx.second *= yy.second;
    xx.second %= md;
    return xx;
}

long long solve(int l, int r) {
    pair<long long, long long> xx = get(1, sz, l, r, 1);
    long long res = xx.second;
    for (long long i = 0; i < lp.size(); ++i) if ((xx.first & (1ll << i))) {
        res *= lp[i] - 1;
        res %= md;
        res *= pw(lp[i], md - 2);
        res %= md;
    }
    return res;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    init();
    cin >> n >> m;
    sz = 1;
    while (sz < n) sz += sz;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        long long cur = 0;
        for (long long j = 0; j < lp.size(); ++j) if (a[i] % lp[j] == 0) {
            cur |= (1ll << j);
        }
        t[sz + i - 1] = cur;
        tt[sz + i - 1] = a[i];
    }
    for (int i = sz - 1; i > 0; --i) {
        t[i] = (t[i + i] | t[i + i + 1]);
        tt[i] = (tt[i + i] * tt[i + i + 1]) % md;
    }
    for (int i = 1; i <= sz + sz; ++i) {
        qq[i] = 1;
    }
    string s;
    for (int i = 1; i <= m; ++i) {
        cin >> s;
        if (s[0] == 'T') {
            int l, r;
            cin >> l >> r;
            cout << solve(l, r) << '\n';
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            long long cur = 0;
            for (long long j = 0; j < lp.size(); ++j)
                if (x % lp[j] == 0) cur |= (1ll << j);
            update(1, sz, l, r, 1, cur, x);
        }
    }
    return 0;
}