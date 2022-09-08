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

const int max_n = 55, max_l = 5555, max_m = 250052;
long long inf = 111111111111111111LL;

int n, m, cnt[max_n], a[max_n][max_l], pozs[max_m];
long long sum[max_n], sum1[max_n], sum2[max_n], dp[max_m], sums[max_n][max_l], max_sum[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    long long ans = -inf;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &cnt[i]);
        sum1[i] = -inf;
        sum2[i] = -inf;
        sum[i] = 0;
        sums[i][cnt[i]] = 0;
        long long mins = 0;
        max_sum[i] = -inf;
        //cout << i << " : " << endl;
        for (int j = 0; j < cnt[i]; ++j) {
            scanf("%d", &a[i][j]);
            sum[i] += a[i][j];
        }
        long long x = 0;
        for (int j = 0; j < cnt[i]; ++j) {
            x += a[i][j];
            sum1[i] = max(sum1[i], x);
        }
        x = 0;
        for (int j = cnt[i] - 1; j >= 0; --j) {
            x += a[i][j];
            sum2[i] = max(sum2[i], x);
            sums[i][j] = a[i][j] + sums[i][j + 1];
            max_sum[i] = max(max_sum[i], sums[i][j] - mins);
            //cout  << max_sum[i]  << endl;
            mins = min(mins, sums[i][j]);
        }
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &pozs[i]);
        --pozs[i];
    }
    dp[m] = 0;
    dp[m - 1] = sum1[pozs[m - 1]];
    for (int i = m - 2; i >= 0; --i) {
        dp[i] = max(sum1[pozs[i]], dp[i + 1] + sum[pozs[i]]);
    }

    /*for (int i = 0; i < n; ++i) {
        cout << i << " : " << sum[i] << ' ' << sum1[i] << ' ' << sum2[i] << endl;
    }
    for (int i = 0; i < m; ++i) {
        cout << dp[i] << ' ';
    }
    cout << endl;*/

    for (int i = 0; i < m; ++i) {
        ans = max(ans, max_sum[pozs[i]]);
        ans = max(ans, sum1[pozs[i]]);
        ans = max(ans, sum2[pozs[i]]);
        ans = max(ans, sum2[pozs[i]] + dp[i + 1]);
    }
    cout << ans << endl;
    return 0;
}