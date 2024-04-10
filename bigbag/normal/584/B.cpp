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

const int max_n = 111111, inf = 1000000007;

int n, dp[max_n][2];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    dp[1][0] = 7;
    dp[1][1] = 20;
    for (int i = 2; i <= n; ++i) {
        dp[i][0] = (1LL * dp[i - 1][0] * 7) % inf;
        dp[i][1] = ((1LL * dp[i - 1][0] * 20) % inf + (1LL * dp[i - 1][1] * 27) % inf) % inf;
    }
    cout << dp[n][1] << endl;
    return 0;
}