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


int n, m, k;
long long a[200005], b[200005];
int pr[200005];
long long dp[200005];

inline long long get(int l, int r) {
    if (l > r) return 0;
    return b[r] - b[l - 1];
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    n = k;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        if (x > n) continue;
        pr[x] = max(pr[x], y);
    }
    long long cur;
    for (int i = 1; i <= n; ++i)
        b[i] = b[i - 1] + a[i];
    for (int i = 1; i <= n; ++i) {
        dp[i] = 1e18;
        dp[i] = min(dp[i], dp[i - 1] + a[i]);
        for (int j = 1; j <= i; ++j) {
            cur = dp[i - j] + get(i - j + 1 + pr[j], i);
            if (cur < dp[i]) dp[i] = cur;
        }
    }
    cout << dp[n] << '\n';
}