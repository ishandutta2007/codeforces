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


int n, m, x, y, z;
int ans, timer;
int tin[200005];
int tout[200005];
int dp[200005][19];
int dp2[200005][19];
bool used[200005];
pair<int, int> e[200005];
int len[200005];
vector<pair<pair<int, int>, pair<int, int> > > q;
int p[200005];
vector<pair<int, int> > v[200005];

void dfs(int x, int y, int z) {
    dp[x][0] = y;
    dp2[x][0] = z;
    tin[x] = ++timer;
    for (int i = 1; i <= 18; ++i) {
        dp[x][i] = dp[dp[x][i - 1]][i - 1];
        dp2[x][i] = max(dp2[x][i - 1], dp2[dp[x][i - 1]][i - 1]);
    }
    for (int i = 0; i < (int)v[x].size(); ++i) {
        int to = v[x][i].first;
        if (to == y) continue;
        dfs(to, x, v[x][i].second);
    }
    tout[x] = timer;
    return;
}

int get(int x) {
    if (x == p[x]) return x;
    return p[x] = get(p[x]);
}

inline bool f_pred(int x, int y) {
    return (tin[x] <= tin[y] && tout[x] >= tout[y]);
}

inline int get_lca(int x, int y) {
    if (tin[x] > tin[y]) swap(x, y);
    if (f_pred(x, y)) return x;
    for (int i = 18; i >= 0; --i)
        if (dp[x][i] && !f_pred(dp[x][i], y)) x = dp[x][i];
    return dp[x][0];
}

int get2(int x, int y) {
    if (x == y) return 0;
    int res = 0;
    for (int i = 18; i >= 0; --i)
        if (dp[y][i] && !f_pred(dp[y][i], x)) {
            res = max(res, dp2[y][i]);
            y = dp[y][i];
        }
    return max(res, dp2[y][0]);
}

inline int solve(int x, int y) {
    z = get_lca(x, y);
    return max(get2(z, x), get2(z, y));
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y >> z;
        e[i] = make_pair(x, y);
        len[i] = z;
        q.push_back(make_pair(make_pair(z, i), make_pair(x, y)));
    }
    for (int i = 1; i <= n; ++i)
        p[i] = i;
    sort(q.begin(), q.end());
    for (int i = 0; i < (int)q.size(); ++i) {
        int x = q[i].second.first;
        x = get(x);
        int y = q[i].second.second;
        y = get(y);
        if (x == y) continue;
        used[q[i].first.second] = true;
        p[y] = x;
        x = q[i].second.first;
        y = q[i].second.second;
        v[x].push_back(make_pair(y, q[i].first.first));
        v[y].push_back(make_pair(x, q[i].first.first));
    }
    dfs(1, 0, 0);
    for (int i = 1; i <= m; ++i)
        if (!used[i]) {
            x = e[i].first;
            y = e[i].second;
            if (solve(x, y) == len[i]) ++ans;
        }
    cout << ans << '\n';
}