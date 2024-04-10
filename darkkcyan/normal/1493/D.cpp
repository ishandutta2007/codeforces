#include <bits/stdc++.h>
using namespace std;

#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#define def_op(op, uop) \
    inline self_t& operator uop(const self_t& o) { CONCAT(op_helper, __LINE__)(o); return *this; } \
    friend inline self_t operator op (self_t lhs, const self_t & rhs) { return lhs uop rhs; } \
    inline void CONCAT(op_helper, __LINE__)(const self_t& o)
#define def_cmp_op(op, body) friend inline bool operator op(const self_t& u, const self_t& v) { return body; }
template<int mod>
struct ModInt {
    using self_t = ModInt<mod>;
    int x;
    ModInt(): x(0) {}
    ModInt(int v): x(v >= mod ? v - mod : v < 0 ? v + mod : v) {}
    ModInt(long long v): ModInt((int)(v % mod)) {}
    def_op(+, +=) {x += o.x; if (x >= mod) x -= mod;}
    def_op(-, -=) {x -= o.x; if (x < 0) x += mod;}
    def_op(*, *=) {x = (int)(1ll * x * o.x % mod); }
    def_op(/, /=) {x = o.pow(mod - 2, x).x; }
    self_t pow(long long exp, self_t ans = 1) const {
        self_t base = *this;
        for (; exp > 0; exp >>= 1) {
            if (exp & 1) ans *= base;
            base *= base;
        }
        return ans;
    }
    def_cmp_op(==, u.x == v.x;)
    def_cmp_op(!=, u.x != v.x;) 
    def_cmp_op(<, u.x < v.x;) 
    friend ostream& operator<<(ostream& out, const self_t& u) { return out << u.x; }
};

using mod_int = ModInt<(int)1e9 + 7>;

using ll = long long;
using ld = long double;
const ld eps = 1e-8;
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define be(a) (a).begin(), (a).end()
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

const int maxn = 201010;
int pfac[maxn];
void sieve() {
    pfac[1] = 1;
    for (int i = 2; i < maxn; ++i) {
        if (pfac[i]) continue;
        for (int f = i; f < maxn; f += i) pfac[f] = i;
    }
}

vector<int> factorize(int num) {
    vector<int> ans; 
    while (num > 1) {
        int p = pfac[num];
        ans.push_back(p);
        num /= p;
    }
    return ans;
}

map<int, int> cnt[maxn];
int cnt_a[maxn];
multiset<int> prio[maxn];
int n;

mod_int ans = 1;

void add(int i, int x) {
    for (auto f: factorize(x)) {
        if (cnt_a[f] == n) {
            ans /= mod_int(f).pow(*prio[f].begin());
        }
        auto& cur = cnt[i][f];
        if (!cur) {
            ++cnt_a[f];
        } else {
            auto it = prio[f].find(cur);
            prio[f].erase(it);
        }
        clog << db(i) << db(f) << db(cnt_a[f]) << endl;
        ++cur;
        prio[f].insert(cur);
        clog << db(prio[f]) << endl;
        if (cnt_a[f] == n) ans *= mod_int(f).pow(*prio[f].begin());
    }
}

int main(void) {
    sieve();
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin >> n >> q;
    rep(i, n) {
        int x; cin >> x;
        add(i, x);
        clog << db(ans) << endl;
    }
    while (q--){
        int p;
        int x;
        cin >> p >> x;
        add(p - 1, x);
        cout << ans << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker