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

const int max_n = 1111111;
const long long inf = 1111111111111111111LL;

int n, c1, c2, a[max_n];
long long ans = inf, dp[max_n][3];

long long cost(int a, int x) {
    if (a % x == 0) {
        return 0;
    }
    if ((a - 1) % x == 0 || (a + 1) % x == 0) {
        return c2;
    }
    return inf;
}

void check(int x) {
    //cout << x << endl;
    for (int qqq = 0; qqq < 2; ++qqq) {
        dp[0][0] = cost(a[0], x);
        dp[0][1] = inf;
        dp[0][2] = inf;
        for (int i = 1; i < n; ++i) {
            dp[i][0] = min(inf, dp[i - 1][0] + cost(a[i], x));
            dp[i][1] = min(inf, min(dp[i - 1][0] + c1, dp[i - 1][1] + c1));
            dp[i][2] = min(inf, min(dp[i - 1][2] + cost(a[i], x), dp[i][1]));
            //cout << i << " : " << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
        }
        ans = min(ans, dp[n - 1][0]);
        ans = min(ans, dp[n - 1][2]);
        reverse(a, a + n);
    }
}

void proc(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            while (x % i == 0) {
                x /= i;
            }
            check(i);
        }
    }
    if (x > 1) {
        check(x);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &c1, &c2);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    proc(a[0]);
    proc(a[0] - 1);
    proc(a[0] + 1);
    proc(a[n - 1]);
    proc(a[n - 1] - 1);
    proc(a[n - 1] + 1);
    cout << ans << endl;
    return 0;
}