/**
 *  created: 24/05/2021, 19:14:39
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, mod = 998244353;

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

inline int mul(int x, int y) {
    return (1LL * x * y) % mod;
}

int power(int a, int b) {
    int res = 1 % mod;
    while (b) {
        if (b % 2) {
            res = mul(res, a);
        }
        b /= 2;
        a = mul(a, a);
    }
    return res;
}

int inv(int x) {
    return power(x, mod - 2);
}

const int r2 = inv(2);
const int r6 = inv(6);

int dp[max_n], sdp[max_n], s2dp[max_n];

int c2(int x) {
    return mul(x, mul(x + 1, r2));
}

int c3(int x) {
    return mul(x, mul(x + 1, mul(x + 2, r6)));
}

int calc_ans2(int h) {
    int res = c2(dp[h - 1]);
    if (h >= 2) {
        inc(res, mul(dp[h - 1], sdp[h - 2]));
    }
    return res;
}

int calc_ans(int h) {
    int res = dp[h - 1];

    inc(res, c2(dp[h - 1]));
    if (h >= 2) {
        inc(res, mul(dp[h - 1], sdp[h - 2]));
    }

    inc(res, c3(dp[h - 1]));
    if (h >= 2) {
        inc(res, mul(c2(dp[h - 1]), sdp[h - 2]));
        inc(res, mul(dp[h - 1], s2dp[h - 2]));
    }
    return res;
}

int calc_dp(int h) {
    int res = dp[h - 1];

    inc(res, c2(dp[h - 1]));
    if (h >= 2) {
        inc(res, mul(dp[h - 1], sdp[h - 2]));
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    dp[0] = sdp[0] = 1;
    s2dp[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        dp[i] = calc_dp(i);

        sdp[i] = sdp[i - 1];
        inc(sdp[i], dp[i]);

        s2dp[i] = s2dp[i - 1];
        inc(s2dp[i], mul(dp[i], sdp[i - 1]));
        inc(s2dp[i], c2(dp[i]));
        if (abs(calc_ans(i) - 272040628) <= 10000) {
            //cout << i << ": " << calc_ans(i) << "    " << abs(calc_ans(i) - 272040628) << endl;
        }
        //cout << i << ": " << dp[i] << " " << calc_ans(i) << "   s2 = " << s2dp[i] << endl;
    }
    int n;
    cin >> n;
    int ans = mul(calc_ans(n), 2);
    inc(ans, mod - 1);
    int tot = 0;
    for (int a = 1; a < n; ++a) {
        inc(tot, calc_ans2(a));
    }
    for (int a = 1; a < n; ++a) {
        dec(tot, calc_ans2(n - a));
        inc(ans, mul(calc_ans2(a), tot));
    }
    cout << ans << endl;
    return 0;
}