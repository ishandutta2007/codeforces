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
const long long md = 1e9 + 7;


int n;
int dp[2005][2005];
pair<int, bool> dp2[2005][2005];

void init() {
    dp[0][0] = 1;
    for (int i = 0; i < n + n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j) {
                dp[i + 1][j - 1] += dp[i][j];
                if (dp[i + 1][j - 1] >= md) dp[i + 1][j - 1] -= md;
            }
            dp[i + 1][j + 1] += dp[i][j];
            if (dp[i + 1][j + 1] >= md) dp[i + 1][j + 1] -= md;
        }
    }
    return;
}

long long solve() {
    long long cur1, cur2;
    bool cur3;
    long long ans = 0;
    dp2[n + n][0].second = true;
    for (int i = n + n - 1; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) if (dp[n + n - i][j]) {
            cur1 = dp[i][j];
            cur3 = dp2[i + 1][j + 1].second;
            if (j) {
                cur3 |= dp2[i + 1][j - 1].second;
            }
            if (cur3) {
                ans += cur1;
                if (ans >= md) ans -= md;
            }
            cur3 ^= 1;
            dp2[i][j].second = cur3;
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    init();
    cout << solve() << '\n';
}