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


const int maxn = 333; 
int n, m;
int a[maxn * maxn];

struct BIT {
    vector<int> data;
    BIT() = default;
    BIT(int len): data(len + 10) {}
    void upd(int i, int d) {
        for (++i; i < sz(data); i += i & -i) data[i] += d;
    }
    int get(int i) {
        int ans = 0;
        for (++i; i > 0; i -= i & -i) ans += data[i];
        return ans;
    }
};

ll solve_n1() {
    vector<int> values(a, a + m);
    sort(all(values));
    values.erase(unique(all(values)), values.end());
    
    BIT bit(m + 1);
    ll ans = 0;
    rep(i, 0, m) {
        int id = (int)(lower_bound(all(values), a[i]) - values.begin());
        ans += bit.get(id - 1);
        bit.upd(id, 1);
    }
    return ans;
}

ll solve_n2() {
    vector<pair<int, int>> s;
    rep(i, 0, n * m) {
        s.emplace_back(a[i], i);
    }
    sort(all(s));
    
    vector<pair<int, int>> seat(n * m);
    
    for (int i = 0; i < n * m; ) {
        int f = i;
        while (f < n * m and s[i].first == s[f].first) ++f;
        
        vector<pair<int, int>> cur_seats;
        rep(g, i, f) cur_seats.emplace_back(g / m, g % m);
        sort(all(cur_seats), [&](const pair<int, int>& u, const pair<int, int>& v) {
                if (u.first == v.first) return u.second > v.second;
                return u.first < v.first;
                });
        
        rep(g, i, f) seat[s[g].second] = cur_seats[g - i];
        i = f;
    }
    
    vector<BIT> rows(n, m);
    ll ans = 0;
    rep(i, 0, n * m) {
        auto [r, c] = seat[i];
        ans += rows[r].get(c);
        rows[r].upd(c, 1);
    }
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    int ntest; cin >> ntest;
    while (ntest--) {
        cin >> n >>m;
        rep(i, 0, n * m) cin >> a[i];
        cout << solve_n2() << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker