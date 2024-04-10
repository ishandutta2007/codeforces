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
int dp[505][505];

void upd(int &x, int y) {
    if (y < x) x = y;
    return;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> s;
    string ss = "";
    for (int i = 0; i < n; ++i)
        if (!i || s[i] != s[i - 1]) ss += s[i];
    n = (int)ss.size();
    s = ss;
    s = "#" + s;
    for (int i = 1; i <= n; ++i) {
        dp[i][i] = 1;
    }
    for (int len = 2; len <= n; ++len) {
        for (int j = len; j <= n; ++j) {
            int i = j - len + 1;
            dp[i][j] = 1e9;
            for (int k = i; k < j; ++k) {
                upd(dp[i][j], dp[i][k] + dp[k + 1][j]);
                if (s[i] == s[k + 1] || s[i] == s[j] || s[k] == s[k + 1] || s[k] == s[j])
                    upd(dp[i][j], dp[i][k] + dp[k + 1][j] - 1);
            }
        }
    }
    cout << dp[1][n] << '\n';
}