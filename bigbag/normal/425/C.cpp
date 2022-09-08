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

const int max_n = 111111, inf = 1111111111;

int n, m, s, e, a[max_n], b[max_n], dp[max_n][333];
vector<int> v[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> s >> e;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        v[b[i]].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        dp[i][0] = -1;
        for (int j = 1; j <= s / e; ++j) {
            dp[i][j] = inf;
        }
    }
    for (int i = 0; i < m; ++i) {
        if (b[i] == a[0]) {
            dp[0][1] = i;
            break;
        }
    }
    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j <= s / e; ++j) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            vector<int>::iterator it = upper_bound(v[a[i + 1]].begin(), v[a[i + 1]].end(), dp[i][j]);
            if (it != v[a[i + 1]].end()) {
                int poz = *it;
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], poz);
            }
        }
    }
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= s / e; ++j) {
            int cost = i + dp[i][j] + 2 + e * j;
            if (cost <= s) {
                ans = max(ans, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}