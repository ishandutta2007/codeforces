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

const int maxn = 101010;
const int maxq = 101010;

struct DSU {
    vector<int> par, depth, root;
    vector<pair<int*, int>> history;
    DSU(int n): par(n, -1), depth(n, 1), root(n) {
        history.reserve(5 * n);
        rep(i, 0, n) root[i] = i;
    }
    pair<int, int> find_set(int u) const {
        int d = depth[u];
        while (par[u] >= 0) {
            u = par[u];
            d += depth[u];
        }
        return {u, d};
    }
    
    int& save(int& x) {
        history.emplace_back(&x, x);
        return x;
    }
    
    void join(int u, int v) {  // add an arc from u to v
        clog << db(stamp()) << endl;
        clog << db(u) << db(v) << endl;
        auto [pu, du] = find_set(u);
        auto [pv, dv] = find_set(v);
        if (pu == pv) return ;
        if (-par[pu] < -par[pv]) {
            save(depth[pu]) += dv - depth[pv];
            save(par[pv]) += par[pu];
            save(par[pu]) = pv;
        } else {
            save(depth[pu]) += dv;
            save(depth[pv]) -= depth[pu];
            save(par[pu]) += par[pv];
            save(par[pv]) = pu;
            save(root[pu]) = root[pv];
        }
        clog << db(pu) << db(pv) << db(du) << db(dv) << db(par[pu]) << db(par[pv]) << db(depth[pu]) << db(depth[pv]) << db(root[pu]) << db(root[pv]) << endl;
    }
    
    size_t stamp() const {
        return history.size();
    }
    
    void rollback(size_t st) {
        clog << "rollback" << db(st) << endl;
        while (history.size() > st) {
            auto [ptr, val] = history.back();
            history.pop_back();
            *ptr = val;
        }
    }
};

struct Edge {
    int u, v;
};

int queries[maxq];
vector<pair<int, int>> answer;

struct Segtree {
    int n;
    vector<vector<Edge>> upds;
    Segtree(int len): n(len), upds(len * 4) {}
    
    void add(int from, int to, const Edge& e, int i, int l, int r) {
        if (from >= r or l >= to) return ;
        if (from <= l and r <= to) {
            upds[i].push_back(e);
            return ;
        }
        int mid = (l + r) / 2;
        add(from, to, e, 2 * i, l, mid);
        add(from, to, e, 2 * i + 1, mid, r);
    }
    
    void add(int from, int to, const Edge& e) {
        clog << db(from) << db(to) << db(e.u) << db(e.v) << endl;
        add(from, to, e, 1, 0, n);
    }
    
    void process(int i, int l, int r, DSU& dsu) {
        DB();
        clog << db(l) << db(r) << endl;
        auto st = dsu.stamp();
        for (auto [u, v]: upds[i]) {
            dsu.join(u, v);
        }
        
        if (r - l == 1) {
            if (queries[l] != -1)  {
                auto [p, d] = dsu.find_set(queries[l]);
                clog << db(l) << db(queries[l]) << db(d) << db(p) << db(dsu.root[p]) << db(dsu.par) << db(dsu.root) << endl;
                answer.emplace_back(dsu.root[p], d);
            }
        } else {
            int mid = (l + r) / 2;
            process(2 * i, l, mid, dsu);
            process(2 * i + 1, mid, r, dsu);
        }
        
        dsu.rollback(st);
    }
    void process(DSU& dsu) {
        process(1, 0, n, dsu);
    }
};

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n), lst(n);
    for (auto& i: a) cin >> i;
    
    Segtree st(q);
    rep(i, 0, q) {
        int t;
        cin >> t;
        if (t == 0) {
            int pos, new_val;
            cin >> pos >> new_val;
            --pos;
            if (pos + a[pos] < n) {
                st.add(lst[pos], i, {pos, pos + a[pos]});
            }
            lst[pos] = i;
            a[pos] = new_val;
            queries[i] = -1;
        } else {
            cin >> queries[i];
            --queries[i];
        }
    }
    rep(i, 0, n) {
        if (i + a[i] < n) 
            st.add(lst[i], q, {i, i + a[i]});
    }
    DSU dsu(n);
    st.process(dsu);
    for (auto [p, d]: answer) cout << p + 1 << ' ' << d << '\n';
    
    return 0;
}

// vim: foldmethod=marker