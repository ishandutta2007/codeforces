#include <bits/stdc++.h>

using namespace std;

#define x1 qwe
#define y1 qwer
#define x2 qwert
#define y2 qwerty

template<typename T>
ostream& operator << (ostream &os, const vector<T> &v) {
    os << "[";
    for (int i = 0; i < v.size(); ++i) {
        if (i) {
            os << " ";
        }
        os << v[i];
    }
    os << "]";
    return os;
}

namespace ntt {

const int max_lev = 15;
const int max_n = 1 << max_lev, mod = 998244353;

int mul(int x, int y) {
    return (1LL * x * y) % mod;
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

int find_root() {
    for (int root = 2; ; ++root) {
        if (power(root, max_n) == 1) {
            int cur = 1;
            bool ok = true;
            for (int i = 1; i < max_n; ++i) {
                cur = mul(cur, root);
                if (cur == 1) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                return root;
            }
        }
    }
}

int pw[max_n], rpw[max_n], rev[max_n];

void init() {
    int root = find_root();
    int rroot = power(root, mod - 2);
    pw[0] = rpw[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        pw[i] = mul(pw[i - 1], root);
        rpw[i] = mul(rpw[i - 1], rroot);
        rev[i] = (rev[i / 2] / 2) + ((i & 1) << (max_lev - 1));
    }
}

void fft(vector<int> &a, int pw[], int lg) {
    for (int i = 0; i < a.size(); ++i) {
        int r = (rev[i] >> (max_lev - lg)) & (a.size() - 1);
        if (i < r) {
            swap(a[i], a[r]);
        }
    }
    int pl = max_n / 2;
    for (int st = 1; st < a.size(); st *= 2) {
        for (int i = 0; i < a.size(); i += 2 * st) {
            int cur = 0;
            for (int j = i; j < i + st; ++j) {
                int y = mul(pw[cur], a[j + st]);
                a[j + st] = (a[j] + mod - y) % mod;
                a[j] = (a[j] + y) % mod;
                cur += pl;
            }
        }
        pl /= 2;
    }
}

vector<int> product(vector<int> &a, vector<int> &b) {
    if (pw[0] == 0) {
        puts("NTT was not initialized");
        exit(228);
    }
    int sz = a.size() + b.size() - 1;
    int N = 1, lg = 0;
    while (N < sz) {
        N *= 2;
        ++lg;
    }
    while (a.size() < N) {
        a.push_back(0);
    }
    while (b.size() < N) {
        b.push_back(0);
    }
    fft(a, pw, lg);
    fft(b, pw, lg);
    for (int i = 0; i < a.size(); ++i) {
        a[i] = mul(a[i], b[i]);
    }
    fft(a, rpw, lg);
    int rn = power(N, mod - 2);
    vector<int> ans(sz);
    for (int i = 0; i < sz; ++i) {
        ans[i] = mul(a[i], rn);
    }
    return ans;
}

}

const int max_n = 3636, mod = 998244353;

int mul(int x, int y) {
    return 1LL * x * y % mod;
}

int n, m, cnt, c[max_n][max_n], f[max_n];
int used_row[max_n], used_col[max_n];

void prec() {
    f[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        f[i] = mul(f[i - 1], i);
    }
    for (int i = 0; i < max_n; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }
    }
}

vector<int> get_v(int used[], int n) {
    vector<int> res;
    for (int i = 0; i < n; ) {
        if (!used[i]) {
            int pos = i;
            while (i < n && !used[i]) {
                ++i;
            }
            res.push_back(i - pos);
        } else {
            ++i;
        }
    }
    return res;
}

vector<int> get_dp(const vector<int> &v) {
    vector<int> res{1};
    for (int len : v) {
        vector<int> upd;
        for (int c1 = 0; 2 * c1 <= len; ++c1) {
            int coef = c[len - c1][c1];
            upd.push_back(coef);
        }
        res = ntt::product(res, upd);
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ntt::init();
    prec();
    cin >> n >> m >> cnt;
    int rows = 0, cols = 0;
    while (cnt--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        --x1;
        --y1;
        --x2;
        --y2;
        used_row[x1] = 1;
        used_row[x2] = 1;
        used_col[y1] = 1;
        used_col[y2] = 1;
        if (x1 == x2) {
            ++rows;
        } else {
            ++cols;
        }
    }
    vector<int> v1 = get_v(used_row, n);
    vector<int> v2 = get_v(used_col, m);
    vector<int> dp1 = get_dp(v1);
    vector<int> dp2 = get_dp(v2);
    //cout << dp1 << endl;
    //cout << dp2 << endl;
    //cout << rows << " " << cols << endl;
    n -= 2 * cols + rows;
    m -= 2 * rows + cols;
    int ans = 0;
    for (int c1 = 0; 2 * c1 <= n && c1 <= m && c1 < dp1.size(); ++c1) {
        for (int c2 = 0; c1 + 2 * c2 <= m && c2 + 2 * c1 <= n && c2 < dp2.size(); ++c2) {
            int add = mul(dp1[c1], dp2[c2]);
            add = mul(add, mul(c[m - 2 * c2][c1], f[c1]));
            add = mul(add, mul(c[n - 2 * c1][c2], f[c2]));
            ans += add;
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}