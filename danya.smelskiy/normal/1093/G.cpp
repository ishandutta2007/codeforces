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


int n, m, sz, msk;
int t[32][1000005];
int b[100];
int ans[100];

void update(int l, int r, int ll, int x) {
    if (l == r) {
        for (int j = 0; j <= msk; ++j) {
            int cur = 0;
            for (int k = 0;k < m; ++k)
                if (j & (1<<k)) cur += b[k];
                else cur -= b[k];
            t[j][x] = cur;
        }
        return;
    }
    int mid = (l + r) >> 1;
    if (ll <= mid) update(l, mid, ll, x + x);
    else update(mid + 1, r, ll, x + x + 1);
    for (int j = 0;j <= msk; ++j) {
        t[j][x] = t[j][x + x];
        if (t[j][x + x + 1] > t[j][x]) t[j][x] = t[j][x + x + 1];
    }
    return;
}

void get(int l, int r, int ll, int rr, int x) {
    if (l > r || ll > r || l > rr || ll > rr) return;
    if (l >= ll && r <= rr) {
        for (int i = 0;i <= msk; ++i)
            if (t[i][x] > ans[i]) ans[i] = t[i][x];
        return;
    }
    int mid = (l + r) >> 1;
    get(l, mid, ll, rr, x + x);
    get(mid + 1, r, ll, rr, x + x + 1);
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    msk = (1 << m) - 1;
    sz = 1;
    while (sz < n) sz += sz;
    int cur, res;
    int x, y;
    for (int i = 1;i <= n; ++i) {
        for (int j = 0;j < m; ++j)
            cin >> b[j];
        for (int j = 0;j <= msk; ++j) {
            cur = 0;
            for (int k = 0;k < m; ++k) {
                if (j & (1<<k)) cur += b[k];
                else cur -= b[k];
            }
            t[j][sz + i - 1] = cur;
        }
    }
    for (int i = 0;i <= msk; ++i) {
        for (int j = sz - 1;j > 0; --j)
            t[i][j] = max(t[i][j + j], t[i][j + j + 1]);
    }
    int mm, tp;
    cin >> mm;
    while (mm--) {
        cin >> tp;
        if (tp == 1) {
            cin >> x;
            for (int j = 0;j < m; ++j)
                cin >> b[j];
            update(1, sz, x, 1);
            continue;
        }
        cin >> x >> y;
        for (int j = 0;j <= msk; ++j) {
            ans[j] = -1e9;
        }
        get(1, sz, x, y, 1);
        res = -1e9;
        for (int j = 0;j <= msk; ++j) {
            cur = ans[j] + ans[(j ^ msk)];
            if (cur > res) res = cur;
        }
        cout << res << '\n';
    }
}