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

int n, m;
int ans;
int dp[3][1000005];
int dp2[3][1000005];
int x;
int cnt[1000005];

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        ++cnt[x];
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j <= 2; ++j)
            for (int k = 0; k <= cnt[i]; ++k)
                dp2[j][k] = -1e6;
        for (int j = 0; j <= 2; ++j) {
            for (int k = 0; k <= cnt[i - 1]; ++k) {
                for (int z = 0; z <= min({j, k, cnt[i]}); ++z) {
                    dp2[min(3, k - z)][cnt[i] - z] = max(dp2[min(3, k - z)][cnt[i] - z], dp[j][k] + z);
                }
            }
        }
        for (int j = 0; j <= 2; ++j) {
            for (int k = cnt[i] - 3; k >= 0; --k) {
                dp2[j][k] = max(dp2[j][k], dp2[j][k + 3] + 1);
            }
            for (int k = cnt[i] - 1; k >= 0; --k)
                dp2[j][k] = max(dp2[j][k], dp2[j][k + 1]);
        }
        for (int j = 0; j <= 2; ++j)
            for (int k = 0; k <= cnt[i]; ++k)
                dp[j][k] = dp2[j][k];
    }
    for (int i = 0; i <= 2; ++i)
        for (int j = 0; j <= cnt[m]; ++j)
            ans = max(ans, dp[i][j]);
    cout << ans << '\n';
}