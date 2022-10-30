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
int a[1000005];
int dp[(1 << 22) + 5][2];
int ans;


int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (dp[a[i]][0]) {
            dp[a[i]][1] = dp[a[i]][0];
            dp[a[i]][0] = i;
        } else dp[a[i]][0] = i;
    }
    int x, y, z;
    for (int i = 0; i <= 21; ++i) {
        for (int j = 0; j < (1 << 21); ++j) if (!(j & (1 << i))) {
            x = (j | (1 << i));
            if (dp[x][1] > dp[j][0]) {
                dp[j][1] = dp[j][0];
                dp[j][0] = dp[x][1];
            } else if (dp[x][1] > dp[j][1]) {
                dp[j][1] = dp[x][1];
            }
            if (dp[x][0] > dp[j][0]) {
                dp[j][1] = dp[j][0];
                dp[j][0] = dp[x][0];
            } else if (dp[x][0] > dp[j][1]) {
                dp[j][1] = dp[x][0];
            }
        }
    }
    for (int i = 1; i <= n - 2; ++i) {
        x = a[i];
        y = 0;
        for (int j = 21; j >= 0; --j) if (!(x & (1 << j))) {
            z = (y | (1 << j));
            if (dp[z][0] > i && dp[z][1] > i) y |= (1 << j);
        }
        ans = max(ans, x | y);
    }
    cout << ans << '\n';
    return 0;
}