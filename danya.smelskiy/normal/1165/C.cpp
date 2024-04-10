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
string s;
pair<bool, int> dp[200005][26][2];
pair<int, int> pred[200005][26][2];


int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> s;
    s = "#" + s;
    for (int i = 1; i <= n; ++i) {
        int x = s[i] - 'a';
        for (int j = 0; j < 26; ++j) {
            for (int k = 0; k < 2; ++k) if (dp[i - 1][j][k].first) {
                if (dp[i][j][k].first == false || dp[i][j][k].second < dp[i - 1][j][k].second) {
                    dp[i][j][k] = make_pair(true, dp[i - 1][j][k].second);
                    pred[i][j][k] = make_pair(j, k);
                }
                if (k == 1 && j == x) continue;
                if (dp[i][x][1 - k].first == false || dp[i][x][1 - k].second < dp[i - 1][j][k].second + 1) {
                    dp[i][x][1 - k] = make_pair(true, dp[i - 1][j][k].second + 1);
                    pred[i][x][1 - k] = make_pair(j, k);
                }
            }
        }
        if (dp[i][x][1].first == false || dp[i][x][1].second < 1) {
            dp[i][x][1] = make_pair(true, 1);
            pred[i][x][1] = make_pair(-1, -1);
        }
    }
    int x = -1, y = 0;
    int res = 0;
    for (int i = 0; i < 26; ++i) {
        if (dp[n][i][0].first && dp[n][i][0].second > res) {
            res = dp[n][i][0].second;
            x = i;
            y = 0;
        }
    }
    cout << n - res << '\n';
    string ans = "";
    for (int i = n; i > 0 && x != -1; --i) {
        int xx = pred[i][x][y].first;
        int yy = pred[i][x][y].second;
        if (yy != y) ans += char(x + 'a');
        x = xx;
        y = yy;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
    return 0;
}