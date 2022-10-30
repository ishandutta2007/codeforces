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



long long ans;
string s[100005], ss[100005];
long long dp[100005][4];
int l[100005];
int n;
bool f[100005];

void solve(int cc) {
    for (int i = 1; i <= n; ++i) {
        ss[i] = s[i];
        for (int j = 0; j < l[i]; ++j)
            if (ss[i][j] - 'a' == cc) ss[i][j] = 'a';
            else ss[i][j] = 'b';
        long long c1 = 0, c2 = 0, c3 = 0;
        long long last = 0;
        for (int j = 0; j < l[i]; ++j) if (ss[i][j] != 'a') break;
        else ++c1;
        for (int j = l[i] - 1; j >= 0; --j)
            if (ss[i][j] != 'a') break;
            else ++c2;
        for (int j = 0; j < l[i]; ++j) {
            if (ss[i][j] == 'a') ++last;
            else last = 0;
            c3 = max(c3, last);
        }
        dp[i][0] = c1;
        dp[i][1] = c2;
        dp[i][2] = c3;
        f[i] = (c1 == l[i] ? true : false);
        if (i == 1) continue;
        long long cur = c3;
        if (dp[i - 1][2]) cur = max(cur, c1 + c2 + 1ll);
        if (f[i]) {
            long long cur2 = dp[i - 1][2] + 1ll;
            long long cur3 = dp[i - 1][2];
            cur3 += cur2 * l[i];
            cur = max(cur, cur3);
        }
        dp[i][2] = cur;
        f[i] &= f[i - 1];
    }
    ans = max(ans, dp[n][2]);
    return;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        l[i] = (int)s[i].size();
    }
    for (int i = 0; i < 26; ++i)
        solve(i);
    cout << ans << '\n';
}