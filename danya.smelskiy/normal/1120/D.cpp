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
vector<int> v[200005], vv;
long long dp[200005][2];
long long a[200005];
long long nxt[200005][2];
long long ans;
vector<int> qq;

void dfs(int x, int y) {
    vv.clear();
    for (int i = 0; i < v[x].size(); ++i) {
        int to = v[x][i];
        if (to != y) vv.push_back(to);
    }
    v[x] = vv;
    if ((int)vv.size() == 0) {
        dp[x][1] = 0;
        dp[x][0] = a[x];
        return;
    }
    long long sum = 0;
    for (int i = 0; i < v[x].size(); ++i) {
        int to = v[x][i];
        dfs(to, x);
        sum += dp[to][0];
    }
    dp[x][0] = sum;
    dp[x][1] = sum;
    for (int i = 0; i < v[x].size(); ++i) {
        int to = v[x][i];
        dp[x][1] = min(dp[x][1], sum - dp[to][0] + dp[to][1]);
    }
    dp[x][0] = min(dp[x][0], dp[x][1] + a[x]);
    return;
}

bool isin[200005];

void solve(int x, long long y, long long z) {
    if (v[x].size() == 0) {
        if (dp[x][0] + y == ans) isin[x] = true;
    } else {
        long long sum = 0;
        long long mn = 1e18;
        for (int i = 0; i < v[x].size(); ++i) {
            int to = v[x][i];
            sum += dp[to][0];
            mn = min(mn, dp[to][1] - dp[to][0]);
        }
        if (sum + mn + a[x] + y == ans) {
            isin[x] = true;
        }
    }
    if (isin[x]) qq.push_back(x);
    long long ss1 = 0, ss2 = 0;
    long long mn1 = 1e15, mn2 = 1e15;
    int pos1, pos2;
    pos1 = pos2 = - 1;
    for (int i = 0; i < v[x].size(); ++i) {
        int to = v[x][i];
        ss1 += dp[to][0];
        ss2 += dp[to][1];
        long long xx = dp[to][1] - dp[to][0];
        if (xx <= mn1) {
            mn2 = mn1;
            pos2 = pos1;
            mn1 = xx;
            pos1 = to;
        } else if (xx < mn2) {
            mn2 = xx;
            pos2 = to;
        }
    }
    for (int i = 0; i < v[x].size(); ++i) {
        int to = v[x][i];
        nxt[to][0] = nxt[to][1] = 1e16;
    }
    
    
    for (int i = 0; i < v[x].size(); ++i) {
        int to = v[x][i];
        nxt[to][0] = y + ss1 - dp[to][0];
        long long yy = y + ss1 - dp[to][0] + a[x];
        if (pos1 != to) yy += mn1;
        else yy += mn2;
        nxt[to][0] = min(nxt[to][0], yy);
        yy = y + ss1 - dp[to][0] + a[x];
        nxt[to][1] = min(nxt[to][1], yy);
    }
    for (int i = 0; i < v[x].size(); ++i) {
        int to = v[x][i];
        long long yy = z + ss1 - dp[to][0];
        nxt[to][1] = min(nxt[to][1], yy);
        yy = z + ss1 - dp[to][0];
        if (pos1 != to) yy += mn1;
        else yy += mn2;
        nxt[to][0] = min(nxt[to][0], yy);
    }
    
    
    for (int i = 0; i < v[x].size(); ++i) {
        int to = v[x][i];
        solve(to, nxt[to][0], nxt[to][1]);
    }
    return;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, 0);
    ans = dp[1][0];
    solve(1, 0, 1e16);
    sort(qq.begin(), qq.end());
    cout << ans << " " << qq.size() << '\n';
    for (int i = 0; i < qq.size(); ++i)
        cout << qq[i] << " ";
    cout << '\n';
}