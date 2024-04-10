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


int n, all, sz;
long long md;
long long ob1[400005];
long long ob2[400005];
long long s[400005];
int ob3[400005][10];
int cnt2[10];
int poc[10];
int C;

void push(int x) {
    if (ob1[x] != 1) {
        ob1[x + x] *= ob1[x];
        ob1[x + x + 1] *= ob1[x];
        s[x + x] *= ob1[x];
        s[x + x + 1] *= ob1[x];
        ob1[x] = 1;
        ob1[x + x] %= md;
        ob1[x + x + 1] %= md;
        s[x + x] %= md;
        s[x + x + 1] %= md;
    }
    if (ob2[x] != 1) {
        ob2[x + x] *= ob2[x];
        ob2[x + x + 1] *= ob2[x];
        s[x + x] *= ob2[x];
        s[x + x + 1] *= ob2[x];
        ob2[x] = 1;
        ob2[x + x] %= md;
        ob2[x + x + 1] %= md;
        s[x + x] %= md;
        s[x + x + 1] %= md;
    }
    for (int i = 0; i < all; ++i) {
        ob3[x + x][i] += ob3[x][i];
        ob3[x + x + 1][i] += ob3[x][i];
        ob3[x][i] = 0;
    }
    return;
}

void update(int l, int r, int ll, int rr, int x, int y, int z, bool c) {
    if (l > r || ll > r || l > rr || ll > rr) return;
    if (l >= ll && r <= rr) {
        ob1[x] *= y;
        ob1[x] %= md;
        ob2[x] *= z;
        ob2[x] %= md;
        s[x] *= y * 1ll * z;
        s[x] %= md;
        if (c) {
            for (int j = 0; j < all; ++j)
                ob3[x][j] += cnt2[j];
        }
        return;
    }
    int mid = (l + r) >> 1;
    push(x);
    update(l, mid, ll, rr, x + x, y, z, c);
    update(mid + 1, r, ll, rr, x + x + 1, y, z, c);
    s[x] = s[x + x] + s[x + x + 1];
    if (s[x] >= md) s[x] -= md;
    return;
}

void mult_query(int l, int r, int x) {
    int y = 1;
    bool c = false;
    for (int i = 1; i <= all; ++i) {
        cnt2[i - 1] = 0;
        while (x % poc[i] == 0) {
            ++cnt2[i - 1];
            c = true;
            x /= poc[i];
            y *= poc[i];
        }
    }
    x %= md;
    y %= md;
    update(1, sz, l, r, 1, x, y, c);
    return;
}

long long get(int l, int r, int ll, int rr, int x) {
    if (l > r || ll > r || l > rr || ll > rr) return 0;
    if (l >= ll && r <= rr) return s[x];
    int mid = (l + r) >> 1;
    push(x);
    return get(l, mid, ll, rr, x + x) + get(mid + 1, r, ll, rr, x + x + 1);
}

long long pw(long long x, long long y) {
    long long res = 1;
    while (y) {
        if (y & 1) res = (res * x) % md;
        x = (x * x) % md;
        y >>= 1;
    }
    return res;
}

void delt(int l, int r, int ll, int x, int y) {
    if (l == r) {
        for (int i = 0; i < all; ++i)
            while (y % poc[i + 1] == 0) {
                --ob3[x][i];
                y /= poc[i + 1];
            }
        ob1[x] *= pw(y, C);
        ob1[x] %= md;
        s[x] = ob1[x];
        for (int i = 0; i < all; ++i)
            if (ob3[x][i]) {
                s[x] *= pw(poc[i + 1], ob3[x][i]);
                s[x] %= md;
            }
        return;
    }
    int mid = (l + r) >> 1;
    push(x);
    if (ll <= mid) delt(l, mid, ll, x + x, y);
    else delt(mid + 1, r, ll, x + x + 1, y);
    s[x] = s[x + x] + s[x + x + 1];
    if (s[x] >= md) s[x] -= md;
    return;
}

inline int get_phi(int x) {
    int res = x;
    for (int i = 2; i * i <= x; ++i) if (x % i == 0) {
        res -= res / i;
        while (x % i == 0) {
            x /= i;
        }
    }
    if (x > 1) res -= res / x;
    return res - 1;
}

int main(int argc, const char * argv[]) {
 //   freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> md;
    C = get_phi(md);
    int md2 = md;
    for (int i = 2; i * i <= md2; ++i) if (md2 % i == 0) {
        while (md2 % i == 0) md2 /= i;
        ++all;
        poc[all] = i;
    }
    if (md2 > 1) {
        ++all;
        poc[all] = md2;
    }
    sz = 1;
    while (sz < n) sz += sz;
    for (int i = 1; i <= sz + sz; ++i) {
        ob1[i] = ob2[i] = 1;
    }
    for (int i = 1; i <= n; ++i)
        s[sz + i - 1] = 1;
    for (int i = sz - 1; i > 0; --i) {
        s[i] = s[i + i] + s[i + i + 1];
        if (s[i] >= md) s[i] -= md;
    }
    int x;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        mult_query(i, i, x);
    }
    int m, tp, l, r;
    cin >> m;
    long long res;
    while (m--) {
        cin >> tp;
        if (tp == 3) {
            cin >> l >> r;
            res = get(1, sz, l, r, 1);
            res %= md;
            cout << res << '\n';
        } else if (tp == 1) {
            cin >> l >> r >> x;
            mult_query(l, r, x);
        } else {
            cin >> l >> x;
            delt(1, sz, l, 1, x);
        }
    }
    
}