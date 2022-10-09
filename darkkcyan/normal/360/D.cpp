#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (int)(a); i < (int)(b); ++i) 
#define all(a) (a).begin(), (a).end()
// #define constexpr(...) (__VA_ARGS__)  
// DEBUGING TEMPLETE ////////////////////////////////////////////////////////////////////////{{{
#define db(val) "["#val" = "<<(val)<<"] "
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
#   define clog cerr << flush << string(__db_level * 2, ' ')
#   define DB() debug_block CONCAT(dbbl, __LINE__)
    int __db_level = 0;
    struct debug_block {
        debug_block() { clog << "{" << endl; ++__db_level; }
        ~debug_block() { --__db_level; clog << "}" << endl; }
    };
#else
#   define clog if (0) cerr
#   define DB(...)
#endif

template<class U, class V> ostream& operator<<(ostream& out, const pair<U, V>& p) {
    return out << "(" << p.first << ", " << p.second << ")";
}

template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")"; 
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup); 
}

template<class ...U> ostream& operator<<(ostream& out, const tuple<U...>& tup) {
    return print_tuple_utils<0, tuple<U...>>(out, tup);
}

template<class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type
operator<<(ostream& out, const Con& container) { 
    out << "{";
    for (auto it = container.begin(); it != container.end(); ++it)
        out << (it == container.begin() ? "" : ", ") << *it;
    return out << "}";
}
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////}}}

int add(int a, int b, int mod) {
    if ((a += b) >= mod) a -= mod;
    return a;
}

int sub(int a, int b, int mod) {
    if ((a -= b) < 0) a += mod;
    return a;
}

int mul(int a, int b, int mod) { return (int)(1ll * a * b % mod); }

int mpow(int base, ll exp, int mod) {
    int ans = 1;
    for (; exp > 0; exp >>= 1, base = mul(base, base, mod))
        if (exp & 1) ans = mul(ans, base, mod);
    return ans;
}

vector<int> find_divs(int num) {
    vector<int> head, tail;
    for (int i = 1; i * i <= num; ++i) {
        if (num % i == 0) {
            head.push_back(i);
            if (i * i != num) tail.push_back(num / i);
        }
    }
    head.insert(head.end(), tail.rbegin(), tail.rend());
    return head;
}



int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> a(n), b(m);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];
    
    int t = p - 1;
    rep(i, 0, m) t = __gcd(t, b[i]);
    
    clog << db(t) << endl;
    
    auto divs = find_divs(p - 1);
    clog << db(divs) << endl;
    vector<int> prime_divs;
    {
        int num = p - 1;
        for (auto i: divs) {
            if (i == 1) continue;
            if (num % i == 0) {
                prime_divs.push_back(i);
                while (num % i == 0) num /= i;
            }
        }
    }
    clog << db(prime_divs) << endl;
    
    unordered_map<int, vector<int>> dd, md;  //  divisors of divisors, multiple of divisors
    unordered_map<int, int> pdd;
    for (int i = sz(prime_divs); i--; ) {
        int u = prime_divs[i];
        for (auto f: divs) if (f % u == 0) {
            pdd[f] = u;
            md[u].push_back(f);
        }
    }
    clog << db(pdd) << endl;
    
    for (auto i: divs) {
        for (auto f: divs) if (f % i == 0) dd[f].push_back(i);
    }
    
    vector<int> d(n);
    transform(all(a), d.begin(), [&](int x) {
        DB();
        clog << db(x) << endl;
        if (x == 1) return 1;
        unordered_map<int, int> pw;
        pw[1] = x;
        
        for (auto ans: divs) {
            if (ans == 1) continue;
            clog << db(ans) << endl;
            auto u = pdd[ans], v = ans / u;
            auto cur_pow  = mpow(pw[v], u, p);
            clog << db(cur_pow) << endl;
            if (cur_pow == 1) return ans;
            pw[ans] = cur_pow;
        }
        assert(false);
        return -1;
    });
    
    clog << db(d) << endl;
    
    set<int> has;
    int new_p = (p - 1) / t;
    for (auto i: d) {
        int q = __gcd((p - 1) / i, new_p);
        has.insert(q);
    }
    
    auto new_divs = find_divs(new_p);
    vector<ll> dp(sz(new_divs));
    
    rep(i, 0, sz(new_divs)) {
        if (has.count(new_divs[i])) continue;
        rep(f, 0, i) {
            if (new_divs[i] % new_divs[f]) continue;
            if (has.count(new_divs[f])) {
                has.insert(new_divs[i]);
                break;
            }
        }
    }
    
    for (int i = sz(new_divs); i--; ) {
        if (!has.count(new_divs[i])) continue;
        
        dp[i] = new_p / new_divs[i];
        rep(f, i + 1, sz(new_divs)) {
            if (new_divs[f] % new_divs[i]) continue;
            dp[i] -= dp[f];
        }
    }
    cout << accumulate(all(dp), 0ll) << endl;
    
    
    return 0;
}

// vim: foldmethod=marker