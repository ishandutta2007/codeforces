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

const int max_n = 505, inf = 1111111111;

int n, m, b, mod, a[max_n], dp[2][max_n][max_n];
vector<pair<int, int> > v;

int main() {
    //freopen("output.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> b >> mod;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    dp[0][0][0] = 1;
    int q1 = 0, q2 = 0;
    for (int i = 0; i < n; ++i) {
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y + a[i] <= b; ++y) {
                if (dp[q1][x][y] == 0) {
                    continue;
                }
                dp[q1][x + 1][y + a[i]] = (dp[q1][x + 1][y + a[i]] + dp[q1][x][y]) % mod;
            }
        }
        swap(q1, q2);
    }
    int ans = 0;
    for (int y = 0; y <= b; ++y) {
        ans = (ans + dp[q1][m][y]) % mod;
    }
    cout << ans << endl;
    return 0;
}