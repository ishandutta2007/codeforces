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

struct Node {
    int cnt;
    ll sum, ans;
    Node(int cur = 0, ll x = 0): cnt(cur), sum(cur * x), ans(0) {}
    Node(const Node& l, const Node& r)
        : cnt(l.cnt + r.cnt)
        , sum(l.sum + r.sum)
        , ans(l.ans + r.ans + r.sum * l.cnt - l.sum * r.cnt)
    {}
};

const int maxn = 202020;
Node nodes[maxn * 2];
void upd(int i, ll x, int delta) {
    int u = i + maxn;
    nodes[u] = Node(nodes[u].cnt + delta, x);
    for (u >>= 1; u > 0; u >>= 1) nodes[u] = Node(nodes[u << 1], nodes[u << 1 | 1]);
}

Node get(int l, int r) {
    Node ansl(0, 0), ansr(0, 0);
    for (l += maxn, r += maxn; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ansl = Node(ansl, nodes[l++]);
        if (r & 1) ansr = Node(nodes[--r], ansr);
    }
    return Node(ansl, ansr);
}

struct Query {
    int t;
    union {
        struct {int i, d;};
        struct {int l, r;};
    };
};

int n, q;
vector<ll> org_x, x;
vector<Query> queries;

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    org_x.resize(n);
    for (auto& i: org_x) cin >> i;
    x = org_x;
    vector<ll> values = x;
    cin >> q;
    queries.resize(q);
    rep(i, 0, q) {
        cin >> queries[i].t >> queries[i].i >> queries[i].r;
        if (queries[i].t == 1) {
            --queries[i].i;
            x[queries[i].i] += queries[i].d;
            values.push_back(x[queries[i].i]);
        }
    }
    
    sort(all(values));
    values.erase(unique(all(values)), values.end());
    
    auto idx = [&](ll v) {
        return (int)(lower_bound(all(values), v) - values.begin());
    };
    
    clog << db(values) << endl;
    
    x = org_x;
    for (auto u: x) upd(idx(u), u, 1);
    
    rep(i, 0 , q) {
        if (queries[i].t == 1) {
            int id = queries[i].i, d = queries[i].d;
            upd(idx(x[id]), x[id], -1);
            x[id] += d;
            upd(idx(x[id]), x[id], 1);
        } else {
            auto ans = get(
                    idx(queries[i].l), 
                    idx(queries[i].r + 1)
                    );
            cout << ans.ans << '\n';
        }
    }
    
    
    return 0;
}

// vim: foldmethod=marker