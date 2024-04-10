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
long long a[200005], dp[200005][2];
int ans;


int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i - 1][1];
        dp[i][(i & 1)] += a[i];
    }
    for (int i = 1; i <= n; ++i) {
        long long x = dp[i - 1][1];
        long long y = dp[i - 1][0];
        if (i & 1) {
            x += dp[n][0] - dp[i][0];
            y += dp[n][1] - dp[i][1];
        } else {
            x += dp[n][0] - dp[i][0];
            y += dp[n][1] - dp[i][1];
        }
        if (x == y) ++ans;
    }
    cout << ans << '\n';
}