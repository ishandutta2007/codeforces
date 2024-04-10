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



int n, m, k, sz;
int q[3000005];
pair<int, int> t[3000005];
vector<int> v[100005];
int ans[100005], a[100005], tp[100005];

void push(int x) {
    q[x + x] ^= 1;
    q[x + x + 1] ^= 1;
    swap(t[x + x].first, t[x + x].second);
    swap(t[x + x + 1].first, t[x + x + 1].second);
    q[x] = 0;
    return;
}

void update(int l, int r, int ll, int rr, int x, int y) {
    if (l > r || ll > r || l > rr || ll > rr) return;
    if (l == r) {
        if (!y) t[x] = {1, 0};
        else t[x] = {0, 1};
        return;
    }
    if (q[x]) push(x);
    int mid = (l + r) >> 1;
    if (ll <= mid) update(l, mid, ll, rr, x + x, y);
    else update(mid + 1, r, ll, rr, x + x + 1, y);
    t[x].first = t[x + x].first + t[x + x + 1].first;
    t[x].second = t[x + x].second + t[x + x + 1].second;
    return;
}

void rev(int l, int r, int ll, int rr, int x) {
    if (l > r || ll > r || l > rr || ll > rr) return;
    if (l >= ll && r <= rr) {
        q[x] ^= 1;
        swap(t[x].first, t[x].second);
        return;
    }
    if (q[x]) push(x);
    int mid = (l + r) >> 1;
    rev(l, mid, ll, rr, x + x);
    rev(mid + 1, r, ll, rr, x + x + 1);
    t[x].first = t[x + x].first + t[x + x + 1].first;
    t[x].second = t[x + x].second + t[x + x + 1].second;
    return;
}

bool check(int l, int r, int ll, int x) {
    if (l == r) return (t[x].second);
    int mid = (l + r) >> 1;
    if (q[x]) push(x);
    if (ll <= mid) return check(l, mid, ll, x + x);
    else return check(mid + 1, r, ll, x + x + 1);
}

void dfs(int x) {
    bool df = false;
    if (tp[x] == 1) {
        int y = a[x];
        if (!check(1, sz, y, 1)) df = true;
        update(1, sz, y, y, 1, 1);
    } else if (tp[x] == 2) {
        int y = a[x];
        if (check(1, sz, y, 1)) df = true;
        update(1, sz, y, y, 1, 0);
    } else if (tp[x] == 3) {
        int l = (a[x] - 1) * m + 1;
        int r = a[x] * m;
        rev(1, sz, l, r, 1);
    }
    ans[x] = t[1].second;
    for (int i = 0; i < v[x].size(); ++i) {
        int to = v[x][i];
        dfs(to);
    }
    if (df) {
        int y = a[x];
        update(1, sz, y, y, 1, (tp[x] == 1 ? 0 : 1));
    } else if (tp[x] == 3) {
        int l = (a[x] - 1) * m + 1;
        int r = a[x] * m;
        rev(1, sz, l, r, 1);
    }
    return;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= k; ++i) {
        cin >> tp[i];
        if (tp[i] <= 2) {
            int x, y;
            cin >> x >> y;
            x = (x - 1) * m + y;
            a[i] = x;
            v[i - 1].push_back(i);
        } else if (tp[i] == 3) {
            cin >> a[i];
            v[i - 1].push_back(i);
        } else {
            int x;
            cin >> x;
            v[x].push_back(i);
        }
    }
    sz = 1;
    while (sz < n * m) sz += sz;
    for (int i = 1; i <= n * m; ++i)
        t[sz + i - 1].first = 1;
    for (int i = sz - 1; i > 0; --i)
        t[i].first = t[i + i].first + t[i + i + 1].first;
    dfs(0);
    for (int i = 1; i <= k; ++i)
        cout << ans[i] << '\n';
}