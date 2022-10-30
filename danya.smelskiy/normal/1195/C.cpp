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
long long a[2][100005];
long long dp[100005][2];

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < 2; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 2; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][1 - j] + a[j][i]);
        }
    }
    cout << max(dp[n][0], dp[n][1]);
    cout << '\n';
    return 0;
}