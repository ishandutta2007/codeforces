#include <bits/stdc++.h>
using namespace std;

#define def_op(op, uop, body) \
    inline self_t& operator uop(const self_t& o) { body; return *this; } \
    friend inline self_t operator op (self_t lhs, const self_t & rhs) { return lhs uop rhs; }
#define def_cmp_op(op, body) friend inline bool operator op(const self_t& u, const self_t& v) { return body; }
template<int mod>
struct ModInt {
    using self_t = ModInt<mod>;
    int x;
    ModInt(): x(0) {}
    ModInt(int v): x(v >= mod ? v - mod : v < 0 ? v + mod : v) {}
    ModInt(long long v): ModInt((int)(v % mod)) {}
    def_op(+, +=, {x += o.x; if (x >= mod) x -= mod;})
    def_op(-, -=, {x -= o.x; if (x < 0) x += mod;}) 
    def_op(*, *= , {x = (int)(1ll * x * o.x % mod); })
    def_op(/, /=, {x = o.pow(mod - 2, x).x; })
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

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#ifdef testing/*{{{*/
mt19937 rng(177013);
#else
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
#endif
#define rand() (int)(rng() >> 1)
#define CONCAT_(x, y) x##y
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
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////

int n, k, q;

vector<vector<mod_int>> cnt_way;
vector<mod_int> a, acc_way;

int main(void) {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k >> q;
    a.resize(n);
    rep(i, n) {
        int num; cin >> num;
        a[i] = mod_int(num);
    }
    
    cnt_way.resize(k + 1);
    cnt_way[0].assign(n, 1);
    
    rep1(cnt_time, k) {
        cnt_way[cnt_time].resize(n);
        rep(i, n - 1) {
            cnt_way[cnt_time][i + 1] += cnt_way[cnt_time - 1][i];
            cnt_way[cnt_time][i] += cnt_way[cnt_time - 1][i + 1];
        }
    }
    acc_way.resize(n);
    rep(i, n) {
        rep(pref, k + 1) {
            int suff = k - pref;
            acc_way[i] += cnt_way[pref][i] * cnt_way[suff][i];
        }
    }
    clog << db(acc_way) << endl;
    mod_int ans;
    rep(i, n) ans += acc_way[i] * a[i];
    
    while (q--) {
        int p, x; cin >> p >> x;
        --p;
        ans -= acc_way[p] * a[p];
        a[p] = mod_int(x);
        ans += acc_way[p] * a[p];
        cout << ans << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker