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
const int C = 10000000;
const long long md = 1e9 + 7;

int n, a[100005];
int dp[100005][19];
int timer, tin[100005], tout[100005];
vector<int> v[100005];
int lpd[10000001];
long long ans[100005];
int f[100005];
pair<int, int> qu[100005];
vector<pair<int, int> > iv[10000001];


void dfs(int x, int y = 0) {
    tin[x] = ++timer;
    dp[x][0] = y;
    for (int i = 1; i <= 18; ++i)
        dp[x][i] = dp[dp[x][i - 1]][i - 1];
    for (int i = 0; i < v[x].size(); ++i) {
        int to = v[x][i];
        if (to != y) dfs(to, x);
    }
    tout[x] = timer;
    return;
}

inline bool f_pred(int x, int y) {
    return (tin[x] <= tin[y] && tout[x] >= tout[y]);
}

int get_lca(int x, int y) {
    if (f_pred(x, y)) return x;
    if (f_pred(y, x)) return y;
    for (int i = 18; i >= 0; --i)
        if (dp[x][i] && !f_pred(dp[x][i], y)) x = dp[x][i];
    return dp[x][0];
}

void init() {
    vector<int> vs;
    lpd[1] = 1;
    for (int i = 2; i <= C; ++i) {
        if (!lpd[i]) {
            lpd[i] = i;
            vs.push_back(i);
        }
        for (int j = 0; j < (int)vs.size() && vs[j] <= lpd[i] && vs[j] * i <= C; ++j) {
            lpd[vs[j] * i] = vs[j];
        }
    }
    return;
}

vector<pair<int, int> > get_vector(int x) {
    vector<pair<int, int> > res;
    int last = 0;
    int c = 0;
    while (x > 1) {
        if (lpd[x] == last) {
            ++c;
            x /= lpd[x];
        } else {
            if (last) res.push_back({last, c});
            last = lpd[x];
            x /= last;
            c = 1;
        }
    }
    if (last) res.push_back({last, c});
    return res;
}

long long pw(long long x, long long y) {
    long long res = 1;
    while (y) {
        if (y & 1ll) res = (res * x) % md;
        x = (x * x) % md;
        y >>= 1;
    }
    return res;
}

int get(int x) {
    int res = 0;
    while (x >= 0) {
        res += f[x];
        x = (x & (x + 1)) - 1;
    }
    return res;
}

void clr(int x) {
    while (x <= n) {
        f[x] = 0;
        x = (x | (x + 1));
    }
    return;
}

void update(int x, int y) {
    while (x <= n) {
        f[x] += y;
        x = (x | (x + 1));
    }
    return;
}

void solve(int x) {
    sort(iv[x].begin(), iv[x].end());
    int xx, yy, zz, cur;
    for (int i = 0; i < (int)iv[x].size(); ++i) {
        yy = iv[x][i].second;
        if (yy < 0) {
            yy *= -1;
            update(tin[yy], 1);
            update(tout[yy] + 1, -1);
        } else {
            xx = qu[yy].first;
            zz = qu[yy].second;
            cur = get(tin[xx]) + get(tin[zz]) - get(tin[dp[get_lca(xx, zz)][0]]) - get(tin[get_lca(xx, zz)]);
            ans[yy] *= pw(x, cur);
            ans[yy] %= md;
        }
    }
    for (int i = 0; i < (int)iv[x].size(); ++i)
        if (iv[x][i].second < 0) {
            yy = iv[x][i].second;
            yy *= -1;
            clr(tin[yy]);
            clr(tout[yy] + 1);
        }
    return;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int x, y, z;
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    init();
    vector<pair<int, int> > cur_v;
    for (int i = 1; i <= n; ++i) {
        cur_v = get_vector(a[i]);
        for (int j = 0; j < cur_v.size(); ++j) {
            x = cur_v[j].first;
            y = cur_v[j].second;
            for (int k = 1; k <= y; ++k)
                iv[x].push_back({k, -i});
        }
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y >> z;
        qu[i] = {x, y};
        cur_v = get_vector(z);
        ans[i] = 1;
        for (int j = 0; j < (int)cur_v.size(); ++j) {
            x = cur_v[j].first;
            y = cur_v[j].second;
            iv[x].push_back({y, i});
        }
    }
    for (int i = 2; i <= C; ++i) if ((int)iv[i].size()) solve(i);
    for (int i = 1; i <= m; ++i)
        cout << ans[i] << '\n';
    return 0;
}