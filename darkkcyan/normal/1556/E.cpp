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

const int maxn = 101010;
int n, q;
ll a[maxn], b[maxn], diff[maxn];

bool have_same_sign(ll x, ll y) {
    if (x == 0 or y == 0) return true;
    return (x > 0) == (y > 0);
}

struct Node {
    ll sum;
    ll max_pref;
    ll min_pref;
    ll ans;
    ll left, right;
    bool same_sign;
    bool empty;
    
    Node(): empty(true) {}
    Node(ll num): sum(num), max_pref(num), min_pref(num), ans(abs(num)), left(num), right(num), same_sign(true), empty(false) {}
    Node(const Node& u, const Node& v)
        : sum(u.sum + v.sum)
        , max_pref(max(u.max_pref, u.sum + v.max_pref))
        , min_pref(min(u.min_pref, u.sum + v.min_pref))
        , ans(max({u.ans, v.ans, have_same_sign(u.right, v.left) ? abs(u.right + v.left) : LLONG_MIN}))
        , left(u.left + (u.same_sign and have_same_sign(u.left, v.left) ? v.left : 0))
        , right(v.right + (v.same_sign and have_same_sign(u.right, v.right) ? u.right : 0))
        , same_sign(u.same_sign and v.same_sign and have_same_sign(u.left, v.right))
        , empty(u.empty and v.empty)
    {
        if (u.empty) {
            *this = v;
            return ;
        }
        if (v.empty) {
            *this = u;
            return ;
        }
    }
    
    ll get_ans() const {
        if (sum) return -1;
        if (max_pref > 0) return -1;
        return -min_pref;
    }
};

Node st[maxn * 2];
void build() {
    rep(i, 0, n) st[i + n] = Node(diff[i]);
    for (int i = n; i--; ) st[i] = Node(st[2 * i], st[2 * i + 1]);
}

Node get(int l, int r) {
    Node left, right;
    for (l += n, r += n; l < r; l >>= 1, r>>= 1) {
        if (l & 1) left = Node(left, st[l++]);
        if (r & 1) right = Node(st[--r], right);
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
    cin >> n >> q;
    rep(i, 0, n) {
        cin >> a[i];
    }
    rep(i, 0, n) {
        cin >> b[i];
    }
    rep(i, 0, n) diff[i] = a[i] - b[i];
    build();
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l;
        auto ans = get(l, r);
        cout << ans.get_ans() << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker