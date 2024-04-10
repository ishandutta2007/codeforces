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
long long t[2000005];
vector<int> v[300005];
long long ans[300005];
vector<pair<int, int > > q[300005];

void update(int l, int r, int ll, int rr, int x, int y) {
    if (l > r || ll > r || l > rr || ll > rr) return;
    if (l >= ll && r <= rr) {
        t[x] += y;
        return;
    }
    int mid = (l + r) >> 1;
    update(l, mid, ll, rr, x + x, y);
    update(mid + 1, r, ll, rr, x + x + 1, y);
    return;
}

long long get(int l, int r, int ll, int x) {
    if (l > r || l > ll || ll > r) return 0;
    if (l == r) return t[x];
    int mid = (l + r) >> 1;
    if (ll <= mid) return get(l, mid, ll, x + x) + t[x];
    return get(mid + 1, r, ll, x + x + 1) + t[x];
}

void dfs(int x, int y, int c = 1) {
    for (int i = 0; i < q[x].size(); ++i) {
        int xx = q[x][i].first;
        update(1, sz, c, c + xx, 1, q[x][i].second);
    }
    ans[x] = get(1, sz, c, 1);
    for (int i = 0; i < v[x].size(); ++i) {
        int to = v[x][i];
        if (to != y)
        dfs(to, x, c + 1);
    }
    for (int i = 0; i < q[x].size(); ++i) {
        int xx = q[x][i].first;
        update(1, sz, c, c + xx, 1, -q[x][i].second);
    }
    return;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cin >> m;
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        q[x].push_back({y, z});
    }
    sz = 1;
    while (sz < n + n) sz += sz;
    dfs(1, 0);
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << '\n';
}