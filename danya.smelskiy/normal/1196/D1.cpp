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
string s;
int dp[200005][3][3];

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        cin >> s;
        for (int i = 1; i <= n; ++i) {
            int x;
            if (s[i - 1] == 'R') x = 0;
            else if (s[i - 1] == 'G') x = 1;
            else x = 2;
            for (int j = 0; j < 3; ++j)
                for (int k = 0; k < 3; ++k)
                    dp[i][j][k] = dp[i - 1][j][k];
            ++dp[i][x][(i % 3)];
        }
        int ans = m;
        for (int i = 1; i <= n - m + 1; ++i) {
            for (int j = 0; j < 3; ++j) {
                int cur = m;
                for (int k = 0; k < 3; ++k) {
                    cur -= dp[i + m - 1][k][(i + (3 + k - j)) % 3] - dp[i - 1][k][(i + (3 + k - j)) % 3];
                }
                ans = min(ans, cur);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}