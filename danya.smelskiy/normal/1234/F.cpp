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


string s;
int n;
int dp[(1 << 21)];

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    n = s.size();
    s = "#" + s;
    for (int i = n; i > 0; --i) {
        int msk = 0;
        int x;
        for (int j = i; j <= n; ++j) {
            x = s[j] - 'a';
            x = (1 << x);
            if (msk & x) break;
            msk |= x;
            dp[msk] = j - i + 1;
        }
    }
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < (1 << 20); ++j) if ((j & (1 << i))) {
            dp[j] = max(dp[j], dp[j ^ (1 << i)]);
        }
    }
    int ans = 0;
    for (int i = 0; i < (1 << 20); ++i) ans = max(ans, dp[i] + dp[(1 << 20) - 1 - i]);
    cout << ans << '\n';
    return 0;
}