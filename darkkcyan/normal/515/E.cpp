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

struct Node {
    ll length;
    ll min_left, max_right;
    ll ans;
    
    friend ostream& operator<<(ostream& out, const Node& u) {
        return out << "(" << u.length << ", " << u.min_left << ", " << u.max_right << ", " << u.ans << ")";
    }
    
    Node(): ans(-1) {}
    Node(ll h): length(0), min_left(2 * h), max_right(2 * h), ans(0) {}
    
    Node(const Node& lhs, const Node& rhs, ll mid_dist) {
        if (lhs.ans == -1) {
            *this = rhs;
            return ;
        }
        if (rhs.ans == -1) {
            *this = lhs;
            return ;
        }
        ans = max({lhs.ans, rhs.ans, lhs.min_left + rhs.max_right + mid_dist + lhs.length});
        length = lhs.length + rhs.length + mid_dist;
        min_left = max(lhs.min_left, rhs.min_left - lhs.length - mid_dist);
        max_right = max(rhs.max_right + mid_dist + lhs.length, lhs.max_right);
    }
};

const int maxn = 101010;
int n, m;
ll d[maxn], h[maxn];

Node it[maxn * 4];
// [l, r)
void build(int i, int l, int r) {
    if (r - l == 1) {
        it[i] = Node(h[l]);
        return ;
    }
    int mid = (l + r) / 2;
    build(2 * i, l, mid);
    build(2 * i + 1, mid, r);
    it[i] = Node(it[2 * i], it[2 * i + 1], d[mid - 1]);
}

// [l, r)
Node get(int from, int to, int i, int l, int r) {
    if (from >= r or l >= to) return Node();
    if (from <= l and r <= to) return it[i];
    int mid = (l + r) / 2;
    return Node(get(from, to, 2 * i, l, mid), get(from, to, 2 * i + 1, mid, r), d[mid - 1]);
}

// [l, r), 0-ind
Node query(int l, int r) {
    clog << db(l) << db(r) << endl;
    if (l < r) return get(l, r, 1, 0, n);
    clog << "here" << endl;
    auto u = get(l, n, 1, 0, n);
    auto v = get(0, r, 1, 0, n);
    clog << db(u) << endl;
    clog << db(v) << endl;
    clog << db(d[n - 1]) << endl;
    return Node(u, v, d[n - 1]);
}
    
int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep(i, 0, n) cin >> d[i];
    rep(i, 0, n) cin >> h[i];
    build(1, 0, n);
    while (m--) {
        int l, r; cin >> l >> r;
        --l;
        cout << query(r, l).ans << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker