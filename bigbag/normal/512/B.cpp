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

const int max_n = 333, mx = 1000000, inf = 1000000000;

int n, dp[mx], a[max_n], b[max_n];
map<int, int> dp2;

int gcd(int a, int b) {
    while (a != 0 && b != 0) {
        int k = a;
        a = b;
        b = k % b;
    }
    return a + b;
}

int get_dp(int x) {
    if (x == 1) {
        return 0;
    }
    if (x < mx) {
        if (dp[x]) {
            return dp[x];
            dp[x] = 1;
        }
    } else {
        if (dp2.count(x)) {
            return dp2[x];
        }
    }
    int res = inf;
    for (int i = 0; i < n; ++i) {
        if (res > b[i]) {
            int g = gcd(x, a[i]);
            if (g < x) res = min(res, b[i] + get_dp(g));
        }
    }
    if (x < mx) {
        dp[x] = res;
    } else {
        dp2[x] = res;
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    int g;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i == 0) {
            g = a[0];
        } else {
            g = gcd(a[i], g);
        }
    }
    if (g > 1) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    int ans = inf;
    for (int i = 0; i < n; ++i) {
        if (ans > b[i]) {
            ans = min(ans, get_dp(a[i]) + b[i]);
        }
    }
    cout << ans << endl;
    return 0;
}