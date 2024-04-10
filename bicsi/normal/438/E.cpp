#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

const int kMod = (119 << 23) + 1, kRoot = 3; // = 998244353
// For p < 2^30 there is also e.g. (5 << 25, 3), (7 << 26, 3),
// (479 << 21, 3) and (483 << 21, 5). The last two are > 10^9.

struct ModInt {
    long long x; 
    ModInt(long long x = 0) : x(x % kMod) {}
    int Get() { return (x < 0 ? x + kMod : x); }
    ModInt operator+(const ModInt& oth) { return x + oth.x; }
    ModInt operator*(const ModInt& oth) { return x * oth.x; }
    ModInt operator-(const ModInt& oth) { return x - oth.x; }
};
ModInt lgpow(ModInt b, int64_t e) {
    ModInt r = 1;
    while (e) {
        if (e % 2) r = r * b;
        b = b * b;
        e /= 2;
    }
    return r;
}
ModInt inv(ModInt x) { return lgpow(x, kMod - 2); }
ostream& operator<<(ostream& out, ModInt x) {
    out << x.Get();
    return out;
}

struct FFTSolver {
    vector<int> rev;

    int __lg(int n) { return n == 1 ? 0 : 1 + __lg(n / 2);  }

    void compute_rev(int n, int lg) {
        rev.resize(n); rev[0] = 0;
        for (int i = 1; i < n; ++i) {
            rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (lg - 1));
        }
    }

    vector<ModInt> fft(vector<ModInt> V, bool invert) {
        int n = V.size(), lg = __lg(n);
        if ((int)rev.size() != n) compute_rev(n, lg);

        for (int i = 0; i < n; ++i) {
            if (i < rev[i])
                swap(V[i], V[rev[i]]);
        }

        for (int step = 2; step <= n; step *= 2) {
            ModInt eps = lgpow(kRoot, (kMod - 1) / step);
            if (invert) eps = inv(eps);

            for (int i = 0; i < n; i += step) {
                ModInt w = 1;
                for (int a = i, b = i+step/2; b < i+step; ++a, ++b) {
                    ModInt aux = w * V[b];
                    V[b] = V[a] - aux;
                    V[a] = V[a] + aux;
                    w = w * eps;
                }
            }
        }

        return V;
    }

    vector<ModInt> Multiply(vector<ModInt> A, vector<ModInt> B, int n) {
        A.resize(n, 0); B.resize(n, 0);
        n *= 2;
        A.resize(n, 0); B.resize(n, 0);

        A = fft(move(A), false);
        B = fft(move(B), false);

        vector<ModInt> ret(n);
        ModInt inv_n = inv(n);

        for (int i = 0; i < n; ++i) {
            ret[i] = A[i] * B[i] * inv_n;
        }

        ret = fft(move(ret), true);
        ret.resize(n / 2);

        return ret;
    }
};

using TElem = ModInt;
using Poly = vector<TElem>;

Poly Multiply(Poly A, Poly B, int n) {
    static FFTSolver fft;
    return fft.Multiply(A, B, n);
}
Poly Scale(Poly P, TElem s) {
    for (auto& x : P)
        x = x * s;
    return P;
}
Poly Add(Poly A, Poly B, int sz) {
    A.resize(sz, 0); B.resize(sz, 0);
    for (int i = 0; i < sz; ++i)
        A[i] = A[i] + B[i];
    return A;
}

// For Invert, Sqrt, size of argument should be 2^k

Poly inv_step(Poly res, Poly P, int n) {
    auto res_sq = Multiply(res, res, n);
    auto sub = Multiply(res_sq, P, n);
    res = Add(Scale(res, 2), Scale(sub, -1), n);
    return res;
}

Poly Invert(Poly P) {
    Poly res(1, 1);
    assert(P[0].Get() == 1); // else put P[0]^(-1)
    
    int n = P.size(); 
    for (int step = 2; step <= n; step *= 2) {
        res = inv_step(res, P, step);
    }

    // Optional, but highly encouraged
//    auto check = Multiply(res, P, n);
//    for (int i = 0; i < n; ++i) {
//        assert(check[i].Get() == (i == 0));
//    }
    return res;
};

Poly Sqrt(Poly P) {
    Poly res(1, 1);
    Poly inv(1, 1);
    assert(P[0].Get() == 1); // else put P[0]^(1/2)

    int n = P.size();
    for (int step = 2; step <= n; step *= 2) {
        auto now = inv_step(inv, res, step);
        now = Multiply(P, now, step);
        res = Add(res, now, step);
        res = Scale(res, (kMod + 1) / 2);
        inv = inv_step(inv, res, step);
    }
    
    // Optional, but highly encouraged
//    auto check = Multiply(res, res, n);
//    for (int i = 0; i < n; ++i) {
//        assert(check[i].Get() == P[i].Get());
//    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    const int kDim = (1 << 17);
    Poly C(kDim);
    
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int c; cin >> c;
        C[c] = C[c] + 1;
    }

    Poly P(1, 1);
    P = Add(move(P), Scale(C, -4), kDim);
    P = Sqrt(move(P));
    P = Add(move(P), Poly(1, 1), kDim);
    P = Scale(move(P), (kMod + 1) / 2);
    P = Invert(move(P));

    for (int i = 1; i <= m; ++i) {
        cout << P[i].Get() << '\n';
    }

    return 0;
}