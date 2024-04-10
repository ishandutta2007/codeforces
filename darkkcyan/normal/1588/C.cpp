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

const int maxn = 301001;

struct Node {
    ll min_val;
    int count;
    Node(): min_val(LLONG_MAX), count(0) {}
    Node(ll num, int p): min_val(num), count(1) {}
    Node(const Node& u, const Node& v) {
        min_val = min(u.min_val, v.min_val);
        count = (u.min_val != min_val ? 0 : u.count) + (v.min_val != min_val ? 0 : v.count);
    }
    friend print_op(Node) {
        return out << "(" << u.min_val << ", " << u.count << ")";
    }
};

struct segtree {
    int n;
    vector<Node> dt;
    vector<ll> lazy;
    segtree() {}
    segtree(int len): n(len), dt(4 * n), lazy(4 * n) {
        if (len) build(1, 0, n);
    }
    
    void build(int i, int l, int r) {
        clog << db(i) << db(l) << db(r) << endl;
        if (r - l == 1) {
            dt[i] = Node(0, l);
            return ;
        }
        int mid = (l + r) / 2;
        build(2 * i, l, mid);
        build(2 * i + 1, mid, r);
        dt[i] = Node(dt[2 * i], dt[2 * i + 1]);
    }
    
    void push(int i, int l, int r) {
        dt[i].min_val += lazy[i];
        if (r - l > 1) {
            lazy[2 * i] += lazy[i];
            lazy[2 * i + 1] += lazy[i];
        }
        lazy[i] = 0;
    }
    
    void upd(int from, int to, ll delta, int i, int l, int r) {
        push(i, l, r);
        if (from >= r or l >= to) return ;
        if (from <= l and r <= to) {
            lazy[i] += delta;
            push(i, l, r);
            return ;
        }
        int mid = (l + r) / 2;
        upd(from, to, delta, 2 * i, l, mid);
        upd(from, to, delta, 2 * i + 1, mid, r);
        dt[i] = Node(dt[2 * i], dt[2 * i + 1]);
    }
    
    Node get(int from, int to, int i, int l, int r) {
        push(i, l, r);
        if (from >= r or l >= to) return Node();
        if (from <= l and r <= to) return dt[i];
        int mid = (l + r) / 2;
        return Node(
                get(from, to, 2 * i, l, mid),
                get(from, to, 2 * i + 1, mid, r)
        );
    }
    
    int last_neg(int from, int to, int i, int l, int r) {
        push(i, l, r);
        if (from >= r or l >= to) return -1;
        int mid = (l + r) / 2;
        if (from <= l and r <= to) {
            if (dt[i].min_val >= 0) return - 1;
            if (r - l == 1) return l;
        }
        auto ans = last_neg(from, to, 2 * i + 1, mid, r);
        if (ans == -1) ans = last_neg(from, to, 2 * i, l, mid);
        return ans;
    }
    
    void upd(int from, int to, ll delta) {
        if (n == 0) return ;
        upd(from, to, delta, 1, 0, n);
    }
    Node get(int from, int to) {
        if (n == 0) return Node();
        return get(from, to, 1, 0, n);
    }
    int last_neg(int from, int to) {
        if (n == 0) return -1;
        return last_neg(from, to, 1, 0, n);
    }
    
    list<ll> collect(int i, int l, int r) {
        push(i, l, r);
        if (r - l == 1) return {dt[i].min_val};
        int mid = (l + r) / 2;
        auto ans = collect(2 * i, l, mid);
        ans.splice(ans.end(), collect(2 * i + 1, mid, r));
        return ans;
    }
    
    list<ll> collect() {
        return collect(1, 0, n);
    }
};


int n;
ll a[maxn];
segtree st[2];
ll solve() {
    DB();
    ll ans = 0;
    st[0] = segtree((n + 1) / 2);
    st[1] = segtree(n / 2);
    rep(i, 0, n) {
        DB();
        clog << db(i) << db(a[i]) << endl;
        int cnt_same = i / 2 + 1;
        int cnt_diff = i + 1 - cnt_same;
        st[i & 1].upd(0, cnt_same, a[i]);
        st[!(i & 1)].upd(0, cnt_diff, -a[i]);
        clog << db(st[i & 1].collect()) << endl;
        clog << db(st[!(i & 1)].collect()) << endl;
        clog << db(cnt_same) << db(cnt_diff) << endl;
        
        int u = st[i & 1].last_neg(0, cnt_same) + 1;
        int v = st[!(i & 1)].last_neg(0, cnt_diff) + 1;
        clog << db(u) << db(v) << endl;
        
        int lim = max({u * 2 + (i & 1), v * 2 + !(i & 1), 0});
        clog << db(lim) << endl;
        auto x = st[i & 1].get(lim / 2, cnt_same);
        auto y = st[!(i & 1)].get(lim / 2, cnt_diff);
        clog << db(x) << db(y) << endl;
        if (x.min_val == 0) ans += x.count;
        if (y.min_val == 0) ans += y.count;
    }
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    int ntest;
    cin >> ntest;
    while (ntest--) {
        cin >> n;
        rep(i, 0, n) cin >> a[i];
        cout << solve() << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker