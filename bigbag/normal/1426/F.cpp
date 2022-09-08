#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, mod = 1000000007;

int n, tot[333], cnt[333], pw[max_n];
string s;

int mul(int x, int y) {
    return 1LL * x * y % mod;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    pw[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        pw[i] = mul(pw[i - 1], 3);
    }
    cin >> n >> s;
    for (char c : s) {
        ++tot[c];
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'b' || s[i] == '?') {
            int ql = cnt['?'];
            int qr = tot['?'] - ql;
            qr -= s[i] == '?';
            int a = cnt['a'];
            int c = tot['c'] - cnt['c'];

            ans += mul(a, mul(c, pw[ql + qr]));
            if (qr) {
                ans += mul(a, mul(qr, pw[ql + qr - 1]));
            }
            if (ql) {
                ans += mul(c, mul(ql, pw[qr + ql - 1]));
            }
            if (ql && qr) {
                ans += mul(ql, mul(qr, mul(pw[ql - 1], pw[qr - 1])));
            }
        }
        ++cnt[s[i]];
    }
    cout << ans % mod << "\n";
    return 0;
}