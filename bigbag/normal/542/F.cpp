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

const int max_n = 1111, max_t = 111;

int n, m, f[max_t][max_n], dp[max_t][max_n];
vector<int> a[max_n];

int get_dp(int lev, int cnt) {
    if (cnt == 0) {
        return 0;
    }
    if (lev == m) {
        return 0;
    }
    if (f[lev][cnt] == 1) {
        return dp[lev][cnt];
    }
    f[lev][cnt] = 1;
    for (int i = 0; i <= cnt && i < a[lev].size(); ++i) {
        dp[lev][cnt] = max(dp[lev][cnt], a[lev][i] + get_dp(lev + 1, min(n, 2 * (cnt - i))));
    }
    return dp[lev][cnt];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int t, q;
        cin >> t >> q;
        a[m - t].push_back(q);
    }
    for (int i = 0; i < m; ++i) {
        sort(a[i].begin(), a[i].end());
        a[i].push_back(0);
        reverse(a[i].begin(), a[i].end());
        for (int j = 1; j < a[i].size(); ++j) {
            a[i][j] += a[i][j - 1];
        }
    }
    cout << get_dp(0, 1) << endl;
    return 0;
}