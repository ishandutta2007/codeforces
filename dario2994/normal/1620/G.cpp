#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SZ(x) ((int)((x).size()))

// Returns the time elapsed in nanoseconds from 1 January 1970, at 00:00:00.
LL get_time() {
    return chrono::duration_cast<chrono::nanoseconds>(
        chrono::steady_clock::now().time_since_epoch())
        .count();
}

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


#ifndef SUBSETS_OPERATIONS
#define SUBSETS_OPERATIONS

// The class SubsetFunction<T> represents a function on the subsets of
// {0, 1, ..., N-1} (or equivalently the integers [0, 2^N)) with values in T
// and offers a variety of standard operations (i.e. xor-convolution).
//
// The time complexities of the various operations are optimal.
// Even if not heavily optimized (in order to maintain a good readability),
// these implementations shall be fast enough in all situations.
//
// Only the high-level APIs (that is SubsetFunction<T>) shall be used by the
// end-user. There is no reason to call directly the low-level functions in
// namespace::internal (which, for performance and for simplicity of the
// implementation, are heavily using pointers).

#include <cassert>
#include <algorithm>
using namespace std;

// In namespace::internal, all operations are implemented directly on arrays
// (and, whenever possible, in place). There are no memory leaks.
// Operating directly on arrays simplifies the implementation (since often one
// has to treat a subarray as an array and with vectors this is not possible).
//
// The functions in namespace::internal operate on pointers and are, therefore, a bit
// uncomfortable to use for the end-user. It is much better to use the clean
// APIs offered by the class SubsetFunction.
namespace internal {

// All functions in namespace::internal take as first argument N, and as further
// arguments some arrays with size 2^N.
// Each function accepts exactly one non-const argument, that argument will
// contain (after the execution) the result of the function.

// Reset all values to 0.
// Complexity: O(2^N).
template<typename T>
void clear(int N, T* A) { fill(A, A+(1<<N), 0); }

// A'[x] = A[complement of x]
// Complexity: O(2^N).
template<typename T>
void complement(int N, T* A) {
    int pot = 1<<N;
    for (int x = 0; x < (pot>>1); x++) swap(A[x], A[x^(pot-1)]);
}

// In place xor-transform. See xor_convolution to understand its importance.
// A'[x] = \sum_y A[y]*(-1)^{bits(x&y)}.
// Complexity: O(N*2^N).
template<typename T>
void xor_transform(int N, T* A, bool inverse = false) {
    for (int len = 1; 2 * len <= (1<<N); len *= 2) {
        for (int x = 0; x < (1<<N); x += 2 * len) {
            for (int y = 0; y < len; y++) {
                T u = A[x + y];
                T v = A[x + y + len];
                A[x + y] = u + v;
                A[x + y + len] = u - v;
            }
        }
    }
    if (inverse) for (int i = 0; i < (1<<N); i++) A[i] /= (1<<N);
}

// In place and-transform. See and_convolution to understand its importance.
//   A'[x] = \sum_{x\subseteq y} A[y].
// Complexity: O(N*2^N).
template<typename T>
void and_transform(int N, T* A, bool inverse = false) {
    for (int len = 1; 2 * len <= (1<<N); len *= 2) {
        for (int x = 0; x < (1<<N); x += 2 * len) {
            for (int y = 0; y < len; y++) {
                if (inverse) A[x+y] -= A[x+y+len];
                else A[x+y] += A[x+y+len];
            }
        }
    }
}

// In place or-transform. See or_convolution to understand its importance.
//   A'[x] = \sum_{y\subseteq x} A[y].
// Complexity: O(N*2^N).
template<typename T>
void or_transform(int N, T* A, bool inverse = false) {
    for (int len = 1; 2 * len <= (1<<N); len *= 2) {
        for (int x = 0; x < (1<<N); x += 2 * len) {
            for (int y = 0; y < len; y++) {
                if (inverse) A[x+y+len] -= A[x+y];
                else A[x+y+len] += A[x+y];
            }
        }
    }
}


// C[x] = \sum_{y^z = x} A[y]B[z]
// Complexity: O(N2^N).
template<typename T>
void xor_convolution(int N, const T* A, const T* B, T* C) {
    T* B2 = new T[1<<N];
    for (int x = 0; x < (1<<N); x++) C[x] = A[x], B2[x] = B[x];
    xor_transform(N, C);
    xor_transform(N, B2);
    for (int x = 0; x < (1<<N); x++) C[x] *= B2[x];
    xor_transform(N, C, true);
    delete[] B2;
}

// C[x] = \sum_{y&z = x} A[y]B[z]
// Complexity: O(N2^N).
template<typename T>
void and_convolution(int N, const T* A, const T* B, T* C) {
    T* B2 = new T[1<<N];
    for (int x = 0; x < (1<<N); x++) C[x] = A[x], B2[x] = B[x];
    and_transform(N, C);
    and_transform(N, B2);
    for (int x = 0; x < (1<<N); x++) C[x] *= B2[x];
    and_transform(N, C, true);
    delete[] B2;
}

// C[x] = \sum_{y|z = x} A[y]B[z]
// Complexity: O(N2^N).
template<typename T>
void or_convolution(int N, const T* A, const T* B, T* C) {
    T* B2 = new T[1<<N];
    for (int x = 0; x < (1<<N); x++) C[x] = A[x], B2[x] = B[x];
    or_transform(N, C);
    or_transform(N, B2);
    for (int x = 0; x < (1<<N); x++) C[x] *= B2[x];
    or_transform(N, C, true);
    delete[] B2;
}


// C[x] = \sum_{y&z = 0, y|z = x} A[y]*B[z].
// Complexity: O(N*2^N).
template<typename T>
void subset_convolution(int N, const T* A, const T* B, T* C) {
    T** A_popcnt = new T*[N+1];
    T** B_popcnt = new T*[N+1];
    T* tmp = new T[1<<N];
    for (int i = 0; i <= N; i++) {
        A_popcnt[i] = new T[1<<N];
        B_popcnt[i] = new T[1<<N];
        clear(N, A_popcnt[i]);
        clear(N, B_popcnt[i]);
    }
    for (int x = 0; x < (1<<N); x++) {
        int q = __builtin_popcount(x);
        A_popcnt[q][x] = A[x];
        B_popcnt[q][x] = B[x];
    }
    for (int i = 0; i <= N; i++) {
        or_transform(N, A_popcnt[i]);
        or_transform(N, B_popcnt[i]);
    }
    for (int l = 0; l <= N; l++) {
        clear(N, tmp);
        for (int i = 0; i <= l; i++) {
            int j = l-i;
            for (int x = 0; x < (1<<N); x++)
                tmp[x] += A_popcnt[i][x]*B_popcnt[j][x];
        }
        or_transform(N, tmp, true);
        for (int x = 0; x < (1<<N); x++)
            if (__builtin_popcount(x) == l) C[x] = tmp[x];
    }
    for (int i = 0; i <= N; i++) {
        delete[] A_popcnt[i];
        delete[] B_popcnt[i];
    }
    delete[] A_popcnt;
    delete[] B_popcnt;
    delete[] tmp;
}

// subset_convolution(A, C) = B.
// Complexity: O(N2^N).
//
// ACHTUNG: The value A[0] must be invertible.
template<typename T>
void inverse_subset_convolution(int N, const T* A, const T* B, T* C) {
    T inv = 1/A[0];
    
    T** A_popcnt = new T*[N+1];
    T** C_popcnt = new T*[N+1];
    for (int i = 0; i <= N; i++) {
        A_popcnt[i] = new T[1<<N];
        C_popcnt[i] = new T[1<<N];
        clear(N, A_popcnt[i]);
        clear(N, C_popcnt[i]);
    }
    for (int x = 0; x < (1<<N); x++) {
        int q = __builtin_popcount(x);
        A_popcnt[q][x] = A[x];
    }
    for (int i = 0; i <= N; i++) or_transform(N, A_popcnt[i]);
    
    for (int l = 0; l <= N; l++) {
        for (int i = 0; i <= l; i++) {
            int j = l-i;
            for (int x = 0; x < (1<<N); x++)
                C_popcnt[l][x] += A_popcnt[i][x]*C_popcnt[j][x];
        }
        or_transform(N, C_popcnt[l], true);
        for (int x = 0; x < (1<<N); x++) {
            int q = __builtin_popcount(x);
            if (q != l) C_popcnt[l][x] = 0;
            else {
                C_popcnt[l][x] = (B[x] - C_popcnt[l][x])*inv;
                C[x] = C_popcnt[l][x];
            }
        }
        or_transform(N, C_popcnt[l]);
    }

    for (int i = 0; i <= N; i++) {
        delete[] A_popcnt[i];
        delete[] C_popcnt[i];
    }
    delete[] A_popcnt;
    delete[] C_popcnt;
}


// B = exp(A).
// Complexity: O(N2^N).
//
// For x != 0, it holds
// B[x] = \sum_{0 < y_1 < y_2 < ... < y_k: y_i disjoint, y_1|y_2|...|y_k = x}
//                    A[y_1]*A[y_2]*...*A[y_k].
// The value B[0] is (arbitrarily) set to 1.
//
// This operations is denoted exponential in analogy with the exponential of
// classical power-series. Indeed, a function on the subsets might also be
// interpreted as power series: the exponent is a subset and the coefficient
// is the values of the function for such subset.
// With this interpretation in mind, assuming that the multiplication is given
// by the subset_convolution, there is a pretty clear analogy between this
// operation and the classical exponential.
//
// ACHTUNG: The value of A[0] is ignored.
template<typename T>
void exp(int N, const T* A, T* B) {
    B[0] = 1;
    for (int n = 0; n < N; n++) 
        subset_convolution(n, A + (1<<n), B, B + (1<<n));
}

// exp(B) = A.
// Complexity: O(N2^N).
//
// The value of B[0] is (arbitrarily) set to 0.
//
// ACHTUNG: It must hold A[0] = 1.
template<typename T>
void log(int N, const T* A, T* B) {
    assert(A[0] == 1);
    B[0] = 0;
    for (int n = 0; n < N; n++)
        inverse_subset_convolution(n, A, A+(1<<n), B+(1<<n));
}

}; // namespace internal



