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

const int max_n = 4044, max_x = 68, inf = 1111111111;

int n, a[max_n], sum[max_n];
int dp[2][max_n][100][max_x];
char f[2][max_n][100][max_x];

int get_sum(int l, int r) {
    if (l == 0) {
        return sum[r];
    }
    return sum[r] - sum[l - 1];
}

int Q = 0;

int get_dp(int tp, int l, int last, int cnt2) {
    if (f[tp][l][last][cnt2]) {
        return dp[tp][l][last][cnt2];
    }
    f[tp][l][last][cnt2] = 1;
    //if (tp == 0 && l == 2 && last == 3 && cnt2 == 1) {
    if (tp == 0) {
        Q = max(Q, last);
        int len2 = l + cnt2;
        int k = last;
        int r = n - len2 - 1;
        if (last == 64) {
            //cout << l << " " << r << endl;
        }
        if (r - l + 1 < k) {
            dp[tp][l][last][cnt2] = 0;
        } else {
            dp[tp][l][last][cnt2] = get_sum(l, l + k - 1) + get_dp(1, l + k, k, cnt2);
            if (r - l + 1 >= k + 1) {
                dp[tp][l][last][cnt2] = max(dp[tp][l][last][cnt2], get_sum(l, l + k) + get_dp(1, l + k + 1, k + 1, cnt2));
            }
        }
    } else {
        int len2 = l + cnt2 - last;
        int k = last;
        int r = n - len2 - 1;
        if (r - l + 1 < k) {
            dp[tp][l][last][cnt2] = 0;
        } else {
            dp[tp][l][last][cnt2] = -get_sum(r - k + 1, r) + get_dp(0, l, k, cnt2);
            if (r - l + 1 >= k + 1) {
                dp[tp][l][last][cnt2] = min(dp[tp][l][last][cnt2], -get_sum(r - k, r) + get_dp(0, l, k + 1, cnt2 + 1));
            }
        }
    }
    return dp[tp][l][last][cnt2];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum[i] = a[i];
    }
    for (int i = 1; i < n; ++i) {
        sum[i] += sum[i - 1];
    }
    printf("%d\n", get_dp(0, 0, 1, 0));
    //cout << Q << endl;
    return 0;
}