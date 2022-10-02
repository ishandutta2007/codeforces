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

// Computes (a*b) % mod avoiding integer overflow.
// Assumption: mod < 2**61.
ULL BigModMultiplication(ULL a, ULL b, ULL mod) {
    return ((__uint128_t)a * b) % mod;
    
    // The following code should be used only if __uint128 is not available.
    a %= mod, b %= mod;
    ULL res = 0;
    while (a > 0) {
        if (a & 1) res += b;
        a >>= 1;
        b <<= 1;
        b %= mod;
        res %= mod;
    }
    return res;
}

// Computes (x**e) % mod avoiding integer overflow.
// Assumption: mod < 2**61.
ULL BigModPower(ULL x, ULL e, ULL mod) {
    ULL res = 1;
    while (e) {
        if (e & 1) res = BigModMultiplication(res, x, mod);
        e >>= 1;
        x = BigModMultiplication(x, x, mod);
    }
    return res;
}

// Primality test, returns true iff p is prime.
// It implements Miller-Rabin algorithm (with some optimizations).
// Assumptions:  0 <= p <= 2**61.
// In order to support p > 1e9 it uses BigModMultiplication and BigModPower.
bool IsPrime(ULL p) {
    if (p <= 1) return false;
    static const ULL first_primes[21] = {2, 3, 5, 7, 11, 13, 17, 19, 23,
                                         29, 31, 37, 41, 43, 47, 53, 59,
                                         61, 67, 71, 73};
    // Checking the divisibility by the first 21 primes.
    for (int i = 0; i < 21; i++) {
        if (p % first_primes[i]== 0) {
            if (p == first_primes[i]) return true;
            return false;
        }
    }

    ULL x = p-1;
    int e = 0;
    while (x % 2 == 0) {
        x >>= 1;
        e++;
    }

    static const map<ULL, int> primes_to_check_table = {
        {2047, 1}, {1373653, 2}, {25326001, 3}, {3215031751ULL, 4},
        {2152302898747ULL, 5}, {3474749660383ULL, 6}, {341550071728321ULL, 7},
        {3825123056546413051ULL, 9}, {1ll<<62, 21}};
    int primes_to_check_num = primes_to_check_table.upper_bound(p)->second;

    for (int i = 0; i < primes_to_check_num; i++) {
        bool composite = true;
        ULL temp = BigModPower(first_primes[i], x, p);
        if (temp != 1 and temp != p-1) {
            for (int k = 0; k < e; k++) {
                temp = BigModMultiplication(temp, temp, p);
                if (temp == p-1) {
                    composite = false;
                    break;
                }
            }
        }
        else composite = false;
        if (composite) return false;
    }
    return true;
}

// Implementation of Pollard-Rho algorithm to find a nontrivial factor
// of n. As cycle-detection method, Brent's algorithm is used.
// The expected running time is O(sqrt(p)*log(n)) where p is the smallest prime
// factor of n.
// Assumption: n > 1 is not a prime.
ULL FindFactor(ULL n) {
    static mt19937_64 gen;
    while (1) {
        ULL x = uniform_int_distribution<ULL>(1, n-1)(gen);
        ULL y = x;
        auto next_x = [&x, n]() { x = (BigModMultiplication(x, x, n)+1) % n; };
        ULL res = 1;
        for (int sz = 2; res == 1; sz<<=1) {
            for (int i = 0; i < sz && res == 1; i++) {
                next_x();
                res = __gcd(n+x-y, n);
                if (res != 1 and res != n) {
                    return res;
                }
            }
            y = x;
        }
    }
}

// TODO: This must be tested.
// Returns the factorization of n.
// The returned vector contains pairs (p, e) so that:
//  - The values of p are strictly increasing.
//  - The values of p are primes.
//  - It holds e > 0.
//  - Product of p**e = n.
//
// Assumptions: 1 <= n < 2**61.
vector<pair<ULL,int>> factorization(ULL n) {
    if (n == 1) return {};
    if (IsPrime(n)) return {{n, 1}};
    ULL x = FindFactor(n);
    vector<pair<ULL,int>> a = factorization(x);
    vector<pair<ULL,int>> b = factorization(n/x);

    // Merging a and b.
    sort(all(a));
    sort(all(b));
    vector<pair<ULL,int>> res;
    auto add = [&](pair<ULL,int> p) {
        if (!res.empty() and res.back().first == p.first)
            res.back().second += p.second;
        else res.push_back(p);
    };
    int ita = 0, itb = 0;
    while (ita < SZ(a) and itb < SZ(b)) {
        if (a[ita] < b[itb]) add(a[ita++]);
        else add(b[itb++]);
    }
    while (ita < SZ(a)) add(a[ita++]);
    while (itb < SZ(b)) add(b[itb++]);
    return res;
}

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

const int MAXN = 1e5;
bool is_comp[MAXN];
vector<ULL> primes;

LL solve() {
    ULL n;
    cin >> n;
    auto is_valid = [&](ULL d) {
        if (d > 1.5e9) return false;
        return (d*(d+1))/2 <= n;
    };
    
    ULL pot2 = 2;
    while (n % pot2 == 0) pot2 *= 2;

    if (is_valid(pot2)) return pot2;

    ULL m = (2*n) / pot2;
    auto fact = factorization(m);
    if (fact.empty()) return -1;
    if (is_valid(fact[0].first)) return fact[0].first;
    // for (ULL p: primes) {
        // if (p*p > m) break;
        // if (m % p) continue;
        // if (is_valid(p)) return p;
        // while (m%p) m /= p;
    // }
    // if (m != 1 and is_valid(m)) return m;
    return -1;
}

int main() {

    // for (int p = 2; p < MAXN; p++) {
        // if (is_comp[p]) continue;
        // if (p > 2) primes.push_back(p);
        // for (int i = 2*p; i < MAXN; i += p) is_comp[i] = false;
    // }
    
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int t;
    cin >> t;
    while (t--) cout << solve() << "\n";
}