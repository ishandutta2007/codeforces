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
long long a[300005];
long long b[300005];
long long dp[300005][6];

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i] >> b[i];
        }
        for (int i = 0; i <= 5; ++i)
            dp[1][i] = i * 1ll * b[1];
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j <= 5; ++j) {
                long long cur = j * 1ll * b[i];
                long long cur2 = 2e18;
                for (int k = 0; k <= 5; ++k)
                    if (a[i - 1] + k != a[i] + j) cur2 = min(cur2, dp[i - 1][k]);
                dp[i][j] = cur + cur2;
            }
        }
        long long res = 2e18;
        for (int i = 0; i <= 5; ++i)
            res = min(res, dp[n][i]);
        cout << res << '\n';
    }
    return 0;
}