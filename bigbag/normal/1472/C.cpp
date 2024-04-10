/**
 *  created: 04/01/2021, 16:39:58
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, a[max_n], dp[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = a[i];
            if (i + a[i] < n) {
                dp[i] += dp[i + a[i]];
            }
        }
        printf("%d\n", *max_element(dp, dp + n));
    }
    return 0;
}