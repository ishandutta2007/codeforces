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

int h, w, n;

bool used1[4005];
bool used2[4005];
int dp1[4005][4005];
int dp2[4005][4005];
int dp[4005][4005];
long long f[4005];

void init() {
    f[0] = 1;
    for (int i = 1; i <= 4000; ++i)
        f[i] = (f[i - 1] * 1ll * i) % md;
    dp[0][0] = 1;
    for (int i = 1; i <= max(h, w); ++i) {
        for (int j = 0; j <= i; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j) {
                dp[i][j] += dp[i - 1][j - 1];
                if (dp[i][j] >= md) dp[i][j] -= md;
            }
        }
    }
    dp1[0][0] = 1;
    for (int i = 1; i <= h; ++i) {
        for (int j = 0; j <= i / 2; ++j) {
            dp1[i][j] = dp1[i - 1][j];
            if (i > 1 && j && !used1[i] && !used1[i - 1]) {
                dp1[i][j] += dp1[i - 2][j - 1];
                if (dp1[i][j] >= md) dp1[i][j] -= md;
            }
        }
    }
    dp2[0][0] = 1;
    for (int i = 1; i <= w; ++i) {
        for (int j = 0; j <= i / 2; ++j) {
            dp2[i][j] = dp2[i - 1][j];
            if (i > 1 && j && !used2[i] && !used2[i - 1]) {
                dp2[i][j] += dp2[i - 2][j - 1];
                if (dp2[i][j] >= md) dp2[i][j] -= md;
            }
        }
    }
    return;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> h >> w >> n;
    for (int i = 1; i <= n; ++i) {
        int x, y, xx, yy;
        cin >> x >> y >> xx >> yy;
        used1[x] = used1[xx] = true;
        used2[y] = used2[yy] = true;
    }
    init();
    int c1 = 0, c2 = 0;
    for (int i = 1; i <= h; ++i)
        if (!used1[i]) ++c1;
    for (int i = 1; i <= w; ++i)
        if (!used2[i]) ++c2;
    long long ans = 0;
    long long cur = 0;
    for (int i = 0; i <= c1 && i + i <= c2; ++i) {
        for (int j = 0; i + j + j <= c1 && i + i + j <= c2; ++j) {
            cur = dp1[h][j];
            cur *= dp2[w][i];
            cur %= md;
            cur *= dp[c1 - j - j][i];
            cur %= md;
            cur *= f[i];
            cur %= md;
            cur *= dp[c2 - i - i][j];
            cur %= md;
            cur *= f[j];
            cur %= md;
            ans += cur;
            if (ans >= md) ans -= md;
        }
    }
    cout << ans << '\n';
    return 0;
}