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


long long n, m;
string s;
long long dp[105][105];
bool u[1005];

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    cin >> s;
    s = "#" + s;
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) if (dp[i][j]) {
            for (int k = 0; k < 26; ++k)
                u[k] = false;
            for (int z = i + 1; z <= n; ++z) if (!u[s[z] - 'a']) {
                u[s[z] - 'a'] = true;
                dp[z][j + 1] += dp[i][j];
                if (dp[z][j + 1] >= m) dp[z][j + 1] = m;
            }
        }
    }
    long long ans = m * n;
    for (int i = n; i >= 0; --i) {
        long long z = 0;
        for (int j = 0; j <= n; ++j)
            z += dp[j][i];
        z = min(z, m);
        m -= z;
        ans -= i * 1ll * z;
    }
    if (m > 0) cout << "-1\n";
    else cout << ans << '\n';
    return 0;
}