#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SZ(x) ((int)((x).size()))
#define all(x) (x).begin(), (x).end()

// Returns the time elapsed in nanoseconds from 1 January 1970, at 00:00:00.
LL get_time() {
    return chrono::duration_cast<chrono::nanoseconds>(
        chrono::steady_clock::now().time_since_epoch())
        .count();
}

// Returns a random integer from the range [l, r].
LL randint(LL l, LL r) {
	#if DEBUG && !ONLINE_JUDGE
	static mt19937_64 gen; // Deterministic on the local machine.
	#else
	static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
	#endif
	return uniform_int_distribution<LL>(l, r)(gen);
}

template <typename Iterator>
string print_iterable(Iterator begin, Iterator end, string bef, string aft,
        function<string(typename iterator_traits<Iterator>::value_type)>* f = nullptr) {
    stringstream res;
    res << bef;
    bool is_first = true;
    for (Iterator it = begin; it != end; ++it) {
        if (!is_first) res << ", ";
        if (f != nullptr) res << (*f)(*it);
        else res << *it;
        is_first = false;
    }
    res << aft;
    return res.str();
}

template <typename S, typename T>
ostream& operator <<(ostream& out, const pair<S, T>& p) {
    out << "{" << p.first << ", " << p.second << "}";
    return out;
}

#define _define_print_container(Container, bef, aft)        \
template <typename T>                                       \
ostream& operator <<(ostream& out, const Container<T>& v) { \
    out << print_iterable(v.begin(), v.end(), bef, aft);    \
    return out;                                             \
}                                                           \

_define_print_container(vector, "[", "]");
_define_print_container(set, "{", "}");
_define_print_container(unordered_set, "{", "}");
_define_print_container(multiset, "{", "}");
_define_print_container(unordered_multiset, "{", "}");
_define_print_container(deque, "[", "]");

#define _define_print_dictionary(Dictionary, bef, aft)                      \
template <typename T1, typename T2>                                         \
ostream& operator <<(ostream& out, const Dictionary<T1, T2>& v) {           \
    out << print_iterable(v.begin(), v.end(), bef, aft);                    \
    return out;                                                             \
}                                                                           \

_define_print_dictionary(map, "{", "}");
_define_print_dictionary(unordered_map, "{", "}");

#define _define_print_container_adaptor(Adaptor, OP)                        \
template <typename T>                                                       \
ostream& operator <<(ostream& out, Adaptor<T> a) {                          \
    vector<T> v;                                                            \
    while (!a.empty()) v.push_back(a.OP()), a.pop();                        \
    out << v;                                                               \
    return out;                                                             \
}                                                                           \

_define_print_container_adaptor(stack, top)
_define_print_container_adaptor(queue, front)
_define_print_container_adaptor(priority_queue, top)

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
    #define dbg_arr(x, len) \
    clog << #x << ": " << print_iterable(x, x+len, "[", "]") << endl;
    #define dbg_arr1(x, len) \
    clog << #x << ": " << print_iterable(x+1, x+len+1, "[", "]") << endl;
#else
    #define dbg(...)
    #define dbg_arr(x, len)
    #define dbg_arr1(x, len)
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

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

const int MAXN = 300100;
mint fact[MAXN];
mint invfact[MAXN];
mint factfact[MAXN];
mint sum_single[MAXN];
mint pow2[MAXN];

mint binom(int a, int b) {
    assert(0 <= b and b <= a);
    return fact[a] * invfact[b] * invfact[a-b];
}

void solve() {
    int n;
    cin >> n;
    mint res = 0;
    for (int p = 0; 2*p <= n; p += 2) {
        int s = n - 2*p;
        mint ways = binom(n-p, p);
        mint single_matching = sum_single[s];
        mint double_matching = 1;
        if (p > 0) double_matching = pow2[p/2] * factfact[p-1];
        res += ways * single_matching * double_matching;
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    mint::set_mod(998244353);
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) fact[i] = i * fact[i-1];
    invfact[MAXN-1] = mint(1) / fact[MAXN-1];
    for (int i = MAXN-2; i >= 0; i--) invfact[i] = invfact[i+1] * (i+1);
    factfact[1] = 1;
    for (int i = 3; i < MAXN; i += 2) factfact[i] = factfact[i-2] * i;
    pow2[0] = 1;
    for (int i = 1; i < MAXN; i++) pow2[i] = pow2[i-1] * 2;

    vector<mint> a(MAXN);
    vector<mint> b(MAXN);
    for (int i = 0; i < MAXN; i++) {
        if (i == 0) a[0] = 1;
        else a[i] = factfact[i-1] * invfact[i];
        b[i] = invfact[i];
    }
    vector<mint> c = Convolution(a, b);
    for (int i = 0; i < MAXN; i++) sum_single[i] = c[i] * fact[i];

    int t;
    cin >> t;
    while (t--) solve();
    
}