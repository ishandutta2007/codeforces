#include <bits/stdc++.h>

using namespace std;

template<int max_lev>
struct FFT {
    static const int max_n = 1 << max_lev;

    typedef double real_type;

    template<typename real_type>
    struct my_complex {
        real_type x, y;

        my_complex(real_type x = 0, real_type y = 0): x(x), y(y) {
        }

        void operator += (const my_complex &o) {
            x += o.x;
            y += o.y;
        }

        void operator -= (const my_complex &o) {
            x -= o.x;
            y -= o.y;
        }

        my_complex operator * (const my_complex &o) const {
            return my_complex(x * o.x - y * o.y, x * o.y + o.x * y);
        }

        void operator /= (real_type k) {
            x /= k;
            y /= k;
        }
    };

    typedef my_complex<real_type> base;

    int rev[max_n];
    real_type si[max_n];
    base buf1[max_n], buf2[max_n], bufpw[max_n];

    FFT() {
        const real_type full = 4 * acosl(0.0);
        for (int i = 0; i < max_n; ++i) {
            si[i] = sinl(full * i / max_n);
            rev[i] = (rev[i / 2] / 2) + ((i & 1) << (max_lev - 1));
        }
    }

    template<bool inv>
    void fft(base *a, int lg) {
        const int n = 1 << lg;
        for (int i = 0; i < n; ++i) {
            int r = (rev[i] >> (max_lev - lg)) & (n - 1);
            if (i < r) {
                swap(a[i], a[r]);
            }
        }
        int pl = max_n / 2;
        for (int st = 1; st < n; st *= 2) {
            if (inv) {
                for (int i = 0, pos = 0; i < st; ++i, pos += pl) {
                    bufpw[i] = {si[(max_n / 4 + pos) & (max_n - 1)], -si[pos]};
                }
            } else {
                for (int i = 0, pos = 0; i < st; ++i, pos += pl) {
                    bufpw[i] = {si[(max_n / 4 + pos) & (max_n - 1)], si[pos]};
                }
            }
            for (int i = 0; i < n; i += 2 * st) {
                base *curpw = bufpw;
                for (int j = i; j < i + st; ++j) {
                    const base y = *curpw * a[j + st];
                    a[j + st] = a[j];
                    a[j + st] -= y;
                    a[j] += y;
                    ++curpw;
                }
            }
            pl /= 2;
        }
    }

    vector<long long> product(const vector<int> &a, const vector<int> &b) {
        int sz = a.size() + b.size() - 1;
        int n = 1, lg = 0;
        while (n < sz) {
            n *= 2;
            ++lg;
        }
        copy(a.begin(), a.end(), buf1);
        copy(b.begin(), b.end(), buf2);
        fill(buf1 + a.size(), buf1 + n, 0);
        fill(buf2 + b.size(), buf2 + n, 0);
        fft<false>(buf1, lg);
        fft<false>(buf2, lg);
        for (int i = 0; i < n; ++i) {
            buf1[i] = buf1[i] * buf2[i];
        }
        fft<true>(buf1, lg);
        vector<long long> ans(sz);
        for (int i = 0; i < sz; ++i) {
            buf1[i] /= n;
            ans[i] = buf1[i].x + 0.5;
        }
        return ans;
    }
};

FFT<18> fft;

const int max_n = 200222, inf = 100001;

int n, m, q, a[max_n], b[max_n];
long long ans1[max_n], ans2[max_n], e1[max_n], e2[max_n];

void proc(long long ans[], const vector<long long> &v) {
    long long sum = 0;
    for (int i = 0; i < max_n; ++i) {
        if (i < v.size()) {
            sum += v[i];
        }
        ans[i] += sum;
    }
}

void add_vertices(long long ans[]) {
    vector<int> c1(inf), c2(inf);
    for (int i = 0; i < n; ++i) {
        ++c1[a[i]];
    }
    for (int i = 0; i < m; ++i) {
        ++c2[b[i]];
    }
    vector<long long> v = fft.product(c1, c2);
    proc(ans, v);
}

void add_horizontal_edges(long long ans[]) {
    vector<int> c1(inf), c2(inf);
    for (int i = 0; i < n; ++i) {
        ++c1[a[i]];
    }
    for (int i = 0; i + 1 < m; ++i) {
        ++c2[max(b[i], b[i + 1])];
    }
    vector<long long> v = fft.product(c1, c2);
    proc(ans, v);
}

void add_vertical_edges(long long ans[]) {
    vector<int> c1(inf), c2(inf);
    for (int i = 0; i + 1 < n; ++i) {
        ++c1[max(a[i], a[i + 1])];
    }
    for (int i = 0; i < m; ++i) {
        ++c2[b[i]];
    }
    vector<long long> v = fft.product(c1, c2);
    proc(ans, v);
}

void add_squares(long long ans[]) {
    vector<int> c1(inf), c2(inf);
    for (int i = 0; i + 1 < n; ++i) {
        ++c1[max(a[i], a[i + 1])];
    }
    for (int i = 0; i + 1 < m; ++i) {
        ++c2[max(b[i], b[i + 1])];
    }
    vector<long long> v = fft.product(c1, c2);
    proc(ans, v);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &b[i]);
    }
    add_vertices(ans1);
    add_squares(ans1);
    add_horizontal_edges(e1);
    add_vertical_edges(e1);
    for (int i = 0; i < n; ++i) {
        a[i] = inf - a[i];
    }
    for (int i = 0; i < m; ++i) {
        b[i] = inf - b[i];
    }
    add_vertices(ans2);
    add_squares(ans2);
    add_horizontal_edges(e2);
    add_vertical_edges(e2);
    while (q--) {
        int x;
        scanf("%d", &x);
        long long ans = (ans2[2 * inf - x] + e1[x - 1]) - (ans1[x - 1] + e2[2 * inf - x]);
        printf("%lld\n", ans);
    }
    return 0;
}