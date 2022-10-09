#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const ld eps = 1e-8;
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
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

const ll inf = (ll)1e13;
struct IT {
    vector<ll> vals;
    int sz;
    IT(int sz_) : vals(sz_ * 2, inf), sz(sz_) {}
    void am(int pos, ll val) { vals[pos] = min(vals[pos], val); }
    void set_min(int l, int r, ll val) {
        for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
            if (l & 1) am(l++, val);
            if (r & 1) am(--r, val);
        }
    }
    vector<ll> extract() {
        rep1(i, len(vals) - 1) {
            if (2 * i < len(vals)) am(2 * i, vals[i]);
            if (2 * i + 1 < len(vals)) am(2 * i + 1, vals[i]);
        }
        return vector<ll>(vals.begin() + sz, vals.end());
    }
};

vector<ll> arr[4];

int main(void) {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    rep(i, 4) {
        int n; cin >> n;
        arr[i].resize(n);
    }
    rep(i, 4) {
        for (auto& x: arr[i]) cin >>x;
    }
    
    vector<ll> prev_min(len(arr[0]), 0);
    rep(i, 3) {
        DB();
        clog << db(i) <<endl ;
        int m; cin >> m;
        IT it(len(arr[i + 1]));
        vector<vector<int>> pos(len(arr[i]));
        while (m--) {
            int u, v; cin >> u >> v;
            pos[--u].push_back(--v);
        }
        
        rep(u, len(arr[i])) {
            DB();
            clog << db(u) << endl;
            sort(pos[u].begin(), pos[u].end());
            ll cur = prev_min[u] + arr[i][u];
            clog << db(cur) << endl;
            auto do_assign = [&](int l, int r) {
                if (l >= r) return ;
                clog << db(l) << ' ' << db(r) << endl;
                it.set_min(l, r, cur);
            };
            int prev = 0;
            for (auto p: pos[u]) {
                do_assign(prev, p);
                prev = p + 1;
            }
            do_assign(prev, len(arr[i + 1]));
        }
        
        prev_min = it.extract();
        clog << db(prev_min) << endl;
    }
    
    ll ans = inf;
    rep(i, len(arr[3])) {
        ans = min(ans, arr[3][i] + prev_min[i]);
    }
    if (ans >= inf) cout << "-1";
    else cout << ans;
    
    return 0;
}

// vim: foldmethod=marker