/**
 *  created: 30/12/2020, 18:01:30
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, mod = 1000000007;
const int max_len = 1000111;

char buf[max_len];

string read() {
    scanf("%s", buf);
    return buf;
}

inline void inc(int &x, int y) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
}

int mul(int x, int y) {
    return 1LL * x * y % mod;
}

const int max_c = 26;

int n, q, len, pw[max_n], rpw[max_n], sum[max_c][max_n];
string s0, t;

int get_sum(int c, int l, int r) {
    if (!l) {
        return sum[c][r];
    }
    return (sum[c][r] + mod - sum[c][l - 1]) % mod;
}

int rec(int pos, const string &s) {
    //cout << pos << " " << len << " " << s << endl;
    if (pos > len) {
        return 0;
    }
    if (s.empty()) {
        return pw[len - pos];
    }
    if (pos >= len) {
        return 0;
    }
    if (s.size() == 1) {
        return mul(pw[len - 1], get_sum(s[0] - 'a', pos, len - 1));
    }
    string a[2];
    for (int i = 0; i < s.length(); ++i) {
        a[i % 2] += s[i];
    }
    int res = 0;
    for (int to = 0; to < 2; ++to) {
        if (a[to ^ 1] == string(a[to ^ 1].length(), t[pos])) {
            inc(res, rec(pos + 1, a[to]));
        }
    }
    return res;
}

int solve(const string &s) {
    int res = rec(0, s);
    //cout << s << ": " << res << endl;
    return res;
}

void init() {
    const int r2 = (mod + 1) / 2;
    pw[0] = 1;
    rpw[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        pw[i] = mul(pw[i - 1], 2);
        rpw[i] = mul(rpw[i - 1], r2);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    init();
    scanf("%d%d", &n, &q);
    s0 = read();
    t = read();
    for (int i = 0; i < t.length(); ++i) {
        if (i) {
            for (int c = 0; c < max_c; ++c) {
                sum[c][i] = sum[c][i - 1];
            }
        }
        inc(sum[t[i] - 'a'][i], rpw[i]);
    }
    s0 += '?';
    while (q--) {
        scanf("%d", &len);
        string s = read();
        int ans = 0;
        for (int i = 0; i < s0.length(); ++i) {
            string need;
            bool ok = 1;
            for (int j = 0; j < s.length() && ok; ++j) {
                if (s0[j % s0.length()] == '?') {
                    need += s[j];
                } else {
                    ok &= s[j] == s0[j % s0.length()];
                }
            }
            if (ok) {
                //cout << s0 << "   ";
                inc(ans, solve(need));
            }
            rotate(s0.begin(), s0.begin() + 1, s0.end());
        }
        printf("%d\n", ans);
    }
    return 0;
}