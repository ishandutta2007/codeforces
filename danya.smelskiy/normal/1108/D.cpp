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
int dp[200005][4];
int pred[200005][4];
int cur;

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> s;
    s = "#" + s;
    for (int i = 1; i <= n; ++i) {
        int x = 0;
        if (s[i] == 'G') x = 1;
        else if (s[i] == 'B') x = 2;
        for (int j = 0; j < 3; ++j) {
            dp[i][j] = 1e9;
            for (int k = 0; k < 3; ++k) if (k != j) {
                cur = dp[i - 1][k];
                if (j != x) ++cur;
                if (cur < dp[i][j]) {
                    dp[i][j] = cur;
                    pred[i][j] = k;
                }
            }
        }
    }
    int pos = 0, res = 1e9;
    for (int i = 0; i < 3; ++i)
        if (dp[n][i] < res) {
            res = dp[n][i];
            pos = i;
        }
    cout << res << '\n';
    string ss = "";
    for (int i = n; i > 0; --i) {
        int x = pred[i][pos];
        if (pos == 0) ss += "R";
        else if (pos == 1) ss += "G";
        else ss += "B";
        pos = x;
    }
    reverse(ss.begin(), ss.end());
    cout << ss << '\n';
    return 0;
}