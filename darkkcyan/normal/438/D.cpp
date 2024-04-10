#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const ld eps = 1e-8;
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define be(a) (a).begin(), (a).end()
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

struct Node {
    ll sum, mx;
    Node(ll val = 0): sum(val), mx(val) {}
    Node(const Node& left, const Node& right): sum(left.sum + right.sum), mx(max(left.mx, right.mx)) {
    }
};

struct IT {
    vector<Node> vals;
    IT(size_t sz): vals(sz * 4) {}
    template<class Iter>
    IT(Iter beg, Iter end): IT(distance(beg, end)) {
        build(beg, 1, 0, size());
    }
    
    template<class Iter>
    void build(Iter beg, int i, int l, int r) {
        if (r - l == 1) {
            vals[i] = Node(beg[l]);
            return ;
        }
        int mid = (l + r) / 2;
        build(beg, i << 1, l, mid);
        build(beg, i << 1 | 1, mid, r);
        vals[i] = Node(vals[i << 1], vals[i << 1 | 1]);
    }
    
    inline int size() const {  return len(vals) >> 2; }
    
    void assign(int pos, ll val, int i, int l, int r) {
        if (pos >= r or pos < l) return ;
        if (r - l == 1) {
            vals[i] = Node(val);
            return ;
        }
        int mid = (l + r) / 2;
        if (pos < mid) assign(pos, val, i << 1, l, mid);
        else assign(pos, val, i << 1 | 1, mid, r);
        vals[i] = Node(vals[i << 1], vals[i << 1 | 1]);
    }
    
    void mod(int from, int to, ll m, int i, int l, int r) {
        if (from >= r or l >= to) return ;
        if (vals[i].mx < m) return ;
        if (r - l == 1) {
            vals[i].sum %= m;
            vals[i].mx = vals[i].sum;
            return ;
        }
        int mid = (l + r) / 2;
        mod(from, to, m, i << 1, l, mid);
        mod(from, to, m, i << 1 | 1, mid, r);
        vals[i] = Node(vals[i << 1], vals[i << 1 | 1]);
    }
    
    ll get_sum(int from, int to, int i, int l, int r) {
        if (from >= r or l >= to) return 0;
        if (from <= l and r <= to) return vals[i].sum;
        int mid = (l + r) / 2;
        return get_sum(from, to, i << 1, l, mid) + get_sum(from, to, i << 1 | 1, mid, r);
    }
    void assign(int pos, ll val) { assign(pos, val, 1, 0, size()); }
    void mod(int from, int to, ll m) { mod(from, to, m, 1, 0, size()); }
    ll get_sum(int from, int to) { return get_sum(from, to, 1, 0, size()); }
};

int main(void) {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    IT it(be(a));
    
    while (m--) {
        int type; cin >> type;
        if (type == 1) {
            int l, r; cin >> l >> r;
            cout << it.get_sum(l - 1, r) << '\n';
        } else if (type == 2) {
            int l, r;
            ll mod;
            cin >> l >> r >> mod;
            it.mod(l - 1, r, mod);
        } else {
            int k; ll x;
            cin >> k >> x;
            it.assign(k - 1, x);
        }
    }
    
    return 0;
}

// vim: foldmethod=marker