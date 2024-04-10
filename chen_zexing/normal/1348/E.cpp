#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;
int a[505],b[505];
long long dp[505][505];
int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < k; j++)
            dp[i][j] = -1;
    dp[0][0] = 0;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            if (dp[i - 1][j] == -1) continue;
            dp[i][(j + a[i]) % k] = dp[i - 1][j] + (j + a[i]) / k + (sum - j - dp[i - 1][j] * k + b[i]) / k;
            //cout<<dp[i-1][j]<<" "<<(j+a[i])/k<<" "<<(sum-j-dp[i-1][j]*k+b[i])/k<<dp[i][(j+a[i])%k]<<endl;
            for (int t = max(0, k - b[i]); t <= min(a[i], k); t++) {
                dp[i][(j + a[i] - t) % k] = max(dp[i][(j + a[i] - t) % k], dp[i - 1][j] + 1 + (j + a[i] - t) / k +
                                                                           (sum - j - dp[i - 1][j] * k + b[i] -
                                                                            (k - t)) / k);
                //cout<<dp[i][(j+a[i]-t)%k]<<endl;
            }
        }
        sum += a[i] + b[i];
    }
    long long ans = 0;
    for (int i = 0; i < k; i++) ans = max(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}