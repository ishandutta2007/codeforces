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

int n;
int a[5005], b[5005];
int cnt[5005];
int c[5005];
int m;
int dp[5005][5005];
long long r[5005];
long long ans;

inline long long pw(long long x, long long y) {
    long long res = 1;
    while (y) {
        if (y & 1ll) res = (res * x) % md;
        x = (x * x) % md;
        y >>= 1;
    }
    return res;
}

void init() {
    r[0] = 1;
    for (int i = 1; i <= n; ++i)
        r[i] = pw(i, md - 2);
    return;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    init();
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = a[i];
        ++cnt[a[i]];
    }
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; ++i)
        if (i == 1 || b[i] != b[i - 1]) b[++m] = b[i];
    dp[0][0] = 1;
    int x, y;
    long long cur;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j <= i; ++j) if (dp[i][j]) {
            dp[i + 1][j] += dp[i][j];
            if (dp[i + 1][j] >= md) dp[i + 1][j] -= md;
            x = cnt[b[i + 1]];
            y = n - j;
            cur = dp[i][j];
            cur *= x;
            cur %= md;
            cur *= r[y];
            cur %= md;
            dp[i + 1][j + 1] += cur;
            if (dp[i + 1][j + 1] >= md) dp[i + 1][j + 1] -= md;
            if (x > 1) {
                cur *= x - 1;
                cur %= md;
                cur *= r[y - 1];
                cur %= md;
                ans += cur;
                if (ans >= md) ans -= md;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}