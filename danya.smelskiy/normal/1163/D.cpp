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


string s1, a, b;
int l1, l2;
int n;
int dp1[105][105], dp2[105][105];
pair<bool, int> dp[1005][51][51];

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s1 >> a >> b;
    l1 = (int)a.size();
    l2 = (int)b.size();
    a = "#" + a;
    b = "#" + b;
    for (int i = 0; i <= l1; ++i) {
        for (int j = 0; j < 26; ++j) {
            string s = "";
            for (int k = 1; k <= i; ++k)
                s += a[k];
            s += char(j + 'a');
            int cur = 0;
            for (int k = i + 1; k > 0; --k) {
                string ss1 = "";
                for (int z = k; z <= i + 1; ++z)
                    ss1 += s[z - 1];
                string ss2 = "";
                for (int z = 1; z <= i + 1 - k + 1; ++z)
                    ss2 += a[z];
                if (ss1 == ss2) {
                    cur = i + 1 - k + 1;
                }
            }
            dp1[i][j] = cur;
        }
    }
    for (int i = 0; i <= l2; ++i) {
        for (int j = 0; j < 26; ++j) {
            string s = "";
            for (int k = 1; k <= i; ++k)
                s += b[k];
            s += char(j + 'a');
            int cur = 0;
            for (int k = i + 1; k > 0; --k) {
                string ss1 = "";
                for (int z = k; z <= i + 1; ++z)
                    ss1 += s[z - 1];
                string ss2 = "";
                for (int z = 1; z <= i + 1 - k + 1; ++z)
                    ss2 += b[z];
                if (ss1 == ss2) {
                    cur = i + 1 - k + 1;
                }
            }
            dp2[i][j] = cur;
        }
    }
    dp[0][0][0] = make_pair(true, 0);
    n = (int)s1.size();
    s1 = "#" + s1;
    int x, jj, kk, cur;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= l1; ++j) {
            for (int k = 0; k <= l2; ++k) if (dp[i][j][k].first) {
                if (s1[i + 1] != '*') {
                    x = s1[i + 1] - 'a';
                    jj = dp1[j][x];
                    kk = dp2[k][x];
                    cur = dp[i][j][k].second;
                    if (jj == l1) ++cur;
                    if (kk == l2) --cur;
                    if (!dp[i + 1][jj][kk].first || dp[i + 1][jj][kk].second < cur) {
                        dp[i + 1][jj][kk] = make_pair(true, cur);
                    }
                } else {
                    for (int z = 0; z < 26; ++z) {
                        jj = dp1[j][z];
                        kk = dp2[k][z];
                        cur = dp[i][j][k].second;
                        if (jj == l1) ++cur;
                        if (kk == l2) --cur;
                        if (!dp[i + 1][jj][kk].first || dp[i + 1][jj][kk].second < cur) {
                            dp[i + 1][jj][kk] = make_pair(true, cur);
                        }
                    }
                }
            }
        }
    }
    int ans = -1e9;
    for (int i = 0; i <= l1; ++i)
        for (int j = 0; j <= l2; ++j)
            if (dp[n][i][j].first) ans = max(ans, dp[n][i][j].second);
    cout << ans << '\n';
    return 0;
}