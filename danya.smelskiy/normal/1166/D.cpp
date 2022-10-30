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
const long long mx = 1e18;



long long a, b, m;
long long c[100], d[100];
long long ans[100];
long long dp[100];

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> a >> b >> m;
        if (a == b) {
            cout << 1 << " " <<  a << '\n';
            continue;
        }
        if (a + m >= b) {
            cout << 2 << " " << a << " " << b << '\n';
            continue;
        }
        c[1] = a;
        d[1] = a;
        bool t = false;
        for (int len = 3; len <= 50; ++len) {
            for (int i = 1; i <= len; ++i)
                dp[i] = 0, ans[i] = 1;
            ans[1] = a;
            bool tt = false;
            dp[1] = a;
            for (int i = 2; i <= len; ++i) {
                for (int j = i - 1; j > 0; --j) {
                    dp[i] += dp[j];
                    if (dp[i] > b) {
                        tt = true;
                        break;
                    }
                }
                ++dp[i];
                if (dp[i] > b) tt = true;
                if (tt) break;
            }
            if (tt) continue;
            long long bb = b - dp[len];
            for (int i = 2; i <= len; ++i) {
                long long cur;
                if (i == len) cur = 1;
                else cur = (1ll << (len - i - 1ll));
                long long z = min(bb / cur, m - 1ll);
                bb -= cur * (z);
                ans[i] += z;
            }
            if (bb == 0) {
                t = true;
                cout << len << " ";
                for (int i = 2; i <= len; ++i)
                    for (int j = i - 1; j > 0; --j)
                        ans[i] += ans[j];
                for (int i = 1; i <= len; ++i)
                    cout << ans[i] << " ";
                cout << '\n';
                break;
            }
        }
        if (!t) {
            cout << "-1\n";
            continue;
        }
    }
}