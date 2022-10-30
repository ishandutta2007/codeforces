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


int n;
int a[200005];
int depth[200005];
int dp[200005][18];
vector<int> v[200005];
int h;
int nxt[200005];
int cnt[200005];

inline int get_dist(int x) {
    cout << "d " << x << endl;
    int res;
    cin >> res;
    return res;
}

inline int get_next(int x) {
    cout << "s " << x << endl;
    int res;
    cin >> res;
    return res;
}

void prnt(int x) {
    cout << "! " << x << endl;
    exit(0);
}

void dfs(int x, int y) {
    if (y) depth[x] = depth[y] + 1;
    dp[x][0] = y;
    for (int i = 1; i <= 17; ++i)
        dp[x][i] = dp[dp[x][i - 1]][i - 1];
    nxt[x] = x;
    cnt[x] = 1;
    if (depth[x] == h) {
        v[x].clear();
        return;
    }
    int mx = 0;
    for (int i = 0; i < (int)v[x].size(); ++i) {
        int to = v[x][i];
        if (to != y) {
            dfs(to, x);
            if (cnt[to] > mx) {
                mx = cnt[to];
                nxt[x] = nxt[to];
            }
            cnt[x] += cnt[to];
        }
    }
    return;
}

int get_pred(int x, int y) {
    for (int i = 19; i >= 0; --i)
        if (dp[x][i] && (1 << i) <= y) x = dp[x][i], y -= (1 << i);
    return x;
}

void solve(int x) {
    if (depth[x] == h) prnt(x);
    int y = nxt[x];
    int z = get_dist(y);
    if (z == 0) prnt(y);
    int hh = (depth[y] + h - z) / 2;
    hh = depth[y] - hh;
    y = get_pred(y, hh);
    y = get_next(y);
    solve(y);
    return;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    //freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    cin >> n;
    int x, y;
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    h = get_dist(1);
    if (h == 0) prnt(1);
    dfs(1, 0);
    solve(1);
    return 0;
}