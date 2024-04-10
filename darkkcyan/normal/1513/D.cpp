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

const int maxn = 201010;
const int maxlg = 20;
int n, p;
int a[maxn];

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        DB();
        cin >> n >> p;
        rep(i, 0, n) cin >> a[i];
        
        vector<int> dsu(n, -1);
        int cnt_comp = n;
        function<int(int)> find_set = [&](int u) {
            return dsu[u] < 0 ? u : dsu[u] = find_set(dsu[u]);
        };
        
        auto join = [&](int u, int v) {
            u = find_set(u);
            v = find_set(v);
            if (u == v) return; 
            --cnt_comp;
            if (-dsu[u] < -dsu[v]) swap(u, v);
            dsu[u] += dsu[v];
            dsu[v] = u;
        };
        
        ll ans = 0;
        
        vector<pair<int, int>> vals;
        rep(i, 0, n) vals.emplace_back(a[i], i);
        sort(all(vals));
        for (auto [min_val, i]: vals) {
            if (min_val >= p) break;
            for (int f = i + 1; f < n and find_set(f) != find_set(i); ++f) {
                if (a[f] % min_val) break;
                ans += min_val;
                join(f, i);
            }
            for (int f = i - 1; f >= 0 and find_set(f) != find_set(i); --f) {
                if (a[f] % min_val) break;
                ans += min_val;
                join(f, i);
            }
        }
        ans += 1ll * p * (cnt_comp - 1);
        cout << ans << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker