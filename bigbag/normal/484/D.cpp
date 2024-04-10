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

const int max_n = 1111111, inf = 1111111111;

long long n, ans, last_p, a[max_n], dp[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", &a[i]);
    }
    last_p = 0;
    dp[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] > a[i - 1]) {
            if (last_p == 0) {
                dp[i] = a[i] - a[0];
            } else {
                dp[i] = max(dp[last_p] + a[i] - a[last_p + 1], dp[last_p - 1] + a[i] - a[last_p]);
            }
        } else {
            if (last_p == 0) {
                dp[i] = a[0] - a[i];
            } else {
                dp[i] = max(dp[last_p] + a[last_p + 1] - a[i], dp[last_p - 1] + a[last_p] - a[i]);
            }
        }
        //cout << i << " " << dp[i] << "   " << last_p << endl;
        if ((a[i - 1] >= a[i] && a[i] <= a[i + 1]) || (a[i - 1] <= a[i] && a[i] >= a[i + 1])) {
            last_p = i;
        }
    }
    cout << dp[n - 1] << endl;
    return 0;
}