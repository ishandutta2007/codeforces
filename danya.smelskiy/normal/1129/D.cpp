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
const int md = 998244353;
const int sz = 250;

int n, m, all;
vector<pair<int, int> > v[100005];
int dp[100005];
int b[100005];
int cnt[100005];
int ob[100005];
vector<int> vv[100005];

void rebuild_block(int x) {
    v[x].clear();
    int l, r;
    if (x == 0) l = r = 0;
    else {
        l = (x - 1) * sz + 1;
        r = min(n, l + sz - 1);
    }
    for (int i = l; i <= r; ++i) {
        cnt[i] += ob[x];
        v[x].push_back({cnt[i], dp[i]});
    }
    ob[x] = 0;
    sort(v[x].begin(), v[x].end());
    for (int i = 1; i < v[x].size(); ++i) {
        v[x][i].second += v[x][i - 1].second;
        if (v[x][i].second >= md) v[x][i].second -= md;
    }
}

void update(int l, int r, int x) {
    if (b[l] == b[r]) {
        for (int i = l; i <= r; ++i)
            cnt[i] += x;
        rebuild_block(b[l]);
        return;
    }
    for (int i = l; b[i] == b[l]; ++i)
        cnt[i] += x;
    rebuild_block(b[l]);
    for (int i = r; i > 0 && b[i] == b[r]; --i)
        cnt[i] += x;
    rebuild_block(b[r]);
    for (int i = b[l] + 1; i < b[r]; ++i)
        ob[i] += x;
    return;
}

int solve(int x) {
    int l = 0;
    int r = (int)v[x].size() - 1;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (v[x][mid].first + ob[x] <= m) l = mid;
        else r = mid - 1;
    }
    if (v[x][l].first + ob[x] <= m) return v[x][l].second;
    return 0;
}

int get(int x) {
    int res = 0;
    for (int i = 0; i < b[x]; ++i) {
        res += solve(i);
        if (res >= md) res -= md;
    }
    int l = 0;
    if (b[x]) l = (b[x] - 1) * sz + 1;
    for (int i = l; i <= x; ++i) if (cnt[i] + ob[b[i]] <= m) {
        res += dp[i];
        if (res >= md) res -= md;
    }
    return res;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i <= n; ++i) {
        b[i] = (i + sz - 1) / sz;
    }
    all = b[n];
    for (int i = 0; i <= all; ++i) {
        rebuild_block(i);
    }
    dp[0] = 1;
    rebuild_block(0);
    for (int i = 1; i <= n; ++i)
        vv[i].push_back(0);
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if (vv[x].size() > 1) {
            int xx = vv[x][(int)vv[x].size() - 2];
            int yy = vv[x].back();
            update(xx, yy - 1, -1);
        }
        update(vv[x].back(), i - 1, 1);
        vv[x].push_back(i);
        dp[i] = get(i - 1);
        rebuild_block(b[i]);
    }
    cout << dp[n] << '\n';
    
}