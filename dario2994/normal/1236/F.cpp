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

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////


struct Edge {
    int from, to;
};

vector<bool> used;
vector<Edge> edges;
vector<vector<int>> aa;
vector<vector<int>> v2c;
vector<vector<int>> c2v;
vector<bool> open; // vertices
vector<int> edges_stack;
vector<bool> in_cycle;
void dfs(int v) {
    open[v] = true;
    for (int i: aa[v]) {
        if (used[i]) continue;
        used[i] = used[i^1] = true;
        edges_stack.push_back(i);
        if (open[edges[i].to]) {
            // create cycle component
            int c = c2v.size();
            c2v.push_back({});
            for (int it = edges_stack.size()-1; it >= 0; it--) {
                int id = edges_stack[it];
                int u = edges[id].from;
                in_cycle[id] = true;
                c2v.back().push_back(u);
                v2c[u].push_back(c);
                if (u == edges[i].to) break;
            }
        } else dfs(edges[i].to);
        if (!in_cycle[i]) {
            // create bridge component
            int c = c2v.size();
            v2c[edges[i].from].push_back(c);
            v2c[edges[i].to].push_back(c);
            c2v.push_back({edges[i].from, edges[i].to});
        }
        edges_stack.pop_back();
    }
    open[v] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    mint::set_mod(1e9 + 7);

    int n, m;
    cin >> n >> m;

    vector<mint> E(m+1);
    vector<mint> E2(m+1);
    vector<mint> var(m+1);

    E[2] = mint(3) / 4;
    E2[2] = mint(1) / 2;
    var[2] = mint(3) / 16;

    mint _2 = mint(1) / 2, _4 = mint(1) / 4, _8 = mint(1) / 8, _16 = mint(1) / 16;
    mint pot = _8;
    for (int i = 3; i <= m; i++, pot *= _2) {
        E[i] = mint(i) * _4 + pot;
        E2[i] = mint(i) * _8 + pot;
        mint j = i;
        var[i] = (j*j + j) * _16 + pot - (j * _4 + pot) * (j * _4 + pot);
    }

    used.resize(2*m, false);
    v2c.resize(n);
    open.resize(n);
    aa.resize(n);
    in_cycle.resize(2*m, false);

    for (int i = 0; i < m; i++) {
        Edge e;
        cin >> e.from >> e.to;
        e.from--, e.to--;
        aa[e.from].push_back(edges.size());
        edges.push_back(e);
        swap(e.from, e.to);
        aa[e.from].push_back(edges.size());
        edges.push_back(e);
    }

    dfs(0);

    mint res1 = 0;
    mint res2 = 0;
    mint res3 = 0;
    mint res4 = 0;
    for (auto c: c2v) res1 += var[c.size()];
    for (int v = 0; v < n; v++) {
        mint q = v2c[v].size() - 1;
        res2 += q*q * _4;
    }

    auto mix_prod = [](const vector<mint>& A, const vector<mint>& B, const vector<int>& indexes) {
        mint sumA = 0;
        mint sumB = 0;
        mint sumAB = 0;
        for (int i: indexes) {
            sumA += A[i];
            sumB += B[i];
            sumAB += A[i] * B[i];
        }
        return sumA * sumB - sumAB;
    };

    for (int v = 0; v < n; v++) {
        vector<int> s;
        for (int c: v2c[v]) s.push_back(c2v[c].size());
        mint ris = 4 * mix_prod(E2, E2, s) + mix_prod(E, E, s) - 4 * mix_prod(E, E2, s);
        res3 += ris;
    }

    for (int v = 0; v < n; v++) {
        mint q = v2c[v].size() - 1;
        mint ris = 0;
        for (int c: v2c[v]) {
            int s = c2v[c].size();
            ris += E2[s] - E[s]/2;
        }
        res4 -= 2 * q * ris;
    }

    cout << res1 + res2 + res3 + res4 << "\n";
}