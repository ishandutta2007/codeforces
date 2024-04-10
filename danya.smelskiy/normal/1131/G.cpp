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
long long x, y;
vector<int> h[250005], c[250005];
int mm;
pair<int, long long> a[10000005];
long long dp[10000005];
int lft[10000005];
int rght[10000005];
int sz;
int q[10000005];
long long dp2[10000005];

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        for (int j = 1; j <= x; ++j) {
            cin >> y;
            h[i].push_back(y);
        }
        for (int j = 1; j <= x; ++j) {
            cin >> y;
            c[i].push_back(y);
        }
    }
    cin >> mm;
    m = 0;
    for (int i = 1; i <= mm; ++i) {
        cin >> x >> y;
        for (int j = 0; j < (int)h[x].size(); ++j) {
            a[++m] = make_pair(h[x][j], c[x][j] * 1ll * y);
        }
    }
    for (int i = m; i > 0; --i) {
        dp[i] = 1e18;
        rght[i] = i + a[i].first - 1;
        while (sz && q[sz] <= rght[i]) {
            x = q[sz];
            y = rght[x];
            if (y > rght[i]) rght[i] = y;
            --sz;
        }
        q[++sz] = i;
    }
    sz = 0;
    int pos;
    long long curdp = 1e18, curdp2;
    long long cur;
    for (int i = 1; i <= m; ++i) {
        lft[i] = i - a[i].first + 1;
        curdp = 1e18;
        while (sz && q[sz] >= lft[i]) {
            x = q[sz];
            if (dp2[x] < curdp) curdp = dp2[x];
            y = lft[x];
            if (y < lft[i]) lft[i] = y;
            --sz;
        }
        q[++sz] = i;
        cur = dp[i - 1] + a[i].second;
        pos = rght[i];
        if (pos > m) pos = m;
        if (cur < dp[pos]) dp[pos] = cur;
        pos = lft[i] - 1;
        if (pos < 0) pos = 0;
        curdp2 = curdp;
        if (dp[pos] < curdp2) curdp2 = dp[pos];
        cur = curdp2 + a[i].second;
        if (cur < dp[i]) dp[i] = cur;
        if (dp[i] < curdp) curdp = dp[i];
        dp2[i] = curdp;
    }
    cout << dp[m] << '\n';
    return 0;
}