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

const ll inf = 1e12;
struct Data {
    int length;
    ll sum, mi[2], ma[2];
    
    Data(): length(0), sum(0), mi{inf, inf}, ma{-inf, -inf} {}
    Data(int num): length(1), sum(num), mi{num, inf}, ma{num, -inf} {
        clog << "new node " << db(num) << endl;
    }
    
    Data(const Data& u, const Data& v) {
        DB();
        clog << db(u) << endl;
        clog << db(v) << endl;
        length = u.length + v.length;
        if (u.length & 1) {
            sum = u.sum - v.sum;
            rep(i, 0, 2) {
                mi[i] = min(u.mi[i], u.sum - v.ma[!i]);
                ma[i] = max(u.ma[i], u.sum - v.mi[!i]);
            }
        } else {
            sum = u.sum + v.sum;
            rep(i, 0, 2) {
                mi[i] = min(u.mi[i], u.sum + v.mi[i]);
                ma[i] = max(u.ma[i], u.sum + v.ma[i]);
            }
        }
        clog << db(*this) << endl;
    }
    
    void add(int x) {
        if (length & 1) sum += x;
        mi[0] += x;
        ma[0] += x;
    }
    
    bool ok() const {
        return sum == 0 and max(mi[0], mi[1]) >= 0;
    }

    friend print_op(Data) {
        return out << "(" << db(u.length) << db(u.sum) << db(u.mi[0]) << db(u.mi[1])<< db(u.ma[0]) << db(u.ma[1]) << ")";
    }
};

const int maxn = 201010;
Data it[maxn * 4];
int lazy[maxn * 4];

void build(int i, int l, int r, int* a) {
    if (r - l == 1) {
        it[i] = Data(a[l]);
        return ;
    }
    int mid = (l + r) / 2;
    build(2 * i, l, mid, a);
    build(2 * i + 1, mid, r, a);
    it[i] = Data(it[2 * i], it[2 * i + 1]);
}

void push(int i, int l, int r) {
    it[i].add(lazy[i]);
    if (r - l > 1) {
        lazy[2 * i] += lazy[i];
        lazy[2 * i + 1] += lazy[i];
    }
    lazy[i] = 0;
}

void upd(int from, int to, int delta, int i, int l, int r) {
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
    it[i] = Data(it[2 * i], it[2 * i + 1]);
}

Data get(int from, int to, int i, int l, int r) {
    push(i, l, r);
    if (from >= r or l >= to) return Data();
    if (from <= l and r <= to) return it[i];
    int mid = (l + r) / 2;
    return Data(get(from, to, 2 * i, l, mid), get(from, to, 2 * i + 1, mid, r));
}

int n;
int a[maxn], b[maxn];

void upd(int from, int to, int delta) {
    upd(from, to, delta, 1, 0, n);
}

Data get(int from, int to) {
    return get(from, to, 1, 0, n);
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
        --a[i];
    }
    
    build(1, 0, n, a);
    int q; cin >> q;
    while (q--) {
        DB();
        int type, l, r; cin >> type >> l >> r;
        ++r;
        if (type == 1) {
            int delta; cin >> delta;
            upd(l, r, delta);
        } else {
            auto ans = get(l, r);
            clog << db(ans) << endl;
            cout << ans.ok() << '\n';
        }
    }
    
    return 0;
}

// vim: foldmethod=marker