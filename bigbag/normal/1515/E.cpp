/**
 *  created: 02/05/2021, 18:16:06
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 444;
int mod;

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

string str_fraq(int x, int n = 20) {
    stringstream res;
    pair<int, int> best(x, 1);
    for (int j = 1; j < n; ++j) {
        best = min(best, {mul(x, j), j});
    }
    res << best.first << "/" << best.second;
    return res.str();
}

const int max_f = max_n;

int f[max_f], rf[max_f];

void get_all_f() {
    f[0] = rf[0] = 1;
    for (int i = 1; i < max_f; ++i) {
        f[i] = mul(i, f[i - 1]);
    }
    rf[max_f - 1] = inv(f[max_f - 1]);
    for (int i = max_f - 2; i > 0; --i) {
        rf[i] = mul(i + 1, rf[i + 1]);
    }
}

int get_c(int n, int k) {
    if (n < k) {
        return 0;
    }
    return mul(f[n], mul(rf[k], rf[n - k]));
}

int n, dp[max_n][max_n], ways[max_n];

int get_dp(int len, int ops) {
    if (len == -1) {
        if (!ops) {
            return 1;
        }
        return 0;
    }
    assert(len >= 0 && ops >= 0);
    return dp[len][ops];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> mod;
    get_all_f();
    for (int len = 1; len <= n; ++len) {
        for (int start = 0; start < len; ++start) {
            inc(ways[len], get_c(len - 1, start));
        }
    }
    for (int len = 1; len <= n; ++len) {
        //cout << len << ": ";
        for (int ops = 1; ops <= len; ++ops) {
            for (int i = 1; i <= ops; ++i) {
                int add = mul(get_dp(len - i - 1, ops - i), get_c(ops, i));
                add = mul(add, ways[i]);
                inc(dp[len][ops], add);
            }
            //cout << dp[len][ops] << " ";
        }
        //cout << endl;
    }
    cout << accumulate(dp[n], dp[n] + n + 1, 0LL) % mod << endl;
    return 0;
}