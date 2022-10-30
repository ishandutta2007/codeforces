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
pair<bool, long long> dp[200005][10];
int x, y;
vector<long long> q[100];
long long mx[1000];
int m;


int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    dp[0][0] = make_pair(true, 0);
    long long s1, s2, s3, cur;
    int c;
    long long z;
    for (int i = 1; i <= n; ++i) {
        cin >> m;
        for (int j = 1; j <= 3; ++j) {
            q[j].clear();
        }
        for (int j = 1; j <= m; ++j) {
            cin >> x >> y;
            q[x].push_back(y);
        }
        for (int j = 1; j <= 3; ++j) {
            sort(q[j].begin(), q[j].end());
            reverse(q[j].begin(), q[j].end());
        }
        mx[0] = mx[1] = mx[2] = mx[3] = 0;
        for (int j = 7; j <= 9; ++j) if (dp[i - 1][j].first) {
            s1 = 0;
            for (int i1 = 0; i1 <= (int)q[1].size(); ++i1) {
                s2 = 0;
                for (int j1 = 0; j1 <= (int)q[2].size() && i1 + 2 * j1 <= 3; ++j1) {
                    s3 = 0;
                    for (int k1 = 0; k1 <= (int)q[3].size() && i1 + 2 * j1 + 3 * k1 <= 3; ++k1) {
                        cur = s1 + s2 + s3;
                        c = i1 + j1 + k1;
                        cur += dp[i - 1][j].second;
                        if (j + c >= 10) {
                            z = 0;
                            if (i1) z = q[1][0];
                            if (j1) z = max(z, q[2][0]);
                            if (k1) z = max(z, q[3][0]);
                            cur +=z;
                        }
                        c += j;
                        if (c >= 10) c -= 10;
                        if (!dp[i][c].first || dp[i][c].second < cur) dp[i][c] = make_pair(true, cur);
                        if (k1 < (int)q[3].size()) s3 += q[3][k1];
                    }
                    if (j1 < (int)q[2].size()) s2 += q[2][j1];
                }
                if (i1 < (int)q[1].size()) s1 += q[1][i1];
            }
        }
        s1 = 0;
        for (int i1 = 0; i1 <= (int)q[1].size(); ++i1) {
            s2 = 0;
            for (int j1 = 0; j1 <= (int)q[2].size() && i1 + j1 + j1 <= 3; ++j1) {
                s3 = 0;
                for (int k1 = 0; k1 <= (int)q[3].size() && i1 + j1 + j1 + k1 + k1 + k1 <= 3; ++k1) {
                    cur = s1 + s2 + s3;
                    c = i1 + j1 + k1;
                    if (cur > mx[c]) mx[c] = cur;
                    if (k1 < (int)q[3].size()) {
                        s3 += q[3][0];
                    }
                }
                if (j1 < (int)q[2].size()) s2 += q[2][j1];
            }
            if (i1 < (int)q[1].size()) s1 += q[1][i1];
        }
        for (int j = 0; j < 7; ++j) if (dp[i - 1][j].first) {
            for (int k = 0; k <= 3; ++k) if (k == 0 || mx[k]) {
                cur = dp[i - 1][j].second + mx[k];
                if (!dp[i][j + k].first || dp[i][j + k].second < cur) {
                    dp[i][j + k] = make_pair(true, cur);
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < 10; ++i)
        if (dp[n][i].first) ans = max(ans, dp[n][i].second);
    cout << ans << '\n';
    return 0;
}