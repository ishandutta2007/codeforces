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
int a[100005];
int t[600005];
pair<int, int> q1[100005];
int ans[100005];
pair<int, int> rng[100005];
int f[2][100005];
char ch[100005];
int val[100005];
vector<int> iv[100005];
int pos[100005];

pair<int, int> get_range(int xx, int yy) {
    if (xx > yy) swap(xx, yy);
    int l = 1, r = m;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (q1[mid].first >= xx) r = mid;
        else l = mid + 1;
    }
    if (q1[l].first < xx || q1[l].first > yy) return make_pair(1, 0);
    int ll = l;
    l = 1;
    r = m;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (q1[mid].first <= yy) l = mid;
        else r = mid - 1;
    }
    return make_pair(ll, r);
}

int get_pos(int l, int r, int ll, int rr, int x) {
    if (l > r || ll > r || l > rr || ll > rr) return 1;
    if (l >= ll && r <= rr) return t[x] + 1;
    int mid = (l + r) >> 1;
    return max(get_pos(l, mid, ll, rr, x + x), get_pos(mid + 1, r, ll, rr, x + x + 1));
}

void update(int x, int y) {
    while (y <= m) {
        f[x][y]++;
        y = (y | (y + 1));
    }
    return;
}

int get_pos(int x) {
    int l = 1;
    int r = m;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (q1[mid].first >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}

int get(int x, int y) {
    int res = 0;
    while (y >= 0) {
        res += f[x][y];
        y = (y & (y + 1)) - 1;
    }
    return res;
}

int get(int x, int l, int r) {
    return get(x, r) - get(x, l - 1);
}

void solve(int x) {
    int y = abs(a[x]);
    int l = 1;
    int r = m;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (q1[mid].first > y) r = mid;
        else l = mid + 1;
    }
    if (q1[l].first > y) {
        ans[x] ^= get(0, l, m);
//        if (x == 1) cout << ">" << ans[x] << " " << get(0, l, m) << '\n';
    }
    l = 1;
    r = m;
    y *= -1;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (q1[mid].first < y) l = mid;
        else r = mid - 1;
    }
    if (q1[l].first < y) ans[x] ^= get(1, 1, l);
    return;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> ch[i] >> val[i];
        if (ch[i] == '<') {
            if (val[i] < 0) --val[i];
        } else if (ch[i] == '>') {
            if (val[i] > 0) ++val[i];
        }
        q1[i] = {val[i], i};
    }
    sort(q1 + 1, q1 + m + 1);
    sz = 1;
    while (sz < m) sz += sz;
    for (int i = 1; i <= sz + sz; ++i)
        t[i] = -1e9;
    for (int i = 1; i <= m; ++i)
        t[sz + i - 1] = q1[i].second;
    for (int i = sz - 1; i > 0; --i)
        t[i] = max(t[i + i], t[i + i + 1]);
    int x;
    for (int i = 1; i <= n; ++i) {
        rng[i] = get_range(-a[i], a[i]);
        pos[i] = get_pos(1, sz, rng[i].first, rng[i].second, 1);
        x = pos[i] - 1;
        if (x <= m) {
            iv[x].push_back(i);
        }
        if (!x) continue;
        if (ch[x] == '<') a[i] = abs(a[i]);
        else if (ch[x] == '>') a[i] = -abs(a[i]);
//        cout << ">" << i << " " << a[i] << " " << pos[i] << '\n';
    }
    for (int i = m; i >= 0; --i) {
        for (int j = 0; j < iv[i].size(); ++j) {
            solve(iv[i][j]);
        }
        if (!i) continue;
        x = get_pos(val[i]);
        if (ch[i] == '<') update(0, x);
        else update(1, x);
    }
    for (int i = 1; i <= n; ++i) {
        if ((ans[i] & 1)) a[i] *= -1;
        if (i > 1) cout << " ";
        cout << a[i];
    }
    cout << '\n';
    return 0;
}