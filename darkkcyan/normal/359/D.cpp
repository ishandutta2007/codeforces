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
#define print_op(...) ostream& operator<<(ostream& out, const __VA_ARGS__& u)
// DEBUGING TEMPLETE ////////////////////////////////////////////////////////////////////////{{{
// What? You wanted to see how this template works?  Check this out:
// https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html
#define db(val) "["#val" = "<<(val)<<"] "
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
#   define clog cerr << setw(__db_level * 2) << setfill(' ') << "" << setw(0)
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

template<class U, class V> print_op(pair<U, V>) {
    return out << "(" << u.first << ", " << u.second << ")";
}
template<class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type
operator<<(ostream& out, const Con& con) { 
    out << "{";
    for (auto beg = con.begin(), it = beg; it != con.end(); ++it)
        out << (it == beg ? "" : ", ") << *it;
    return out << "}";
}
template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")"; 
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup); 
}
template<class ...U> print_op(tuple<U...>) {
    return print_tuple_utils<0, tuple<U...>>(out, u);
}
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////}}}

struct BIT {
    vector<ll> g;
    BIT(int len): g(len + 10) {}
    void upd(int i, ll d) {
        for (++i; i < sz(g); i += i & -i) g[i] = __gcd(g[i], d);
    }
    
    ll get(int i) {
        ll ans = 0;
        for (++i; i > 0; i -= i & -i) ans = __gcd(ans, g[i]);
        return ans;
    }
};

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    
    vector<int> mx_left(n, -1), mx_right(n, n);
    BIT bit(n);
    rep(i, 0, n) {
        bit.upd(n - i - 1, a[i]);
        int l = 0, r = i;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (bit.get(n - 1 - i + mid) == a[i]) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        mx_left[i] = l;
    }
    bit = BIT(n);
    for (int i = n; i--; ) {
        bit.upd(i, a[i]);
        int l = 0, r = n - i - 1;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (bit.get(i + mid) == a[i]) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        mx_right[i] = l;
    }
    
    clog << db(mx_left) << endl;
    clog << db(mx_right) << endl;
    
    int mx_len = 0;
    vector<int> ans_pos;
    rep(i, 0, n) {
        int l = i - mx_left[i];
        int r = i + mx_right[i];
        int len = r - l + 1;
        if (len > mx_len) {
            mx_len = len;
            ans_pos.clear();
        }
        if (len == mx_len) ans_pos.push_back(l);
    }
    sort(all(ans_pos));
    ans_pos.erase(unique(all(ans_pos)), ans_pos.end());
    cout << sz(ans_pos) << ' ' << mx_len - 1  << '\n';
    for (auto i: ans_pos) cout << i + 1 << ' ';
    
    return 0;
}

// vim: foldmethod=marker