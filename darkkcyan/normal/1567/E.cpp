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

ll choose2(ll x) {
    return x * (x - 1) / 2;
}

struct Node {
    int length;
    int max_left, max_right;
    int lval, rval;
    ll ans;
    Node(): length(0), max_left(0), max_right(0), lval(0), rval(0), ans(0) {}
    Node(int val): length(1), max_left(1), max_right(1), lval(val), rval(val), ans(0) {}
    Node(const Node& left, const Node& right)
        : length(left.length + right.length)
        , max_left(left.max_left + (left.max_left == left.length and left.rval <= right.lval ? right.max_left : 0))
        , max_right(right.max_right + (right.max_right == right.length and left.rval <= right.lval ? left.max_right : 0))
        , lval(left.lval)
        , rval(right.rval)
        , ans(left.ans + right.ans)
    {
        if (left.length == 0) {
            *this = right;
            return ;
        }
        if (right.length == 0) {
            *this = left;
            return ;
        }
        if (left.rval <= right.lval) {
            if (max_left < left.length and max_right < right.length) ans += choose2(left.max_right + right.max_left + 1);
        } else {
            if (left.max_right != left.length) ans += choose2(left.max_right + 1);
            if (right.max_left != right.length) ans += choose2(right.max_left + 1);
        }
    }
    
    ll get_ans() const {
        clog << db(*this) << endl;
        if (max_left == length) return choose2(length + 1);
        return ans + choose2(max_left + 1) + choose2(max_right + 1);
    }
    
    friend print_op(Node) {
        return out << "(" << u.ans << ", " << u.max_left << ", " << u.max_right << ")";
    }
};

const int maxn = 201010;
int n;
int a[maxn];
Node it[maxn * 2];

void build() {
    rep(i, 0, n) it[i + n] = a[i];
    for (int i = n; i--; ) it[i] = Node(it[i << 1], it[i << 1 | 1]);
}

void upd(int i, int val) {
    i += n;
    it[i] = val;
    for (i >>= 1; i > 0; i >>= 1) it[i] = Node(it[i << 1], it[i << 1 | 1]);
}

Node get(int l, int r) {
    Node left, right;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) left = Node(left, it[l++]);
        if (r & 1) right = Node(it[--r], right);
    }
    return Node(left, right);
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    int q; cin >> q;
    rep(i, 0, n) cin >> a[i];
    build();
    while (q--) {
        int type, u, v; cin >> type >> u >> v;
        if (type == 1) {
            upd(--u, v);
        } else {
            cout << get(--u, v).get_ans() << '\n';
        }
    }
    
    return 0;
}

// vim: foldmethod=marker