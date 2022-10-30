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
long long t[400005];
long long a[100005], p[100005], pp[100005];
set<int> s;


void update(int x, long long y) {
    x += sz - 1;
    t[x] = y;
    x >>= 1;
    while (x) {
        t[x] = t[x + x] + t[x + x + 1];
        x >>= 1;
    }
    return;
}

long long get(int l, int r, int ll, int rr, int x) {
    if (l > r || ll > r || l > rr || ll > rr) return 0;
    if (l >= ll && r <= rr) return t[x];
    int mid = (l + r) >> 1;
    return get(l, mid, ll, rr, x + x) + get(mid + 1, r, ll, rr, x + x + 1);
}



long long get_ans(int r) {
    if (r == 0) return 0;
    long long res = get(1, sz, 1, r, 1);
    if (r == n || s.find(r + 1) != s.end()) return res;
    set<int> :: iterator q = s.upper_bound(r);
    --q;
    int ll = *q;
    long long len = r - ll + 1;
    res += a[ll] * len;
    res += p[r] - p[ll];
    res -= (len - 1ll) * pp[ll];
    return res;
}

long long get_sum(int l, int r) {
    return get_ans(r) - get_ans(l - 1);
}




int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s.insert(i);
    }
    for (int i = 2; i <= n; ++i) {
        cin >> p[i];
        p[i] += p[i - 1];
        pp[i] = p[i];
    }
    for (int i = 2; i <= n; ++i) {
        p[i] += p[i - 1];
    }
    sz = 1;
    while (sz < n) sz += sz;
    for (int i = 1; i <= n; ++i) {
        t[sz + i - 1] = a[i];
    }
    for (int i = sz - 1; i > 0; --i) {
        t[i] = t[i + i] + t[i + i + 1];
    }
    cin >> m;
    set<int> :: iterator q;
    int l, r;
    char tp;
    int ll, rr;
    long long cur, len;
    long long x, y;
    long long xx, yy;
    while (m--) {
        cin >> tp;
        if (tp == 's') {
            cin >> l >> r;
            cout << get_sum(l, r) << '\n';
            continue;
        }
        cin >> x >> y;
        q = s.upper_bound(x);
        if (q == s.end()) rr = n;
        else rr = *q - 1;
        --q;
        ll = *q;
        if (ll < x) {
            a[x] = a[ll] + pp[x] - pp[ll];
            xx = get_sum(ll, x - 1);
            yy = get_sum(x, rr);
            update(rr, yy);
            update(x - 1, xx);
            s.insert(x);
        }
        a[x] += y;
        len = rr - x + 1;
        cur = a[x] * len;
        cur += p[rr] - p[x];
        cur -= (len - 1ll) * 1ll * pp[x];
        update(rr, cur);
        while (true) {
            q = s.upper_bound(x);
            if (q == s.end()) break;
            ll = *q;
            if (a[ll] < a[x] + pp[ll] - pp[x]) {
                ++q;
                if (q == s.end()) rr = n;
                else rr = *q - 1;
                update(rr, 0);
                update(ll - 1, 0);
                s.erase(s.find(ll));
                len = rr - x + 1;
                cur = a[x] * len;
                cur += p[rr] - p[x];
                cur -= pp[x] * 1ll * (len - 1ll);
                update(rr, cur);
            } else break;
        }
    }
    
}