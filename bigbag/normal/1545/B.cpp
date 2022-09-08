/**
 *  created: 11/07/2021, 19:24:32
**/

#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;
const int max_n = 100111, inf = 1000111222;

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

const int max_f = 2 * max_n;

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


char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;
}

int t, n;
string s;

int main() {
    get_all_f();
//    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        s = read();
        int zeros = 0;
        for (char c : s) {
            zeros += c == '0';
        }
        int odd = 0, comps = 0, sum = 0;
        for (int i = 0; i < s.size(); ) {
            if (s[i] == '1') {
                int len = 0;
                while (i < s.size() && s[i] == '1') {
                    ++len;
                    ++i;
                }
                odd += len % 2;
                ++comps;
                sum += len / 2;
            } else {
                ++i;
            }
        }
        //cout << s.size() << " " << zeros << " " << odd << "    " << sum + zeros << endl;
        printf("%d\n", get_c(sum + zeros, zeros));
    }
    return 0;
}