#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, sum, dp[max_n], last[3];
char a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%s", a + 1);
    n = strlen(a + 1);
    memset(last, -1, sizeof(last));
    last[0] = 0;
    for (int i = 1; i <= n; ++i) {
        if (i) {
            dp[i] = dp[i - 1];
        }
        sum += a[i] - '0';
        sum %= 3;
        if (last[sum] != -1) {
            dp[i] = max(dp[i], dp[last[sum]] + 1);
        }
        last[sum] = i;
    }
    printf("%d\n", dp[n]);
    return 0;
}