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
const long long md = 998244353;

int n, m, k, len;
int m1[200], m2[200];
int nxt[100005][105];
int q[100005][105];
int dp[100005][105];
int a[100005];
int s, x, y;

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k >> len;
    --len;
    if (len <= 0) {
        cout << "0" << endl;
        return 0;
    }
    for (int i = 1;i <= n; ++i)
        cin >> a[i];
    for (int i = 1;i <= k; ++i)
        nxt[n + 1][i] = n + 1;
    for (int i = n;i > 0; --i) {
        for (int j = 1;j <= k; ++j) {
            nxt[i][j] = nxt[i + 1][j];
            if (j == a[i + 1]) nxt[i][j] = i + 1;
        }
    }
    dp[0][0] = 1;
    int cur, r;
    for (int i = 1;i <= n; ++i) {
        s = 0;
        for (int j = 0;j <= k; ++j) {
            s += dp[i-1][j];
            if (s >= md) s -= md;
        }
        m1[0] = n;
        for (int j = 1;j <= k; ++j) {
            m1[j] = m1[j-1];
            if (nxt[i][j] - 1 < m1[j]) m1[j] = nxt[i][j] - 1;
        }
        m2[k + 1] = n;
        for (int j = k;j > 0; --j) {
            m2[j] = m2[j + 1];
            if (nxt[i][j] - 1< m2[j]) m2[j] = nxt[i][j] - 1;
        }
        for (int j = 1;j <= k; ++j) {
            if (a[i] != -1 && a[i] != j) continue;
            cur = s - dp[i-1][j];
            if (cur < 0) cur += md;
            r = m1[j - 1];
            if (m2[j + 1] < r) r = m2[j + 1];
            if (r > i + len - 1) r = i + len - 1;
            q[i][j] += cur;
            if (q[i][j] >= md) q[i][j] -= md;
            q[r + 1][j] -= cur;
            if (q[r + 1][j] < 0) q[r + 1][j] += md;
        }
        for (int j = 1;j <= k; ++j) {
            q[i][j] += q[i-1][j];
            if (q[i][j] >= md) q[i][j] -= md;
            dp[i][j] = q[i][j];
        }
    }
    long long ans = 0;
    for (int i = 1;i <= k; ++i) {
        ans += dp[n][i];
        if (ans >= md) ans -= md;
    }
    cout << ans << '\n';
}