// The class SubsetFunction<T> represents a function on the subsets of
// {0, 1, ..., N-1} with values in T.
// A subset is represented by its bitmask. If Subset<T> F is an instance, then
// the value of F on the subset x is F[x].
//
// With respect to copy and assignment, the class SubsetFunction behaves like
// a vector.
// 
// The following operations (see their headers in namespace::internal to know
// precisely what they do) are supported:
//  xor_transform                  // Complexity O(N2^N).
//  and_transform                  // Complexity O(N2^N).
//  or_transform                   // Complexity O(N2^N).
//
//  xor_convolution                // Complexity O(N2^N).
//  and_convolution                // Complexity O(N2^N).
//  or_convolution                 // Complexity O(N2^N).
//  subset_convolution             // Complexity O(N2^N).
//  inverse_subset_convolution     // Complexity O(N2^N).
//
//  complement                     // Complexity O(2^N).
//  exp                            // Complexity O(N2^N).
//  log                            // Complexity O(N2^N).
//
// The code that follows is mostly boiler-plate, as the heavy-lifting is
// performed in namespace::internal.
//
// Usage Example:
//  SubsetFunction<double> A(10);
//  for (int x = 0; x < (1<<10); x++) cin >> A[i];
//  auto B = xor_convolution(A, A);
//  auto C = inverse_subset_convolution(A, B);
//  auto D = log(exp(C));
//  for (int x = 1; x < (1<<10); x++) assert(abs(D[x] - C[x]) < 0.0001);
//  auto E = and_transform(A);
//  E = and_transform(E, true); // inverse transform
//  for (int x = 0; x < (1<<10); x++) assert(abs(E[x] - A[x]) < 0.0001);
template<typename T>
struct SubsetFunction {
    int N; // 1<<N is the size of arr.
    T* arr;
    SubsetFunction(int N): N(N) { // N >= 0
        arr = new T[1<<N];
        clear();
    }
    ~SubsetFunction() { delete[] arr; }
    SubsetFunction(const SubsetFunction& other) {
        N = other.N;
        arr = new T[1<<N];
        for (int x = 0; x < (1<<N); x++) arr[x] = other[x];
    }
    SubsetFunction& operator=(const SubsetFunction& other) {
        if (this != &other) {
            if (N != other.N) {
                N = other.N;
                delete[] arr;
                arr = new T[1<<N];
            }
            for (int x = 0; x < (1<<N); x++) arr[x] = other[x];
        }
        return *this;
    }
    T& operator[](int index) { return arr[index]; }
    const T& operator[](int index) const { return arr[index]; }
    void clear() { internal::clear(N, arr); }
};

