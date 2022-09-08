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

const int max_n = 1011, mod = 1000000007;

int t, k;
long long pw[max_n], pw2[max_n];
int dp[max_n], sumdp[max_n], sums[max_n][max_n];
char ll[max_n], rr[max_n];
string l, r;

int sum_dp(int r) {
    return sumdp[r];
}

long long sum(int st, int cnt) {
    if (cnt < 0 || st < 0) {
        return 0;
    }
    return sums[st][cnt];
}

void get_all_sum() {
    for (int st = 0; st < max_n; ++st) {
        sums[st][1] = (2 * pw[st] * pw2[0]) % mod;
        for (int cnt = 2; cnt <= st + 1; ++cnt) {
            sums[st][cnt] = (sums[st][cnt - 1] + 2 * pw[st - cnt + 1] * pw2[cnt - 1]) % mod;
        }
    }
}

void get_dp() {
    pw[0] = 1;
    pw2[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        pw[i] = (pw[i - 1] * 10) % mod;
        pw2[i] = (pw2[i - 1] * 8) % mod;
    }
    dp[0] = dp[1] = 0;
    get_all_sum();
    for (int len = 2; len < max_n; ++len) {
        for (int i = 1; i <= len; ++i) {
            long long x = 1;
            int poz = i - k;
            if (poz > 1) {
                x = (x * pw2[k]) % mod;
                long long y = ((9 * pw[poz - 2] - dp[poz - 1]/*sum_dp(poz - 1)*/) % mod + mod) % mod;
                x = (x * y) % mod;
            } else {
                if (i != 1) {
                    x = (x * pw2[i - 2] * 7) % mod;
                }
            }
            dp[len] = (dp[len] + (2 * x * sum(len - i - 1, min(len, k + i) - i)) % mod) % mod;
        }
        sumdp[len] = (sumdp[len - 1] + dp[len]) % mod;
    }
}

bool ok(string s) {
    int last = -11111;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '4' || s[i] == '7') {
            if (i - last <= k) {
                return true;
            }
            last = i;
        }
    }
    return false;
}

bool happy(int x) {
    return x == 4 || x == 7;
}

long long fun(string r) {
    int res = sumdp[r.length() - 1];
    int last = -111111;
    for (int i = 0; i < r.length(); ++i) {
        int st = 0, fin = r[i] - '0';
        if (i == 0) {
            st = 1;
        }
        for (int j = st; j < fin; ++j) {
            if (happy(j)) {
                if (i - last <= k) {
                    res = (res + pw[r.length() - i - 1]) % mod;
                } else {
                    res = (res + sum(r.length() - i - 2, min((int) r.length() - 1, i + k) - i)) % mod;
                    int poz = i + k + 1;
                    if (poz < r.length()) {
                        long long x = (pw2[k] * sum_dp(r.length() - poz)) % mod;
                        res = (res + x) % mod;
                    }
                }
            } else {
                if (last < 0) {
                    res = (res + sum_dp(r.length() - i - 1)) % mod;
                } else {
                    res = (res + sum(r.length() - i - 2, min((int) r.length() - 1, k + last) - i)) % mod;
                    int poz = max(i + 1, last + k + 1);
                    if (poz < r.length()) {
                        long long x = (pw2[poz - i - 1] * sum_dp(r.length() - poz)) % mod;
                        res = (res + x) % mod;
                    }
                }
            }
        }
        if (happy(fin)) {
            if (i - last <= k) {
                res = (res + 1) % mod;
                long long x = 0;
                for (int j = i + 1; j < r.length(); ++j) {
                    x = (x * 10 + r[j] - '0') % mod;
                }
                res = (res + x) % mod;
                return res;
            }
            last = i;
        }
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t >> k;
    get_dp();
    while (t--) {
        scanf("%s%s", ll, rr);
        l = ll;
        r = rr;
        long long x = fun(r);
        long long y = fun(l);
        long long ans = ((x - y) % mod + mod) % mod;
        if (ok(l)) {
            ans = (ans + 1) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}