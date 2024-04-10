#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef __uint128_t ULLL; 
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

// Overloading of the operator << for __int128 type.
ostream& operator <<(ostream& out, __uint128_t x) {
    static short int digits[41];
    if (x == 0) {
        out << '0';
        return out;
    }
    int length = 0;
    for (; x > 0; x /= 10) {
        digits[length] = x % 10;
        length++;
    }
    for (int i = length - 1; i >= 0; i--) out << digits[i];
    return out;
}

istream& operator >>(istream& in, ULLL& x) {
    x = 0;
    
    char ch = in.get();
    while (ch < '0' or '9' < ch) ch = in.get();

    while ('0' <= ch and ch <= '9') {
        x = x * 10 + ch - '0';
        ch = in.get();
    }
    
    return in;
}


///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

ULLL gcdulll(ULLL x, ULLL y) {
    if (x > y) swap(x, y);
    while (x != 0) y %= x, swap(x, y);
    return y;
}

vector<ULLL> split(vector<ULLL> primes, ULLL& n) {
    vector<ULLL> new_primes;
    for (ULLL p: primes) {
        while (n % p == 0) n /= p;
        ULLL g = gcdulll(p, n);
        if (g == 1) {
            new_primes.push_back(p);
            continue;
        }
        vector<ULLL> vec = split({g}, p);
        if (p != 1) vec.push_back(p);
        vector<ULLL> vec2 = split(vec, n);
        for (ULLL q: vec2) new_primes.push_back(q);
    }
    return new_primes;
}

void solve(int n, int m, vector<ULLL> a, vector<ULLL> b) {
    vector<ULLL> primes;
    auto process = [&](ULLL z) {
        primes = split(primes, z);
        if (z != 1) primes.push_back(z);
    };

    for (int i = 0; i < n; i++) process(a[i]);
    for (int i = 0; i < m; i++) process(b[i]);
    
    auto factor = [&](ULLL z) {
        map<int,int> fact;
        for (int i = 0; i < SZ(primes); i++) {
            ULLL p = primes[i];
            int e = 0;
            while (z % p == 0) e++, z /= p;
            if (e > 0) fact[i] = e;
        }
        assert(z == 1);
        return fact;
    };
    
    vector<map<int,int>> a2(n), b2(m);
    for (int i = 0; i < n; i++) a2[i] = factor(a[i]);
    for (int i = 0; i < m; i++) b2[i] = factor(b[i]);

    vector<bool> a_alive(n, true), b_alive(m, true);

    while (1) {
        bool changed = false;
        for (int _ = 0; _ < 2; _++) {
            map<int,int> alcm;
            for (int i = 0; i < n; i++) {
                if (a_alive[i]) {
                    for (const auto& pp: a2[i]) {
                        alcm[pp.first] = max(alcm[pp.first], pp.second);
                    }
                }
            }

            for (int i = 0; i < m; i++) {
                if (!b_alive[i]) continue;
                bool ok = true;
                for (auto pp: b2[i]) ok &= pp.second <= alcm[pp.first];
                if (!ok) {
                    b_alive[i] = false;
                    changed = true;
                }
            }
            
            swap(n, m);
            swap(a2, b2);
            swap(a_alive, b_alive);
        }
        if (!changed) break;
    }

    vector<ULLL> ares;
    vector<ULLL> bres;
    for (int i = 0; i < n; i++) if (a_alive[i]) ares.push_back(a[i]);
    for (int i = 0; i < m; i++) if (b_alive[i]) bres.push_back(b[i]);

    if (ares.empty() or bres.empty()) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << ares.size() << " " << bres.size() << "\n";
    for (ULLL x: ares) cout << x << " ";
    cout << "\n";
    for (ULLL x: bres) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int t;
    cin >> t;
    // t = 1000;
    while (t--) {
        int n, m;
        cin >> n >> m;
        // n = randint(1, 5), m = randint(1, 5);
        vector<ULLL> a(n), b(m);

        // auto randval = [&]() {
            // const static vector<ULLL> primes = {2, 3, 5, 7, 11, 13, 17};
            // ULLL z = 1;
            // while (z < 1e35) z *= primes[randint(0, 6)];
            // return z;
        // };

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        // for (int i = 0; i < n; i++) a[i] = randval();
        // for (int i = 0; i < m; i++) b[i] = randval();

        solve(n, m, a, b);
    }
}