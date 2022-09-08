/**
 *  created: 14/01/2021, 18:07:05
**/

#include <bits/stdc++.h>

using namespace std;

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

const int max_lev = 20, mod = 998244353;

template<int mod, int max_lev>
struct NTT {
    static const int max_n = 1 << max_lev;

    int roots[2][max_lev];
    int rev[max_n], buf1[max_n], buf2[max_n], bufpw[max_n];

    NTT() {
        int root = find_root();
        int rroot = power(root, mod - 2);
        roots[0][0] = root;
        roots[1][0] = rroot;
        for (int i = 1; i < max_lev; ++i) {
            roots[0][i] = mul(roots[0][i - 1], roots[0][i - 1]);
            roots[1][i] = mul(roots[1][i - 1], roots[1][i - 1]);
        }
        for (int i = 1; i < max_n; ++i) {
            rev[i] = (rev[i / 2] / 2) + ((i & 1) << (max_lev - 1));
        }
    }

    static inline void inc(int &x, int y) {
        x += y;
        if (x >= mod) {
            x -= mod;
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

    static int find_root() {
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

    void fft(int *a, const int *roots, int lg) {
        const int n = 1 << lg;
        for (int i = 0; i < n; ++i) {
            int r = (rev[i] >> (max_lev - lg)) & (n - 1);
            if (i < r) {
                swap(a[i], a[r]);
            }
        }
        int pos = max_lev - 1;
        for (int st = 1; st < n; st *= 2) {
            int cur = 1;
            for (int i = 0; i < st; ++i) {
                bufpw[i] = cur;
                cur = mul(cur, roots[pos]);
            }
            --pos;
            for (int i = 0; i < n; i += 2 * st) {
                int *curpw = bufpw;
                for (int j = i; j < i + st; ++j) {
                    int y = mul(*curpw++, a[j + st]);
                    a[j + st] = a[j];
                    inc(a[j + st], mod - y);
                    inc(a[j], y);
                }
            }
        }
    }

    vector<int> product(const vector<int> &a, const vector<int> &b) {
        int sz = a.size() + b.size() - 1;
        int n = 1, rn = 1, lg = 0;
        while (n < sz) {
            n *= 2;
            rn = mul(rn, (mod + 1) / 2);
            ++lg;
        }
        memcpy(buf1, a.data(), 4 * a.size());
        memset(buf1 + a.size(), 0, 4 * (n - a.size()));
        memcpy(buf2, b.data(), 4 * b.size());
        memset(buf2 + b.size(), 0, 4 * (n - b.size()));
        fft(buf1, roots[0], lg);
        fft(buf2, roots[0], lg);
        for (int i = 0; i < n; ++i) {
            buf1[i] = mul(buf1[i], buf2[i]);
        }
        fft(buf1, roots[1], lg);
        vector<int> ans(sz);
        for (int i = 0; i < sz; ++i) {
            ans[i] = mul(buf1[i], rn);
        }
        return ans;
    }

    vector<int> square(const vector<int> &a) {
        int sz = a.size() + a.size() - 1;
        int n = 1, rn = 1, lg = 0;
        while (n < sz) {
            n *= 2;
            rn = mul(rn, (mod + 1) / 2);
            ++lg;
        }
        memcpy(buf1, a.data(), 4 * a.size());
        memset(buf1 + a.size(), 0, 4 * (n - a.size()));
        fft(buf1, roots[0], lg);
        for (int i = 0; i < n; ++i) {
            buf1[i] = mul(buf1[i], buf1[i]);
        }
        fft(buf1, roots[1], lg);
        vector<int> ans(sz);
        for (int i = 0; i < sz; ++i) {
            ans[i] = mul(buf1[i], rn);
        }
        return ans;
    }
};

NTT<mod, max_lev> ntt;

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

const int max_f = 200111;

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
    if (n < k || k < 0) {
        return 0;
    }
    return mul(f[n], mul(rf[k], rf[n - k]));
}

int n;

const bool debug = 0;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_f();
    if (debug) {
        n = 1000;
    } else {
        cin >> n;
    }
    vector<int> dp{1};
    while (n--) {
        int a = 100000, b = 100000 - 5;
        if (!debug) {
            cin >> a >> b;
        }
        vector<int> ndp(dp.size() + a - b);
        vector<int> d(dp.size() + ndp.size() - 1);
        const int shift = dp.size() - 1;
        for (int pos = 0; pos < d.size(); ++pos) {
            const int k = pos - shift;
            d[pos] = get_c(a + b, b + k);
            continue;
            for (int j = 0; j <= b; ++j) {
                const int i = k + j;
                if (0 <= i && i <= a) {
                    inc(d[pos], mul(get_c(a, i), get_c(b, j)));
                }
            }
        }
        /*for (int i = 0; i <= a; ++i) {
            for (int j = 0; j <= b; ++j) {
                const int pos = shift + i - j;
                if (0 <= pos && pos < d.size()) {
                    inc(d[pos], mul(get_c(a, i), get_c(b, j)));
                }
            }
        }*/
        vector<int> C = ntt.product(dp, d);
        for (int i = 0; i < C.size(); ++i) {
            int pos = i - shift;
            if (0 <= pos && pos < ndp.size()) {
                inc(ndp[pos], C[i]);
            }
        }
        dp.swap(ndp);
        //cout << dp << ", d = " << d << endl;
    }
    int ans = accumulate(dp.begin(), dp.end(), 0LL) % mod;
    printf("%d\n", ans);
    return 0;
}