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

int n, m;
int a[505];
long long dp[505][505];

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        dp[i][i] = dp[i][i - 1] = 1;
    dp[n + 1][n] = 1;
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i <= n - len + 1; ++i) {
            int j = i + len - 1;
            int mn = 1e9, pos = 0;
            for (int k = i; k <= j; ++k) if (a[k] < mn) {
                mn = a[k];
                pos = k;
            }
            long long s = 0;
            long long ss = 0;
            for (int l = pos; l >= i; --l) {
                s += (dp[l][pos - 1] * dp[i][l - 1]) % md;
            }
            for (int r = pos; r <= j; ++r) {
                ss += (dp[pos + 1][r] * dp[r + 1][j]) % md;
            }
//            cout << i << " " << j << " " << s << " " << ss << '\n';
            s %= md;
            ss %= md;
            s *= ss;
            s %= md;
            dp[i][j] = s;
        }
    }
    cout << dp[1][n] << '\n';
    return 0;
}