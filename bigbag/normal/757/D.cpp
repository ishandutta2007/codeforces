#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 77, max_x = 20, mod = 1000000007;

int n, nxt[max_n], dp[max_n][1 << max_x];
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> s;
    nxt[n] = n;
    for (int i = n - 1; i >= 0; --i) {
        nxt[i] = nxt[i + 1];
        if (s[i] == '1') {
            nxt[i] = i;
        }
    }
    for (int i = 0; i < n; ++i) {
        dp[i][0] = 1;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int mask = 0; mask < (1 << max_x); ++mask) {
            int pos = nxt[i];
            int x = 0;
            while (pos < n) {
                x *= 2;
                x += s[pos] - '0';
                if (x > max_x) {
                    break;
                }
                int nmask = mask | (1 << (x - 1));
                ++pos;
                dp[pos][nmask] += dp[i][mask];
                dp[pos][nmask] %= mod;
            }
        }
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 1; j <= max_x; ++j) {
            int mask = (1 << j) - 1;
            ans += dp[i][mask];
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}