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
    vector<int> dsu, min_val, max_val;
    
    DSU(int sz): dsu(sz, -1), min_val(sz), max_val(sz) {
        for (auto i: views::iota(0, sz)) {
            min_val[i] = i + 1;
            max_val[i] = i - 1;
        }
    }
    
    int find_set(int u) {
        return dsu[u] < 0 ? u : dsu[u] = find_set(dsu[u]);
    }
    
    bool is_occupied(int u) {
        u = find_set(u);
        return min_val[u] <= u and u <= max_val[u];
    }
    
    void set_occupied(int u) {
        min_val[u] = max_val[u] = u;
    }
    
    void join(int u, int v) {
        u = find_set(u);
        v = find_set(v);
        if (u == v) return ;
        if (-dsu[u] < -dsu[v]) swap(u, v);
        dsu[u] += dsu[v];
        dsu[v] = u;
        min_val[u] = min(min_val[u], min_val[v]);
        max_val[u] = max(max_val[u], max_val[v]);
    }
    
    pair<int, int> get_val_range(int u) {
        u = find_set(u);
        return {min_val[u], max_val[u]};
    }
};

struct Point {
    int r, c;
};

int pd(const Point& u, const Point& v) {
    return abs(u.r - v.r) + abs(u.c - v.c);
}

struct AnsT {
    int dist;
    Point dest;

    friend bool operator<(const AnsT& u, const AnsT& v) {
        if (int t = u.dist - v.dist; t) return t < 0;
        if (int t = u.dest.r - v.dest.r; t) return t < 0;
        return u.dest.c < v.dest.c;
    }
    
    void upd(const AnsT& x) {
        if (x < *this) *this = x;
    }
    
    void upd(const Point& src, const Point& dst) {
        int d = pd(src, dst);
        upd(AnsT{d, dst});
    }
};

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    // n = 2000;
    // m = 30;
    // k = n * m;
    
    vector<DSU> occupied_ranges(n, m);
    
    while (k--) {
        // DB();
        int r, c;
        cin >> r >> c;
        // r = 1625;
        // c = 17;
        --r, --c;
        // clog << db(r) << db(c) << endl;
        
        AnsT ans {INT_MAX, {-1, -1}};
        
        for (auto row_dist: views::iota(0, n + 1)) {
            // DB();
            if (row_dist > ans.dist) break;
            // clog << db(row_dist) << endl;
            for (auto dst_r: {r - row_dist, r + row_dist}) {
                if (dst_r < 0 or dst_r >= n) continue;
                auto free_range = occupied_ranges[dst_r].get_val_range(c);
                // clog << db(dst_r) << db(free_range) << endl;
                for (auto dst_c: {free_range.first - 1, free_range.second + 1}) {
                    if (dst_c < 0 or dst_c >= m) continue;
                    // clog << db(dst_r) << db(dst_c) << endl;
                    ans.upd({r, c}, {dst_r, dst_c});
                }
            }
        }
        
        clog << db(ans.dest.r) << db(ans.dest.c) << endl;
        cout << ans.dest.r + 1 << ' ' << ans.dest.c + 1 << '\n';
        
        auto& o = occupied_ranges[ans.dest.r];
        o.set_occupied(ans.dest.c);
        if (ans.dest.c > 0 and o.is_occupied(ans.dest.c - 1)) {
            o.join(ans.dest.c, ans.dest.c - 1);
        }
        if (ans.dest.c + 1 < m and o.is_occupied(ans.dest.c + 1)) {
            o.join(ans.dest.c, ans.dest.c + 1);
        }
    }
    
    return 0;
}