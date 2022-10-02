#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
typedef long long LL;
#define SZ(x) ((int)((x).size()))
 
template <typename T1, typename T2>
string print_iterable(T1 begin_iter, T2 end_iter, int counter) {
    bool done_something = false;
    stringstream res;
    res << "[";
    for (; begin_iter != end_iter and counter; ++begin_iter) {
        done_something = true;
        counter--;
        res << *begin_iter << ", ";
    }
    string str = res.str();
    if (done_something) {
        str.pop_back();
        str.pop_back();
    }
    str += "]";
    return str;
}
 
vector<int> SortIndex(int size, std::function<bool(int, int)> compare) {
    vector<int> ord(size);
    for (int i = 0; i < size; i++) ord[i] = i;
    sort(ord.begin(), ord.end(), compare);
    return ord;
}
 
template <typename T>
bool MinPlace(T& a, const T& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
 
template <typename T>
bool MaxPlace(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template <typename S, typename T>
ostream& operator <<(ostream& out, const pair<S, T>& p) {
    out << "{" << p.first << ", " << p.second << "}";
    return out;
}
 
template <typename T>
ostream& operator <<(ostream& out, const vector<T>& v) {
    out << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        out << v[i];
        if (i != (int)v.size()-1) out << ", ";
    }
    out << "]";
    return out;
}
 
template<class TH>
void _dbg(const char* name, TH val){
    clog << name << ": " << val << endl;
}
template<class TH, class... TA>
void _dbg(const char* names, TH curr_val, TA... vals) {
    while(*names != ',') clog << *names++;
    clog << ": " << curr_val << ", ";
    _dbg(names+1, vals...);
}
 
#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file
 
    #define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
    #define dbg_arr(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg(...)
    #define dbg_arr(x, len)
#endif

// Computes the inverse of n modulo m.
// Precondition: n >= 0, m > 0 and gcd(n, m) == 1.
// The returned value satisfies 0 <= x < m (Inverse(0, 1) = 0).
// ACHTUNG: It must hold max(m, n) < 2**31 to avoid integer overflow.
LL Inverse(LL n, LL m) {
    n %= m;
    if (n <= 1) return n; // Handles properly (n = 0, m = 1).
    return m - ((m * Inverse(m, n) - 1) / n);
}

// Fast exponentiation modulo mod. Returns x**e modulo mod.
// Assumptions: 0 <= x < mod
//              mod < 2**31.
//              0 <= e < 2**63
LL pow(LL x, LL e, LL mod) {
    LL res = 1;
    for (; e >= 1; e >>= 1) {
        if (e & 1) res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}

// Struct that computes x % mod faster than usual, if mod is always the same.
// It gives a x1.8 speed up over the % operator (with mod ~ 1e9 and x large).
// It is an implementation of the Barrett reduction, see
//    https://en.wikipedia.org/wiki/Barrett_reduction .
// If fast_mod is an instance of the class, then fast_mod(x) will return
// x % mod. There are no restrictions on the values of mod and x, provided
// that they fit in an unsigned long long (and mod != 0).
//
// ACHTUNG: The integer type __uint128_t must be available.
struct FastMod {
    ULL mod;
    ULL inv;
    FastMod(ULL mod) : mod(mod), inv(-1ULL / mod) {}
    ULL operator()(ULL x) {
        ULL q = (ULL)((__uint128_t(inv) * x) >> 64);
        ULL r = x - q * mod;
        return r - mod * (r >= mod);
    }
};

// Class for integers modulo mod.
// It supports all expected operations: +, -, *, /, pow, ==, < and >.
// It is as fast as it can be.
// The modulo mod shall be set through set_mod().
//
// Assumptions: mod < (1<<30).
// ACHTUNG: The integer type __uint128_t must be available.
//
// Remark: To handle larger moduli (up to 1<<62), one has to:
//          1. replace int in the definitions of mod, n.
//          2. The parameter of fast_mod must be __uint128_t, so it must be
//             changed in the definition of fast_mod and in the definition of
//             the operators * and *=.
//          3. fast_mod must be a naive modulo operation, no barrett reduction.
//          4. In Inverse, __int128_t shall be used.
struct ModularInteger {
    static int mod;
    static __uint128_t inv_mod; // Necessary for fast_mod.
    int n; // 0 <= n < mod at all times
    static void set_mod(int _mod) {
        mod = _mod;
        inv_mod = -1ULL / mod;
    }
    ModularInteger(): n(0) {}
    ModularInteger(LL _n): n(_n % mod) {
        n += (n<0)*mod;
    }
    LL get() const { return n; }
    static int fast_mod(ULL x) { // Barrett reduction.
        ULL q = (inv_mod * x) >> 64;
        int m = x - q * mod;
        m -= mod * (m >= mod);
        return m;
    }

    ModularInteger operator-() const { return n?mod-n:0; }
};
int ModularInteger::mod;
__uint128_t ModularInteger::inv_mod;

ModularInteger operator +(const ModularInteger& A, const ModularInteger& B) {
    ModularInteger C;
    C.n = A.n + B.n;
    C.n -= (C.n >= ModularInteger::mod)*ModularInteger::mod;
    return C;
}

void operator +=(ModularInteger& A, const ModularInteger& B) {
    A.n += B.n;
    A.n -= (A.n >= ModularInteger::mod)*ModularInteger::mod;
}

ModularInteger operator -(const ModularInteger& A, const ModularInteger& B) {
    ModularInteger C;
    C.n = A.n - B.n;
    C.n += (C.n < 0)*ModularInteger::mod;
    return C;
}

void operator -=(ModularInteger& A, const ModularInteger& B) {
    A.n -= B.n;
    A.n += (A.n < 0)*ModularInteger::mod;
}

ModularInteger operator *(const ModularInteger& A, const ModularInteger& B) {
    ModularInteger C;
    C.n = ModularInteger::fast_mod(((ULL)A.n) * B.n);
    return C;
}

void operator *=(ModularInteger& A, const ModularInteger& B) {
    A.n = ModularInteger::fast_mod(((ULL)A.n) * B.n);
}

// Assumption: gcd(B, mod) = 1.
ModularInteger operator /(const ModularInteger& A, const ModularInteger& B) {
    return A * Inverse(B.n, ModularInteger::mod);
}

// Assumption: gcd(B, mod) = 1.
void operator/=(ModularInteger& A, const ModularInteger& B) {
    A *= Inverse(B.n, ModularInteger::mod);
}

ModularInteger power(ModularInteger A, ULL e) {
    ModularInteger res = 1;
    for (; e >= 1; e >>= 1) {
        if (e & 1) res *= A;
        A *= A;
    }
    return res;
}

bool operator ==(const ModularInteger& A, const ModularInteger& B) {
    return A.n == B.n;
}
bool operator !=(const ModularInteger& A, const ModularInteger& B) {
    return A.n != B.n;
}
bool operator <(const ModularInteger& A, const ModularInteger& B) {
    return A.n < B.n;
}
bool operator >(const ModularInteger& A, const ModularInteger& B) {
    return A.n > B.n;
}
bool operator <=(const ModularInteger& A, const ModularInteger& B) {
    return A.n <= B.n;
}
bool operator >=(const ModularInteger& A, const ModularInteger& B) {
    return A.n >= B.n;
}

ostream& operator <<(ostream& out, const ModularInteger& A) {
    out << A.n;
    return out;
}

istream& operator >>(istream& in, ModularInteger& A) {
  LL a;
  in >> a;
  A = ModularInteger(a);
  return in;
}

typedef ModularInteger mint;

// Returns x such that Ord_mod(x) = order.
// Assumptions:
//  1. mod is an odd prime < 2**31
//  2. order | mod-1
//
// Complexity: sqrt(lpf(order)) + polylog(order).
// When this function is used as a building block for the number theoretic
// transform, order is a power of two and therefore the complexity is
// polylog(order).
LL FindElementWithGivenOrder(LL mod, LL order) {
    assert((mod-1)%order == 0);
    vector<LL> primes; // primes dividing order
    LL n = order;
    for (LL p = 2; p*p <= n; p++) {
        if (n % p == 0) {
            primes.push_back(p);
            while (n % p == 0) n /= p;
        }
    }
    if (n != 1) primes.push_back(n);
    for (LL x = 2; x < mod; x++) {
        LL y = pow(x, (mod-1)/order, mod);
        if (pow(y, order, mod) != 1) continue;
        bool works = true;
        for (LL p : primes) {
            if (pow(y, order/p, mod) == 1) {
                works = false;
                break;
            }
        }
        if (works) return y;
    }
    assert(0);
    return -1;
}


// Precomputes the vectors rev and roots as required by the function FFT.
// It is called internally by FFT when necessary (i.e., when the length of
// the vector is strictly larger than all previous calls to FFT).
// Both the arrays rev and roots have length N. Their values satisfy:
// - rev[i] is the bit-reverse of i.
// - roots contains the roots of unity. For any k that is a power of two,
//   and any i < k, roots[k + i] contains the i-th power of the (2k)-root of
//   unity. Using such an array speeds up (and simplifies) the code.
//
// Complexity: O(N)
//
// Assumptions:
//  1. The type T is either complex<double> or ModularInteger.
//  2. N power of 2
//  3. If T = ModularInteger, then ModularInteger::mod is prime and
//     N | mod-1 .
template <typename T>
void _FFT_Precompute(int N, vector<int>& rev, vector<T>& roots) {
    static_assert(std::is_same<T, ModularInteger>::value
                  or std::is_same<T, complex<double>>::value);
    assert(N > 0 and !(N&(N-1)));
    rev.resize(N);
    roots.resize(N);
    rev[0] = 0;
    for (int i = 1; i < N; i++) rev[i] = (rev[i>>1]>>1) ^ ((i&1)?(N>>1):0);
    
    // The generation of primitive roots is handled differently for complex
    // numbers and finite fields.
    if constexpr (std::is_same<T, ModularInteger>::value) {
        ModularInteger primitive_root =
            FindElementWithGivenOrder(ModularInteger::mod, N);
        for (int k = 1; k < N; k<<=1) {
            // z is a (2k)-primitive root.
            ModularInteger z = power(primitive_root, N/(2*k)); 
            ModularInteger r = 1;
            for (int i = 0; i < k; i++) {
                roots[k+i] = r;
                r *= z;
            }
        }
    } else {
        for (int k = 1; k < N; k<<=1) {
            for (int i = 0; i < k; i++) {
                double theta = M_PI*i/k;
                roots[k+i] = cos(theta) + 1i * sin(theta);
            }
        }
    }
}

// Given a sequence of numbers, computes its discrete Fourier transform in-place.
// If inverse=true then the inverse of the Fourier transform is computed.
//
// More precisely, the resulting array a' satisfies
//  a'_i = \sum a_j w^{ij} ,
// where w is an N-root of unity (N = a.size()).
//
// Complexity: O(Nlog(N)) where N = a.size().
//
// Assumptions:
//  1. The type T is either complex<double> or ModularInteger.
//  2. The length of a is a power of 2.
//  3. If T = ModularInteger, then ModularInteger::mod is prime and the
//     length of a divides mod-1 .
template <typename T>
void FFT(vector<T>& a, bool inverse=false) {
    static_assert(std::is_same<T, ModularInteger>::value
                  or std::is_same<T, complex<double>>::value);
    static vector<int> rev;
    static vector<T> roots;
    int N = a.size();
    assert(N > 0 and !(N&(N-1)));
    if ((int)rev.size() < N) _FFT_Precompute(N, rev, roots);

    int offset = 0;
    while ((1<<offset) < (int)rev.size()/N) offset++;

    for (int i = 0; i < N; i++) if (i < (rev[i]>>offset)) {
        swap(a[i], a[rev[i]>>offset]);
    }
    
    for (int k = 1; k < N; k<<=1) {
        for (int i = 0; i < N; i+=2*k) {
            for (int j = 0; j < k; j++) {
                T x = a[i+j], y = a[i+k+j] * roots[k+j];
                a[i+j] = x + y;
                a[i+k+j] = x - y;
            }
        }
    }

    if (inverse) {
        reverse(a.begin()+1, a.end());
        T invN = static_cast<T>(1) / static_cast<T>(N);
        for (auto& val : a) val *= invN;
    }
}


// Computes the convolution between a and b in O(n log n) where
// n = a.size() + b.size().
// It returns a vector c such that
//   c[k] = \sum_{i+j = k} a[i] b[j].
//
// Assumption: a and b are nonempty.
template<typename T>
vector<T> Convolution(vector<T> a, vector<T> b) {
    const static int small_len = 64;
    int alen = a.size(), blen = b.size();
    if (alen == 0 or blen == 0) return {};
    assert(1 <= alen and 1 <= blen);

    // Naive convolution O(alen * blen).
    // Used if one of the two vectors is very short.
    if (alen < small_len or blen < small_len) {
        vector<T> c(alen + blen-1, 0);
        for (int i = 0; i < alen; i++) for (int j = 0; j < blen; j++)
            c[i + j] += a[i] * b[j];
        return c;
    }
    
    int sz = 1;
    while (sz < alen + blen - 1) sz *= 2;
    a.resize(sz, 0);
    b.resize(sz, 0);
    FFT(a);
    FFT(b);
    for (int i = 0; i < sz; i++) a[i] *= b[i];
    FFT(a, true);
    a.resize(alen + blen - 1);
    return a;
}


// F is a field. Must support operator +, +=, -, -=, *, / as defined by the field.
// F(0) must return additive identity. F(1) must return multiplicative identity.
template<typename F>
struct Polynomial {
    vector<F> coef;

    Polynomial() {}

    Polynomial(const vector<F> &_coef) : coef(_coef) {}

    Polynomial(vector<F> &&_coef) : coef(_coef) {}

    size_t size() const {
        return coef.size();
    }

    void trim_leading_zeros() {
        while (!coef.empty() && coef.back() == F(0))
            coef.pop_back();
    }

    void resize(size_t new_size) {
        coef.resize(new_size, F(0));
    }

    void operator+=(const Polynomial &other) {
        for (size_t i = 0; i < other.size(); i++)
            if (i < coef.size())
                coef[i] += other.coef[i];
            else
                coef.push_back(other.coef[i]);
    }

    Polynomial operator+(const Polynomial &other) const {
        Polynomial ret = *this;
        ret += other;
        return ret;
    }

    void operator-=(const Polynomial &other) {
        for (size_t i = 0; i < other.size(); i++)
            if (i < coef.size())
                coef[i] -= other.coef[i];
            else
                coef.push_back(-other.coef[i]);
    }

    Polynomial operator-(const Polynomial &other) const {
        Polynomial<F> ret = *this;
        ret -= other;
        return ret;
    }

    Polynomial operator*(const Polynomial &other) const {
        return Polynomial(Convolution<F>(this->coef, other.coef));
    }

    void operator*=(const Polynomial &other) {
        *this = *this * other;
    }

    // f(x)g(x) = 1 (mod x^N)
    Polynomial recip_mod(size_t deg = 0) const {
        size_t n = deg;
        if (n == 0)
            n = size();
        const int N_RECIP_MOD_NAIVE = 64;
        if (n <= N_RECIP_MOD_NAIVE) {
            Polynomial ret;
            ret.coef.reserve(n);
            ret.coef.push_back(F(1) / coef[0]);
            for (size_t i = 1; i < n; i++) {
                F s(0);
                for (size_t j = 1; j <= i && j < size(); j++)
                    s -= coef[j] * ret.coef[i - j];
                ret.coef.push_back(s * ret.coef[0]);
            }
            return ret;
        }
        size_t n_low = (n + 1) / 2;
        Polynomial low_recip;
        if (size() <= n_low)
            low_recip = recip_mod(n_low);
        else {
            Polynomial low(vector<F>(coef.begin(), coef.begin() + n_low));
            low_recip = low.recip_mod();
        }
        Polynomial ret = low_recip * low_recip;
        if (size() <= n)
            ret *= *this;
        else {
            Polynomial trunc(vector<F>(coef.begin(), coef.begin() + n));
            ret *= trunc;
        }
        ret.resize(n);
        for (size_t i = n_low; i < n; i++)
            ret.coef[i] = -ret.coef[i];
        return ret;
    }

    Polynomial rev() const {
        Polynomial ret = *this;
        reverse(ret.coef.begin(), ret.coef.end());
        return ret;
    }

    Polynomial derivative() const {
        if (size() <= 1)
            return Polynomial();
        Polynomial deriv;
        deriv.coef.reserve(size() - 1);
        F multiplier(0);
        for (size_t i = 1; i < size(); i++) {
            multiplier += F(1);
            deriv.coef.push_back(coef[i] * multiplier);
        }
        return deriv;
    }

    Polynomial integral() const {
        if (size() <= 1)
            return Polynomial({F(0)});
        Polynomial integ;
        integ.coef.reserve(size() + 1);
        integ.coef.emplace_back(0);
        F divisor(0);
        for (size_t i = 0; i < size(); i++) {
            divisor += F(1);
            integ.coef.push_back(coef[i] / divisor);
        }
        return integ;
    }
};

Polynomial<mint> exp(Polynomial<mint> f) {
    Polynomial<mint> g({1});
    while (g.size() < f.size()) {
        size_t next_size = min(g.size() * 2, f.size());
        vector<mint> f_coef_trunc(f.coef.begin(), f.coef.begin() + next_size);
        f_coef_trunc[0] += 1;
        Polynomial<mint> f_trunc(move(f_coef_trunc));
        Polynomial<mint> log_g = g;
        log_g.resize(next_size);
        log_g = log_g.recip_mod() * g.derivative();
        log_g.resize(next_size - 1);
        log_g = log_g.integral();
        g *= f_trunc - log_g;
        g.resize(next_size);
    }
    return g;
}

 
///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////
 

 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    mint::set_mod(998244353);
 
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    s = '_' + s;
    vector<mint> fact(n+1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = fact[i-1] * i;
    vector<mint> ifact(n+1);
    ifact[n] = mint(1) / fact[n];
    for (int i = n-1; i >= 0; i--) ifact[i] = ifact[i+1] * (i+1);

    // Definitions of q, a21, b21, a12.
    // Complexity O(nm).
    auto q = [&](int p, char c) { return p > m or s[p] == c; };
    vector<vector<mint>> _a21(m+2, vector<mint>(n+m+2));
    auto b21 = [&](int k) { return _a21[m+1][m+k]; };
    auto a21 = [&](int l, int r) { return (l > m) ? b21(r-l+1) : _a21[l][r]; };
    for (int l = m+1; l >= 0; l--) {
        _a21[l][l+1] = q(l, '>');
        _a21[l][l+2] = q(l, '<') and q(l+1, '>');
        for (int r = l+3; r <= n+m+1; r++)
            _a21[l][r] = q(l, '<') * a21(l+1, r) + q(r-1, '>') * a21(l, r-1);
    }
    auto a12 = [&](int l, int r) { return (l + 1 == r) ? q(l, '<') : a21(l, r); };

    // Definitions of u, x, v.
    // Complexity O(nm).
    vector<mint> u(n);
    for (int i = 0; i < n; i++) u[i] = b21(i+2) * ifact[i];

    vector<mint> x(m);
    x[0] = 1;
    for (int k = 1; k < m; k++) {
        for (int i = 0; i < k; i++) x[k] += x[i] * u[k-1-i];
        for (int i = 0; i <= min(k-1, m-1); i++) {
            mint diff = a21(i+1, k+1) - b21(k+1-i);
            x[k] += diff * x[i] * ifact[k-1-i];
        }
        x[k] /= k;
    }

    vector<mint> v(n);
    for (int k = 0; k < n; k++) {
        for (int i = 0; i <= min(k, m-1); i++) {
            mint diff = a21(i+1, k+2) - b21(k+2-i);
            v[k] += x[i] * diff * ifact[k-i];
        }
    }
    

    // BEGIN Generating functions
    // Complexity O(nlog(n)).
    Polynomial<mint> U(u);
    Polynomial<mint> V(v);

    Polynomial<mint> Y = exp(U.integral());
    Polynomial<mint> Y_inv = Y.recip_mod();
    Polynomial<mint> X = Y + Y * (V*Y_inv).integral();
    // END Generating functions

    // Computing
    //   pref[k] = a_{*1}(1, k),
    //   suff[k] = a_{1*}(k, n).
    // Complexity O(nm).
    vector<mint> pref(n+1);
    vector<mint> suff(n+1);

    for (int k = 1; k <= n; k++) {
        pref[k] = X.coef[k-1] * fact[k-1];
        suff[n+1-k] = Y.coef[k-1] * fact[k-1];
    }

    auto binom = [&](int a, int b) {
        return fact[a] * ifact[b] * ifact[a-b];
    };
    for (int k = m; k >= 1; k--) {
        suff[k] = 0;
        for (int i = k+1; i <= n; i++)
            suff[k] += a12(k, i) * suff[i] * binom(n-k-1, i-k-1);
    }

    // Computing the result.
    // Complexity O(n).
    mint res = 0;
    for (int i = 1; i <= n; i++) res += pref[i] * suff[i] * binom(n-1, i-1);
    cout << res << "\n";
}