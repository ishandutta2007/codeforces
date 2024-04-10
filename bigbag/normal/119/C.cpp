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

const int max_n = 111;

int n, m, k, p1[max_n][max_n][max_n], p2[max_n][max_n][max_n];
long long a[max_n], b[max_n], c[max_n], dp[max_n][max_n][max_n];
vector<pair<int, long long> > ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    memset(dp, -1, sizeof(dp));
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        for (long long x = a[i]; x <= b[i]; ++x) {
            dp[0][i][x - a[i]] = max(dp[0][i][x - a[i]], x);
        }
    }
    for (int i = 0; i + 1 < n; ++i) {
        for (int num = 0; num < m; ++num) {
            for (long long x = a[num]; x <= b[num]; ++x) {
                long long Q = dp[i][num][x - a[num]];
                if (Q == -1) {
                    continue;
                }
                //cout << i << " : " << num << " " << x << endl;
                for (int num2 = 0; num2 < m; ++num2) {
                    if (c[num] < c[num2]) {
                        long long y = x * k;
                        if (a[num2] <= y && y <= b[num2]) {
                            if (dp[i + 1][num2][y - a[num2]] < Q + y) {
                                dp[i + 1][num2][y - a[num2]] = Q + y;
                                p1[i + 1][num2][y - a[num2]] = num;
                                p2[i + 1][num2][y - a[num2]] = x - a[num];
                            }
                        }
                        y = x + k;
                        if (a[num2] <= y && y <= b[num2]) {
                            if (dp[i + 1][num2][y - a[num2]] < Q + y) {
                                dp[i + 1][num2][y - a[num2]] = Q + y;
                                p1[i + 1][num2][y - a[num2]] = num;
                                p2[i + 1][num2][y - a[num2]] = x - a[num];
                            }
                        }
                    }
                }
            }
        }
    }
    long long mx = -1, num = -1, cnt = -1;
    for (int i = 0; i < m; ++i) {
        for (long long x = a[i]; x <= b[i]; ++x) {
            if (mx < dp[n - 1][i][x - a[i]]) {
                mx = dp[n - 1][i][x - a[i]];
                num = i;
                cnt = x - a[i];
            }
        }
    }
    if (mx == -1) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for (int i = n - 1; i >= 0; --i) {
        ans.push_back(make_pair(num + 1, a[num] + cnt));
        if (i == 0) {
            break;
        }
        int num2 = p1[i][num][cnt];
        int cnt2 = p2[i][num][cnt];
        num = num2;
        cnt = cnt2;
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}