#define TRANSFORM_DEF(OP)                                         \
template<typename T>                                              \
SubsetFunction<T> OP##_transform(const SubsetFunction<T>& A,      \
                                 bool inverse=false) {            \
    SubsetFunction<T> B = A;                                      \
    internal::OP##_transform(B.N, B.arr, inverse);                \
    return B;                                                     \
}                                                                 \

TRANSFORM_DEF(xor)
TRANSFORM_DEF(and)
TRANSFORM_DEF(or)

#define CONVOLUTION_DEF(OP)                                         \
template<typename T>                                                \
SubsetFunction<T> OP##_convolution(const SubsetFunction<T>& A,      \
                                   const SubsetFunction<T>& B) {    \
    assert(A.N == B.N);                                             \
    SubsetFunction<T> C(A.N);                                       \
    internal::OP##_convolution(A.N, A.arr, B.arr, C.arr);           \
    return C;                                                       \
}

CONVOLUTION_DEF(xor)
CONVOLUTION_DEF(and)
CONVOLUTION_DEF(or)
CONVOLUTION_DEF(subset)
CONVOLUTION_DEF(inverse_subset)

#define UNARY_OPERATOR_DEF(OP)                          \
template<typename T>                                    \
SubsetFunction<T> OP(const SubsetFunction<T>& A) {      \
    SubsetFunction<T> B(A.N);                           \
    internal::OP(A.N, A.arr, B.arr);                    \
    return B;                                           \
}

