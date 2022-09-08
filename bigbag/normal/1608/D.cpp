/**
 *  created: 11/12/2021, 13:05:56
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, mod = 998244353;

template<int mod>
struct NTT {
    static constexpr int max_lev = __builtin_ctz(mod - 1);

    int prod[2][max_lev - 1];

    NTT() {
        int root = (mod == 998244353) ? 31 : find_root();
        int rroot = inv(root);
        vector<vector<int>> roots(2, vector<int>(max_lev - 1));
        roots[0][max_lev - 2] = root;
        roots[1][max_lev - 2] = rroot;
        for (int tp = 0; tp < 2; ++tp) {
            for (int i = max_lev - 3; i >= 0; --i) {
                roots[tp][i] = mul(roots[tp][i + 1], roots[tp][i + 1]);
            }
        }
        for (int tp = 0; tp < 2; ++tp) {
            int cur = 1;
            for (int i = 0; i < max_lev - 1; ++i) {
                prod[tp][i] = mul(cur, roots[tp][i]);
                cur = mul(cur, roots[tp ^ 1][i]);
            }
        }
    }

    template<bool inverse>
    void fft(int *a, int lg) const {
        const int n = 1 << lg;
        int pos = max_lev - 1;
        for (int it = 0; it < lg; ++it) {
            const int h = inverse ? lg - 1 - it : it;
            const int shift = (1 << (lg - h - 1));
            int coef = 1;
            for (int start = 0; start < (1 << h); ++start) {
                for (int i = start << (lg - h); i < (start << (lg - h)) + shift; ++i) {
                    if (!inverse) {
                        const int y = mul(a[i + shift], coef);
                        a[i + shift] = a[i];
                        inc(a[i], y);
                        dec(a[i + shift], y);
                    } else {
                        const int y = mul(a[i] + mod - a[i + shift], coef);
                        inc(a[i], a[i + shift]);
                        a[i + shift] = y;
                    }
                }
                coef = mul(coef, prod[inverse][__builtin_ctz(~start)]);
            }
        }
        if (inverse) {
            const int rn = inv(n);
            for (int i = 0; i < n; ++i) {
                a[i] = mul(a[i], rn);
            }
        }
    }

    vector<int> product(vector<int> a, vector<int> b) const {
        if (a.empty() || b.empty()) {
            return {};
        }
        const int sz = a.size() + b.size() - 1;
        const int lg = 32 - __builtin_clz(sz - 1), n = 1 << lg;
        a.resize(n);
        b.resize(n);
        fft<false>(a.data(), lg);
        fft<false>(b.data(), lg);
        for (int i = 0; i < n; ++i) {
            a[i] = mul(a[i], b[i]);
        }
        fft<true>(a.data(), lg);
        a.resize(sz);
        return a;
    }

    vector<int> square(vector<int> a) const {
        if (a.empty()) {
            return {};
        }
        const int sz = a.size() + a.size() - 1;
        const int lg = 32 - __builtin_clz(sz - 1), n = 1 << lg;
        a.resize(n);
        fft<false>(a.data(), lg);
        for (int i = 0; i < n; ++i) {
            a[i] = mul(a[i], a[i]);
        }
        fft<true>(a.data(), lg);
        a.resize(sz);
        return a;
    }

    static int find_root() {
        for (int root = 2; ; ++root) {
            if (power(root, (1 << max_lev)) == 1 && power(root, (1 << (max_lev - 1))) != 1) {
                return root;
            }
        }
    }

    static inline void inc(int &x, int y) {
        x += y;
        if (x >= mod) {
            x -= mod;
        }
    }

    static inline void dec(int &x, int y) {
        x -= y;
        if (x < 0) {
            x += mod;
        }
    }

    static inline int mul(int x, int y) {
        return (1LL * x * y) % mod;
    }

    static int power(int x, int y) {
        if (y == 0) {
            return 1;
        }
        if (y % 2 == 0) {
            return power(mul(x, x), y / 2);
        }
        return mul(x, power(x, y - 1));
    }

    static int inv(int x) {
        return power(x, mod - 2);
    }
};

NTT<mod> ntt;

int n;
string s[max_n];
vector<int> poly[max_n];

bool ok(string a, string b) {
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i] && a[i] != '?') {
            return false;
        }
    }
    return true;
}

vector<int> get_prod(int l, int r) {
    if (l == r) {
        return poly[l];
    }
    int mid = (l + r) / 2;
    return ntt.product(get_prod(l, mid), get_prod(mid + 1, r));
}

const bool debug = 0;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    if (debug) {
        n = 100000;
    } else {
        cin >> n;
    }
    int sub = 1, add1 = 1, add2 = 1;
    for (int i = 0; i < n; ++i) {
        if (debug) {
            s[i] = "??";
        } else {
            cin >> s[i];
        }
        poly[i].resize(3);
        if (ok(s[i], "WW")) {
            ++poly[i][0];
        }
        if (ok(s[i], "BB")) {
            ++poly[i][2];
        }
        if (ok(s[i], "WB")) {
            ++poly[i][1];
        } else {
            add1 = 0;
        }
        if (ok(s[i], "BW")) {
            ++poly[i][1];
        } else {
            add2 = 0;
        }
        sub = ntt.mul(poly[i][1], sub);
    }
    int ans = get_prod(0, n - 1)[n];
    ntt.dec(ans, sub);
    ntt.inc(ans, add1);
    ntt.inc(ans, add2);
    cout << ans << "\n";
    return 0;
}