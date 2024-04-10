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
int dp[100005][2];

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    n = (int)s.size();
    s = "#" + s;
    for (int i = n; i > 0; --i) {
        if (s[i] == '0') {
            dp[i][0] = max(dp[i + 1][0], dp[i + 1][1]) + 1;
            dp[i][1] = dp[i + 1][1];
        } else {
            dp[i][0] = dp[i + 1][0];
            dp[i][1] = dp[i + 1][1] + 1;
        }
    }
    for (int i = 1; i <= n; ++i) if (s[i] == '1') {
        int x = max(dp[i][0], dp[i][1]);
        int y = max(dp[i + 1][0], dp[i + 1][1]) + 1;
        if (y == x) s[i] = '0';
    }
    for (int i = 1; i <= n; ++i)
        cout << s[i];
    cout << '\n';
    return 0;
}