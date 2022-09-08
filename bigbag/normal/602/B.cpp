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

int n, last, x, cnt, dp[max_n][2];
vector<int> a, b;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    last = -1;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (last == x) {
            ++cnt;
        } else {
            a.push_back(last);
            b.push_back(cnt);
            cnt = 1;
            last = x;
        }
    }
    a.push_back(last);
    b.push_back(cnt);
    n = a.size();
    dp[n - 1][0] = dp[n - 1][1] = b[n - 1];
    int ans = b[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        dp[i][0] = b[i];
        if (a[i] == a[i + 1] + 1) {
            dp[i][0] += dp[i + 1][1];
        }
        dp[i][1] = b[i];
        if (a[i] + 1 == a[i + 1]) {
            dp[i][1] += dp[i + 1][0];
        }
        ans = max(ans, dp[i][0]);
        ans = max(ans, dp[i][1]);
    }
    cout << ans << endl;
    return 0;
}