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
pair<int, int> t[10][800005];
int sz;


void update(int x, int y, int z) {
    y += sz - 1;
    t[x][y] = {z, 2e9};
    y >>= 1;
    while (y) {
        t[x][y] = t[x][y + y];
        int xx = t[x][y + y + 1].first;
        int yy = t[x][y + y + 1].second;
        if (xx <= t[x][y].first) {
            t[x][y].second = t[x][y].first;
            t[x][y].first = xx;
        } else if (xx < t[x][y].second) t[x][y].second = xx;
        xx = yy;
        if (xx <= t[x][y].first) {
            t[x][y].second = t[x][y].first;
            t[x][y].first = xx;
        } else if (xx < t[x][y].second) t[x][y].second = xx;
        y >>= 1;
    }
    return;
}

void add(int x, int y) {
    int yy = y;
    for (int i = 0; i < 10; ++i) {
        int z = y % 10;
        y /= 10;
        if (z == 0) update(i, x, 2e9);
        else update(i, x, yy);
    }
    return;
}

pair<int, int> get(int l, int r, int ll, int rr, int x, int y) {
    if (l > r || ll > r || l > rr || ll > rr) return {2e9, 2e9};
    if (l >= ll && r <= rr) return t[x][y];
    int mid = (l + r) >> 1;
    pair<int, int> res = get(l, mid, ll, rr, x, y + y);
    pair<int, int> cur = get(mid + 1, r, ll, rr, x, y + y + 1);
    int xx = cur.first;
    if (xx <= res.first) {
        res.second = res.first;
        res.first = xx;
    } else if (xx < res.second) res.second = xx;
    xx = cur.second;
    if (xx <= res.first) {
        res.second = res.first;
        res.first = xx;
    } else if (xx < res.second) res.second = xx;
    return res;
}

int solve(int l, int r) {
    int res = 2e9 + 5;
    for (int i = 0; i < 10; ++i) {
        pair<int, int> cur = get(1, sz, l, r, i, 1);
        if (cur.first < 2e9 && cur.second < 2e9) res = min(res, cur.first + cur.second);
    }
    return (res < 2e9 + 5 ? res : -1);
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    sz = 1;
    while (sz < n) sz += sz;
    for (int i = 0; i < 10; ++i) {
        for (int j = 1; j <= sz + sz; ++j) {
            t[i][j] = {2e9, 2e9};
        }
    }
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        add(i, x);
    }
    for (int i = 1; i <= m; ++i) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int x, y;
            cin >> x >> y;
            add(x, y);
        } else {
            int l, r;
            cin >> l >> r;
            cout << solve(l, r) << '\n';
        }
    }
    return 0;
}