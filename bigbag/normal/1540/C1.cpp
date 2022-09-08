/**
 *  created: 25/06/2021, 19:44:15
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, mod = 1000000007;

inline void inc(int &x, int y) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
}

inline void dec(int &x, int y) {
    x -= y;
    if (x < 0) {
        x += mod;
    }
}

int n, c[max_n], a[max_n], b[max_n], Q, x, ans;

const int max_sum = max_n * max_n;

int dp[2][max_sum];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i + 1 < n; ++i) {
        cin >> b[i];
    }
    cin >> Q >> x;
    int q1 = 0, q2 = 1, sb = 0, mn = 0;
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        memset(dp[q2], 0, sizeof(dp[q2]));
        int tot = 0, from = 0;
        mn += x + sb;
        sb += b[i];
        for (int sum = 0; sum < max_sum; ++sum) {
            inc(tot, dp[q1][sum]);
            while (from + c[i] < sum) {
                dec(tot, dp[q1][from++]);
            }
            dp[q2][sum] = tot;
            if (sum < mn) {
                dp[q2][sum] = 0;
            }
        }
        swap(q1, q2);
    }
    int res = accumulate(dp[q1], dp[q1] + max_sum, 0LL) % mod;
    cout << res << endl;
    return 0;
    /*while (true) {
        for (int i = 0; i + 1 < n; ++i) {
            cout << a[i + 1] - a[i] << " ";
        }
        cout << endl;
        bool ok = 1;
        for (int i = 0; i + 1 < n; ++i) {
            double d = a[i + 1] - a[i];
            if (b[i] > d) {
                ok = 0;
                double c = (b[i] - d) / 2;
                a[i] -= c;
                a[i + 1] += c;
                break;
            }
        }
        if (ok) {
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }*/
    return 0;
}