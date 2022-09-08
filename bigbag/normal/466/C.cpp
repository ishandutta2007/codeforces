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

const int max_n = 555555, inf = 1111111111;

long long n, a[max_n], sum[max_n], dp[max_n];

long long get_sum(int l, int r) {
    if (l == 0) {
        return sum[r];
    }
    return sum[r] - sum[l - 1];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", &a[i]);
        sum[i] = a[i];
        if (i > 0) {
            sum[i] += sum[i - 1];
        }
    }
    if (sum[n - 1] % 3) {
        printf("0\n");
        return 0;
    }
    long long x = sum[n - 1] / 3, ans = 0;
    dp[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
        dp[i] = dp[i + 1];
        if (get_sum(i, n - 1) == x) {
            ++dp[i];
        }
    }
    for (int i = 0; i + 2 < n; ++i) {
        if (sum[i] == x) {
            //cout << i << " " << dp[i  + 2] << endl;
            ans += dp[i + 2];
        }
    }
    cout << ans << endl;
    return 0;
}