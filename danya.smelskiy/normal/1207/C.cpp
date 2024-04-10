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
long long a, b;
string s;
long long dp[200005][2];

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        cin >> s;
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j < 2; ++j)
                dp[i][j] = 3e14;
        dp[0][0] = b;
        dp[0][1] = 3e14;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] == '1') {
                dp[i][1] = b + b + dp[i - 1][1] + a;
            } else {
                dp[i][1] = min(dp[i - 1][1] + b + b + a, dp[i - 1][0] + b + b + a + a);
                dp[i][0] = min(dp[i - 1][0] + b + a, dp[i - 1][1] + b + a + a);
            }
        }
        cout << dp[n][0] << '\n';
    }
    return 0;
}