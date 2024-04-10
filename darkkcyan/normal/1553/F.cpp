#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

// #define constexpr(...) (__VA_ARGS__)  
using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (int)(a); i < (int)(b); ++i) 
#define all(a) (a).begin(), (a).end()
#define print_op(type) ostream& operator<<(ostream& out, const type& u)
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

template<class T>
struct BIT {
    vector<T> val;
    BIT(int len): val(len + 10) {}
    T get(int i) {
        T ans = T();
        for (++i; i > 0; i -= i & -i) ans += val[i];
        return ans;
    }
    void upd(int i, T u) {
        for (++i; i < sz(val); i += i & -i) val[i] += u;
    }
    
    T get(int l, int r) {
        l = min(l, sz(val));
        r = min(r, sz(val));
        return get(r) - get(l - 1);
    }
};

const int maxn = 201010;
const int maxval = 301010;
const int bs = 550;
template<class T>
struct DS {
    vector<T> val, buck;
    T sum_all;
    DS(int len): val(len + 10), buck(len / bs + 10), sum_all(0) {}
    
    T get(int i) {
        if (i < 0) return 0;
        if (i >= sz(val)) return sum_all;
        int bi = i / bs;
        return buck[bi] + val[i];
    }
    
    void upd(int i, T u) {
        int bi = i / bs;
        for (int f = bi + 1; f < sz(buck); ++f) buck[f] += u;
        for (int f = i; f < (bi + 1) * bs and f < sz(val); ++f)
            val[f] += u;
        sum_all += u;
    }
    
    T get(int l, int r) {
        return get(r) - get(l - 1);
    }
};

int n;
int a[maxn];
vector<ll> solve() {
    DS<int> cnt_bit(maxval);
    DS<ll> sum_bit(maxval);
    
    vector<ll> ans;
    ll final_ans = 0;
    rep(pos, 0, n) {
        DB();
        int u = a[pos];
        clog << db(pos) << db(u) << endl;
        ll cur_ans = 0;
        for (int i = 1; i * u <= maxval; ++i) {
            cur_ans += sum_bit.get(i * u, (i + 1) * u - 1) - 1ll * i * u * cnt_bit.get(i * u, (i + 1) * u - 1);
        }
        clog << db(cur_ans) << endl;
        
        for (int q = 1; q <= u; ) {
            int last_b = u / q;
            int first_b = u / (q + 1) + 1;
            cur_ans += 1ll * u * cnt_bit.get(first_b, last_b) - 1ll * sum_bit.get(first_b, last_b) * q;
            if (first_b == 1) break;
            q = u / (first_b - 1);
        }
        
        cur_ans += 1ll * u * cnt_bit.get(u, maxval);
        cur_ans += sum_bit.get(0, u);
        cnt_bit.upd(u, 1);
        sum_bit.upd(u, u);
        ans.push_back(final_ans += cur_ans);
    }
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    rep(i, 0, n) cin >> a[i];
    auto ans = solve();
    for (auto i: ans) {
        cout << i << ' ';
    }
    
    
    return 0;
}

// vim: foldmethod=marker