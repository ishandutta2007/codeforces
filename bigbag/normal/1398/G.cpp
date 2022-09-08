#pragma GCC optimize("Ofast", "unroll-loops")
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

const int max_lev = 19, mod = 998244353;

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

const int max_n = 200222, inf = 1000111222;
const int max_x = 1000111;

int n, x, y, a[max_n];
bool ok[max_x];
int ans[max_x];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &x, &y);
    ++n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    vector<int> A(x + 1), B(x + 1);
    for (int i = 0; i < n; ++i) {
        A[a[i]] = 1;
        B[x - a[i]] = 1;
    }
    vector<int> C = ntt.product(A, B);
    for (int i = x; i < C.size(); ++i) {
        if (C[i]) {
            ok[i - x] = 1;
        }
    }
    memset(ans, -1, sizeof(ans));
    for (int x = 1; x < max_x; ++x) {
        int need = x - 2 * y;
        if (need > 0 && need % 2 == 0 && ok[need / 2]) {
            for (int y = x; y < max_x; y += x) {
                ans[y] = x;
            }
        }
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        int len;
        scanf("%d", &len);
        printf("%d ", ans[len]);
    }
    puts("");
    return 0;
}