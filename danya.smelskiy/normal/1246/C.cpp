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
const int md = 1e9 + 7;

int n, m;
string s[2005];
int c[2005][2005];
int q2[2005];
int q1[2005][2005];
int dp[2005][2005][2];

int get(int x, int y, int xx, int yy) {
    int res = c[xx][yy] + c[x - 1][y - 1];
    res -= c[x - 1][yy] + c[xx][y - 1];
    return res;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        s[i] = "#" + s[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            c[i][j] = c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1];
            if (s[i][j] == 'R') ++c[i][j];
        }
    }
    dp[1][1][0] = dp[1][1][1] = 1;
    int cc, l, r;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            q2[j] = 0;
        }
        for (int j = 1; j <= m; ++j) {
            q1[i][j] += q1[i - 1][j];
            if (q1[i][j] >= md) q1[i][j] -= md;
            q2[j] += q2[j - 1];
            if (q2[j] >= md) q2[j] -= md;
            dp[i][j][0] += q2[j];
            if (dp[i][j][0] >= md) dp[i][j][0] -= md;
            dp[i][j][1] += q1[i][j];
            if (dp[i][j][1] >= md) dp[i][j][1] -= md;
//            cout << i << " " << j << " " << dp[i][j][0] + dp[i][j][1] << '\n';
            if (j < m) {
                cc = get(i, j + 1, i, m);
                l = j + 1;
                r = m - cc;
                if (l <= r) {
                    q2[l] += dp[i][j][1];
                    if (q2[l] >= md) q2[l] -= md;
                    q2[r + 1] -= dp[i][j][1];
                    if (q2[r + 1] < 0) q2[r + 1] += md;
                }
            }
            if (i < n) {
                cc = get(i + 1, j, n, j);
                l = i + 1;
                r = n - cc;
                if (l <= r) {
                    q1[l][j] += dp[i][j][0];
                    if (q1[l][j] >= md) q1[l][j] -= md;
                    q1[r + 1][j] -= dp[i][j][0];
                    if (q1[r + 1][j] < 0) q1[r + 1][j] += md;
                }
            }
        }
    }
    int res = dp[n][m][0] + dp[n][m][1];
    if (res >= md) res -= md;
    if (n == 1 && m == 1) {
        --res;
        if (res < 0) res += md;
    }
    cout << res << '\n';
    return 0;
}