#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 100111, mod = 1000000007;

int mul(int x, int y) {
    return 1LL * x * y % mod;
}

int power(int x, int y) {
    if (y == 0) {
        return 1;
    }
    if (y % 2 == 0) {
        return power(mul(x, x), y / 2);
    }
    return mul(x, power(x, y - 1));
}

int inv(int x) {
    return power(x, mod - 2);
}

const int max_f = 4 * max_n;

int f[max_f], rf[max_f];

void get_all_f() {
    f[0] = rf[0] = 1;
    for (int i = 1; i < max_f; ++i) {
        f[i] = mul(f[i - 1], i);
    }
    rf[max_f - 1] = inv(f[max_f - 1]);
    for (int i = max_f - 2; i > 0; --i) {
        rf[i] = mul(rf[i + 1], i + 1);
    }
}

int get_c(int n, int k) {
    if (n == -1 && k == -1) {
        return 1;
    }
    if (n < k || n < 0 || k < 0) {
        return 0;
    }
    return mul(f[n], mul(rf[k], rf[n - k]));
}

char tmp[max_n];

string read() {
    scanf("%s", tmp);
    return tmp;
}

int c[2][2];
string a, b;

bool is_eq(int cnt[2][2]) {
    return cnt[0][0] == c[0][0] && cnt[0][1] == c[0][1] && cnt[1][0] == c[1][0] && cnt[1][1] == c[1][1];
}

bool is_ok(const string &s) {
    int cnt[2][2] = {{0, 0}, {0, 0}};
    for (int i = 0; i + 1 < s.length(); ++i) {
        cnt[s[i] - '0'][s[i + 1] - '0']++;
    }
    return is_eq(cnt);
}

int get_r(int n, int k) {
    return get_c(n + k - 1, k - 1);
}

int func_final(int n, int cnt0, int cnt1, int C[2][2]) {
    //cout << "$" << C[0][0] << " " << cnt0 << " " << C[1][1] << " " << cnt1 << endl;
    int q = cnt0 + cnt1;
    n -= q;
    if (n < 0) {
        return 0;
    }
    if (C[0][0] + C[1][1] != n) {
        return 0;
    }
    return mul(get_r(C[0][0], cnt0), get_r(C[1][1], cnt1));
}

int func(int f1, int f2, int n, int cnt[2][2]) {
    int C[2][2];
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            C[i][j] = c[i][j] - cnt[i][j];
            if (C[i][j] < 0) {
                return 0;
            }
        }
    }
    if (n == 1) {
        return f1 == f2 && C[0][0] + C[0][1] + C[1][0] + C[1][1] == 0;
    }
    if (f1 == 0 && f2 == 0) {
        int cnt0 = C[0][1] + 1;
        if (cnt0 != C[1][0] + 1) {
            return 0;
        }
        int cnt1 = cnt0 - 1;
        return func_final(n, cnt0, cnt1, C);
    } else if (f1 == 0 && f2 == 1) {
        int cnt0 = C[0][1];
        if (cnt0 != C[1][0] + 1) {
            return 0;
        }
        int cnt1 = cnt0;
        return func_final(n, cnt0, cnt1, C);
    } else if (f1 == 1 && f2 == 0) {
        int cnt0 = C[0][1] + 1;
        if (cnt0 != C[1][0]) {
            return 0;
        }
        int cnt1 = cnt0;
        return func_final(n, cnt0, cnt1, C);
    } else {
        int cnt0 = C[0][1] + 1;
        if (cnt0 != C[1][0] + 1) {
            return 0;
        }
        int cnt1 = cnt0;
        --cnt0;
        return func_final(n, cnt0, cnt1, C);
    }
}

int solve(const string &s) {
    int n = c[0][0] + c[0][1] + c[1][0] + c[1][1] + 1;
    if (s.length() < n) {
        return 0;
    }
    int cnt[2][2] = {{0, 0}, {0, 0}};
    int res = 0;
    if (s.length() > n) {
        for (int f1 = 1; f1 < 2; ++f1) {
            for (int f2 = 0; f2 < 2; ++f2) {
                //cout << f1 << " " << f2 << ": " << func(f1, f2, n, cnt) << endl;
                res += func(f1, f2, n, cnt);
                res %= mod;
            }
        }
        return res;
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1' && i) {
            if (i) {
                ++cnt[s[i - 1] - '0'][0];
            }
            if (i + 1 == n) {
                res += is_eq(cnt);
                res %= mod;
                break;
            }
            for (int f1 = 0; f1 < 2; ++f1) {
                ++cnt[0][f1];
                for (int f2 = 0; f2 < 2; ++f2) {
                    res += func(f1, f2, n - i - 1, cnt);
                    res %= mod;
                }
                --cnt[0][f1];
            }
            if (i) {
                --cnt[s[i - 1] - '0'][0];
            }
        }
        if (i) {
            ++cnt[s[i - 1] - '0'][s[i] - '0'];
        }
    }
    return res;
}

int main() {
    //freopen("inputH.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_f();
    a = read();
    b = read();
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            scanf("%d", &c[i][j]);
        }
    }
    int ans = solve(b);
    ans += is_ok(b);
    ans += mod - solve(a);
    ans %= mod;
    printf("%d\n", ans);
    return 0;
}