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


int n, m;
int sz;
int t[500005];
long long s[500005];


long long get(int l, int r, int ll, int rr, int x) {
    if (l > r || ll > r || l > rr || ll > rr) return 0;
    if (l >= ll && r <= rr) return s[x];
    int mid = (l + r) >> 1;
    return get(l, mid, ll, rr, x + x) + get(mid + 1, r, ll, rr, x + x + 1);
}

void update(int l, int r, int ll, int rr, int x, int y) {
    if (l > r || ll > r || l > rr || ll > rr || t[x] < y) return;
    if (l == r) {
        t[x] %= y;
        s[x] %= y;
        return;
    }
    int mid = (l + r) >> 1;
    update(l, mid, ll, rr, x + x, y);
    update(mid + 1, r, ll, rr, x + x + 1, y);
    t[x] = max(t[x + x], t[x + x + 1]);
    s[x] = s[x + x] + s[x + x + 1];
    return;
}

void update(int x, int y) {
    x += sz - 1;
    t[x] = s[x] = y;
    x >>= 1;
    while (x) {
        t[x] = max(t[x + x], t[x + x + 1]);
        s[x] = s[x + x] + s[x + x + 1];
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
        int x;
        cin >> x;
        t[sz + i - 1] = x;
        s[sz + i - 1] = x;
    }
    for (int i = sz - 1; i > 0; --i) {
        t[i] = max(t[i + i], t[i + i + 1]);
        s[i] = s[i + i] + s[i + i + 1];
    }
    for (int i = 1; i <= m; ++i) {
        int tp, l, r;
        cin >> tp >> l >> r;
        if (tp == 1) {
            cout << get(1, sz, l, r, 1) << '\n';
            continue;
        } else if (tp == 2) {
            int x;
            cin >> x;
            update(1, sz, l, r, 1, x);
        } else {
            update(l, r);
        }
    }
}