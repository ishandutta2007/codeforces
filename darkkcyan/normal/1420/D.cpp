#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define rand __rand
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
template<class T = int> T rand(T range = numeric_limits<T>::max()) { return (T)(rng() % range); }

#define CONCAT_(x, y) x##y/*{{{*/
#define CONCAT(x, y) CONCAT_(x, y)
#define SPEC(name) CONCAT(name, __LINE__)
#ifdef LOCAL_DEBUG   
int __db_level = 0;
#define clog cerr << string(__db_level * 2, ' ')
struct debug_block {
    string msg;
    debug_block(const string& s): msg(s) { clog << "{ " << msg << endl; ++__db_level; }
    ~debug_block() { --__db_level; clog << "} " << msg << endl; }
};
#define DB(args...) stringstream SPEC(ss); SPEC(ss)<< args; debug_block SPEC(dbbl)(SPEC(ss).str())
#else
#define clog if (0) cerr
#define DB(...)
#endif
#define db(val) "[" #val " = " << val << "]; "
template<class U, class V> ostream& operator<<(ostream& out, const pair<U, V>& p) {
    return out << "(" << p.first << ", " << p.second << ")";
}
template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")";
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup);
}
template<class ...U>
ostream& operator<<(ostream& out, const tuple<U...>& tup) { return print_tuple_utils<0, tuple<U...>>(out, tup); }
template<class, typename = void> struct has_const_iterator : false_type {};
template<class T> struct has_const_iterator<T, void_t<typename T::const_iterator>> : true_type {};
template<class T>
typename enable_if<has_const_iterator<T>::value && !is_same<T, string>::value, ostream&>::type
operator<<(ostream& out, const T& container) { 
    auto beg = container.begin(), end = container.end();
    out << "(" << container.size() << ") {";
    if (beg != end) out << *(beg++);
    while (beg != end) out << ", " << *(beg++);
    return out << "}";
}
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> $v(u a, u b) { return vector<ptrtype(u)>(a, b); }/*}}}*/
// ACTUAL SOLUTION BELOW ////////////////////////////////////////////////////////////

constexpr bool testing = 0;
constexpr bool print_brute = 0;

int ntest = testing ? 1000 : 1; 
const int maxn = 301010;
const llong mod = 998244353;

llong mpow(llong base, llong exp) {
    llong ans = 1;
    for (; exp > 0; exp >>= 1) {
        if (exp & 1) (ans *= base) %= mod;
        (base *= base) %= mod;
    }
    return ans;
}

const int fac_len = maxn * 2;
llong fac[fac_len], ifac[fac_len];
void cal_fac() {
    fac[0] = ifac[0] = 1;
    rep1(i, fac_len - 1) {
        fac[i] = fac[i - 1] * i % mod;
        ifac[i] = mpow(fac[i], mod - 2);
    }
}

llong choose(int n, int k) {
    // clog << db(n) << db(k) << endl; 
    if (k < 0 or n < 0 or k > n) return 0;
    return fac[n] * ifac[k] % mod * ifac[n - k] % mod;
}

int n, k;
pair<int, int> ranges[maxn];

void read() {
    if constexpr(!testing) {
        cin >> n >> k;
        rep(i, n) cin >> ranges[i].first >> ranges[i].second;
    } else {
        n = 5;
        k = rand(n) + 1;
        rep(i, n) {
            ranges[i].first = rand(20) + 1;
            ranges[i].second= rand(20) + 1;
            if (ranges[i].first > ranges[i].second)
                swap(ranges[i].first, ranges[i].second);
        }
        ofstream inp("main.inp");
        inp << n << ' ' << k << endl;
        rep(i, n) inp << ranges[i].first << ' ' << ranges[i].second << '\n';
    }
}

llong brute_solve() {
    llong ans = 0;
    vector<int> picked;
    function<void(int, int, pair<int, int>)> check =
        [&](int i, int cnt, pair<int, int> rg) {
            if (cnt == k) {
                ++ans;
                clog << db(picked) << endl;
                if (ans >= mod) ans -= mod;
                return ;
            }
            if (i >= n) return ;
            check(i + 1, cnt, rg);
            if (rg.first > ranges[i].second or ranges[i].first > rg.second) return ;
            rg.first = max(rg.first, ranges[i].first);
            rg.second = min(rg.second, ranges[i].second);
            picked.push_back(i);
            check(i + 1, cnt + 1, rg);
            picked.pop_back();
        };
    check(0, 0, {INT_MIN, INT_MAX});
    return ans;
}

llong solve() {
    map<int, int> add, rem;
    vector<int> moments;
    rep(i, n) {
        add[ranges[i].first]++;
        rem[ranges[i].second + 1] ++;
        moments.push_back(ranges[i].first);
        moments.push_back(ranges[i].second + 1);
    }
    
    sort(moments.begin(), moments.end());
    moments.erase(unique(moments.begin(), moments.end()), moments.end());
    
    int prev = 0;
    llong ans = 0;
    for (auto t: moments) {
        int cur_add = add[t], cur_rem = rem[t];
        int base = prev - cur_rem;
        int cur = base + cur_add;
        ans += choose(cur, k) - choose(base, k);
        while (ans >= mod) ans -= mod;
        while (ans < 0) ans += mod;
        clog << db(t) << db(ans) << db(cur_add) << db(cur_rem) << endl;
        prev = cur;
    }
    return ans;
}

int main(void) {
    cal_fac();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    while (ntest--) {
        read();
        if constexpr (testing) {
            llong u = solve(), v = brute_solve();
            assert(u == v);
        } else {
            cout << solve() << '\n';
            if constexpr(print_brute) cout << brute_solve() << '\n';
        }
    }
    

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker