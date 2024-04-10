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

const int max_n = 555, inf = 1000000007;

int n, a[max_n], dp[max_n][max_n];

int get_dp(int l, int r) {
    if (l > r) {
        return 1;
    }
    if (l == r) {
        return 1;
    }
    if (dp[l][r]) {
        return dp[l][r];
    }
    dp[l][r] = get_dp(l + 1, r);
    for (int i = l + 1; i <= r; ++i) {
        if (a[l] < a[i]) {
            dp[l][r] += (1LL * get_dp(i, r) * get_dp(l + 1, i - 1)) % inf;
            dp[l][r] %= inf;
        }
    }
    return dp[l][r];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << get_dp(1, n - 1) << endl;
    return 0;
}