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

const int max_n = 111111, inf = 1111111111;

int n, m, q1, q2, all, a[max_n];
double dp[2][max_n], sum[max_n];

double get_sum(int l, int r) {
    if (l == 0) {
        return sum[r];
    }
    return sum[r] - sum[l - 1];
}

void get_sums() {
    sum[0] = dp[q1][0];
    for (int i = 1; i <= n * m; ++i) {
        sum[i] = sum[i - 1] + dp[q1][i];
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    if (m == 1) {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        all += a[i];
    }
    q1 = 0;
    q2 = 1;
    dp[q1][0] = m - 1;
    get_sums();
    for (int i = 0; i < n; ++i) {
        //cout << i << " : ";
        dp[q2][0] = 0;
        for (int j = 1; j <= n * m; ++j) {
            int l = max(0, j - m);
            int r = j - 1;
            dp[q2][j] = get_sum(l, r);
            if (l <= j - a[i] && j - a[i] <= r) {
                dp[q2][j] -= dp[q1][j - a[i]];
            }
            dp[q2][j] /= (m - 1);
            //printf("%.2f ", dp[q2][j]);
        }
        //cout << endl;
        swap(q1, q2);
        get_sums();
    }
    double ans = 0;
    for (int i = 0; i < all; ++i) {
        ans += dp[q1][i];
    }
    printf("%.10f\n", 1 + ans);
    return 0;
}