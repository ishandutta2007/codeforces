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

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////


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

int slowf[100];
void slow(int b, int dep, int len) {
    for (int i = 0; i < len-2; i++) {
        if ((b&(1<<i)) and (b&(1<<(i+2)))) b |= 1<<(i+1);
    }
    if (b == (1<<len)-1) {
        slowf[dep]++;
        return;
    }
    for (int i = 0; i < len; i++) {
        if (!(b&(1<<i))) slow(b|(1<<i), dep+1, len);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int n, M;
    cin >> n >> M;
    mint::set_mod(M);
    vector<vector<mint>> binom(n+1, vector<mint>(n+1, 0));
    for (int i = 0; i <= n; i++) {
        binom[i][0] = 1;
        for (int j = 1; j <= i; j++) binom[i][j] = binom[i-1][j] + binom[i-1][j-1];
    }
    vector<mint> p2(n+1);
    p2[0] = 1;
    for (int k = 1; k <= n; k++) p2[k] = p2[k-1]*2;
    vector<vector<mint>> f(n+1, vector<mint>(n+1,0));
    for (int t = 1; t <= n; t++) {
        for (int k = 1; k <= t-1; k++) {
            for (int h = 1; h <= k; h++) {
                f[t][k] += f[t-h-1][k-h] * p2[h-1] * binom[k][h];
            }
        }
        f[t][t] = p2[t-1];
    }
    mint res = 0;
    for (int k = 1; k <= n; k++) res += f[n][k];
    cout << res << "\n";

    // slow(0, 0, n);
    // for (int k = 1; k <= n; k++) cout << f[n][k] << " " << slowf[k] << endl;
}