UNARY_OPERATOR_DEF(exp)
UNARY_OPERATOR_DEF(log)

template<typename T>
SubsetFunction<T> complement(const SubsetFunction<T>& A) {
    SubsetFunction<T> B(A);
    internal::complement(B.N, B.arr);
    return B;
}


#endif // SUBSETS_OPERATIONS



///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    mint::set_mod(998244353);
    // or-transform
    const int E = 26;
    int n;
    cin >> n;
    vector<vector<int>> A(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vector<int> vec(E);
        int it = 0;
        for (int c = 0; c < E; c++) {
            char z = 'a' + c;
            int q = 0;
            while (it < SZ(s) and s[it] == z) q++, it++;
            vec[c] = q;
        }    
        A[i] = vec;
    }

    vector<vector<int>> B0;
    B0.push_back(vector<int>(26, 1e6));
    vector<vector<int>> B1;
    B1.push_back(vector<int>(26, 1e6));

    int n1 = n/2;
    int n2 = n-n1;
    for (int bb = 1; bb < (1<<n1); bb++) {
        int i = 0;
        while (!(bb&(1<<i))) i++;
        vector<int> vec = B0[bb^(1<<i)];
        for (int c = 0; c < E; c++) vec[c] = min(vec[c], A[i][c]);
        B0.push_back(vec);
    }
    for (int bb = 1; bb < (1<<n2); bb++) {
        int i = 0;
        while (!(bb&(1<<i))) i++;
        vector<int> vec = B1[bb^(1<<i)];
        for (int c = 0; c < E; c++) vec[c] = min(vec[c], A[i + n1][c]);
        B1.push_back(vec);
    }

    SubsetFunction<mint> C(n);
    C[0] = 0;
    for (int bb = 1; bb < (1<<n); bb++) {
        const auto& x0 = B0[bb&((1<<n1)-1)];
        const auto& x1 = B1[bb>>n1];
        mint prod = 1;
        for (int c = 0; c < 26; c++) prod *= 1 + min(x0[c], x1[c]);
        C[bb] = prod;
        if (__builtin_popcount(bb) %  2 == 0) C[bb] = -C[bb];
    }
    SubsetFunction<mint> res = or_transform(C);

    LL ans = 0;
    for (int bb = 0; bb < (1<<n); bb++) {
        LL k = 0;
        LL sum = 0;
        for (int i = 0; i < n; i++) if (bb&(1<<i)) k++, sum += i+1;
        ans ^= k*sum*res[bb].get();
    }
    cout << ans << "\n";
}