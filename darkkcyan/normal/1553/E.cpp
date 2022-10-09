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

struct DSU {
    vector<int> par;
    int cnt_comp;
    DSU(int len): par(len, -1), cnt_comp(len) {}
    int find_set(int u) {
        return par[u] < 0 ? u : par[u] = find_set(par[u]);
    }
    void join(int u, int v) {
        u = find_set(u);
        v = find_set(v);
        if (u == v) return ;
        if (-par[u] < -par[v]) swap(u, v);
        par[u] += par[v];
        par[v] = u;
        --cnt_comp;
    }
};

int n, m;
vector<int> p, pos;
vector<int> brute() {
    DB();
    auto count_comp = [&](int shift) -> int {
        DSU dsu(n);
        rep(i, 0, n) {
            // dsu.join(p[i], (i - shift + n) % n); 
            dsu.join(pos[i], (i + shift) % n);
        }
        return dsu.cnt_comp;
    };
    
    vector<int> cnt_comp(n + 1);
    rep(shift, 1, n + 1) {
        cnt_comp[shift] = count_comp(shift);
    }
    
    clog << db(cnt_comp) << endl;
    vector<int> ans;
    rep(i, 0, n) {
        int swap_need = n - (i == 0 ? cnt_comp[n] : cnt_comp[i]); 
        if (swap_need > m) continue;
        ans.push_back(i);
    }
    return ans;
}

vector<int> solve() {
    DB();
    
    vector<int> match(n);
    rep(i, 0, n) {
        int shift = pos[i] - i;
        if (shift < 0) shift += n;
        match[shift] ++;
    }
    
    auto count_comp = [&](int shift) -> int {
        DSU dsu(n);
        rep(i, 0, n) {
            // dsu.join(p[i], (i - shift + n) % n); 
            dsu.join(pos[i], (i + shift) % n);
        }
        return dsu.cnt_comp;
    };
    
    clog << db(match) << endl;
    vector<int> ans;
    rep(i, 0, n) {
        if (match[i] < n - 2 * m) continue;
        int cnt_comp = count_comp(i);
        if (n - cnt_comp > m) continue;
        ans.push_back(i);
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
    
    int ntest; cin >> ntest;
    while (ntest--) {
        DB();
        cin >> n >> m;
        p.resize(n);
        pos.resize(n);
        rep(i, 0, n) {
            cin >> p[i];
            --p[i];
            pos[p[i]] = i;
        }
        
        auto ans = solve();
        cout << sz(ans);
        for (auto i: ans) cout << ' ' << i;
        cout << '\n';
// #ifdef LOCAL 
        // cout << string(10, '-') << endl; 
        // auto exp = brute(); 
        // cout << sz(exp); 
        // for (auto i: exp) cout << ' ' << i; 
        // cout << endl; 
        // cout << endl; 
// #endif 
    }
    
    return 0;
}

// vim: foldmethod=marker