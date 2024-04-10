#include <bits/stdc++.h>
using namespace std;
 
// #define constexpr(...) (__VA_ARGS__)  
using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (a); i < (b); ++i) 
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
 
struct DSU {
    vector<pair<int, int>> par;
    DSU(int n): par(n, {-1, 0}) {
        
    }
    
    pair<int, int> find_set(int u) {
        if (par[u].first < 0) return {u, 0};
        auto [p, d] = find_set(par[u].first);
        return {p, d ^ par[u].second};
    }
    
    bool join(int u, int v, int e) {
        auto [pu, du] = find_set(u);
        auto [pv, dv] = find_set(v);
        if (pu == pv) {
            return e == (du ^ dv);
        }
        if (-par[pu].first < -par[pv].first) {
            swap(pu, pv);
            swap(du, dv);
        }
        par[pu].first += par[pv].first;
        par[pv].first = pu;
        par[pv].second = e ^ du ^ dv;
        return true;
    }
};

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    mt19937 rng;
#define rand() (int)(rng() >> 1)
    int ntest = 10000;
    cin >> ntest;
    while (ntest--) {
        DB();
        int n;
        // n = rand() % 10;
        cin >> n;
        vector a(n, vector<int>(n));
        for (auto& row: a) for (auto& i: row) {
            cin >> i;
            // i = rand() % 2;
        }
        // ofstream inp("main.inp");
        // inp << "1\n";
        // inp << n << endl;
        // for (auto& row: a) {
            // for (auto i: row) inp << i << ' ';
            // inp << endl;
        // }
        // inp.close();
        
        auto ans = a;
        
        vector gr(n, vector<pair<int, int>>());
        
        DSU dsu(n);
        
        rep(i, 0, n) rep(f, i, n) {
            if (i == f) {
                continue;
            }
            if (a[i][f] == a[f][i]) continue;
            bool should_fl = a[f][i] < a[i][f];
            if (dsu.join(i, f, should_fl)) {
                gr[i].emplace_back(f, should_fl);
                gr[f].emplace_back(i, should_fl);
                clog << db(i) << db(f) << db(should_fl) << endl;
            }
        }
        vector<int> flipped(n, -1);
        rep(i, 0, n) {
            if (flipped[i] != -1) continue;
            flipped[i] = 0;
            queue<int> qu;
            for (qu.push(i); qu.size(); qu.pop()) {
                int u = qu.front();
                for (auto [v, d]: gr[u]) {
                    int nd = flipped[u] ^ d;
                    if (flipped[v] != -1) {
                        assert(flipped[v] == nd);
                        continue;
                    }
                    flipped[v] = nd;
                    qu.push(v);
                }
            }
        }
        rep(i, 0, n) rep(f, 0, n) {
            if (flipped[i] ^ flipped[f]) {
                ans[i][f] = a[f][i]; 
            } else {
                ans[i][f] = a[i][f];
            }
        }
        for (auto& row: ans) {
            for (auto i: row) cout << i << ' ';
            cout << '\n';
        }
    }
    
    return 0;
}