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

optional<vector<vector<int>>> try_fill(int n, const vector<pair<int, int>>& cnt) {
    DB();
    clog << db(n) << endl;
    list<pair<int, int>> g1, g2, g3;
    vector<vector<int>> ans(n, vector<int>(n));
    auto add_inrange = [&](list<pair<int, int>>& g, int u, int v) {
        if (u < n and v < n) g.emplace_back(u, v);
    };
    for (int i = 0; i < n + 1; i += 2)
        for (int f = 0; f < n + 1; f += 2) {
            add_inrange(g2, i, f);
            add_inrange(g1, i + 1, f);
            add_inrange(g3, i, f + 1);
        }
    
    g1.splice(g1.end(), g2);
    g1.splice(g1.end(), g3);
    
    auto ptr = g1.begin();
    for (auto [c, id]: cnt) {
        while (c--) {
            if (ptr == g1.end()) return {};
            ans[ptr->first][ptr->second] = id;
            ++ptr;
        }
    }
    
    rep(i, 0, n - 1) rep(f, 0, n) {
        if (ans[i][f] == 0) continue;
        if (f + 1 < n and ans[i + 1][f + 1] and ans[i][f] == ans[i + 1][f + 1]) return {};
        if (f and ans[i + 1][f - 1] and ans[i][f] == ans[i + 1][f - 1]) return {};
    }
    clog << db("ok" )<< endl;
    return {ans};
}

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
        int m, k; cin >> m >> k;
        vector<pair<int, int>> cnt(k);
        rep(i, 0, k) {
            cin >> cnt[i].first;
            cnt[i].second = i + 1;
        }
        sort(all(cnt), greater<>());
        int lo = 1, hi = 1;
        while (!try_fill(hi, cnt)) hi <<= 1;
        clog << db(lo) << db(hi) << endl;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (try_fill(mid, cnt)) hi = mid;
            else lo = mid + 1;
        }
        auto ans = try_fill(lo, cnt);
        cout << lo << '\n';
        rep(i, 0, lo) {
            rep(f, 0, lo) cout << (*ans)[i][f] << ' ';
            cout << '\n';
        }
    }
    
    return 0;
}

// vim: foldmethod=marker