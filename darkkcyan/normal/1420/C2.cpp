#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define rand __rand
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
template<class T = int> T rand(T range = numeric_limits<T>::max()) { return (T)(rng() % range); }

#define CONCAT_(x, y) x##y/*{{{*/
#define CONCAT(x, y) CONCAT_(x, y)
#define SPEC(name) CONCAT(name, __LINE__)
#ifdef LOCAL_DEBUG   
int __db_level = 0;
#define clog cerr << string(__db_level * 2, ' ')
struct debug_block {
    string msg;
    debug_block(const string& s): msg(s) { clog << "{ " << msg << endl; ++__db_level; }
    ~debug_block() { --__db_level; clog << "} " << msg << endl; }
};
#define DB(args...) stringstream SPEC(ss); SPEC(ss)<< args; debug_block SPEC(dbbl)(SPEC(ss).str())
#else
#define clog if (0) cerr
#define DB(...)
#endif
#define db(val) "[" #val " = " << val << "]; "
template<class U, class V> ostream& operator<<(ostream& out, const pair<U, V>& p) {
    return out << "(" << p.first << ", " << p.second << ")";
}
template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")";
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup);
}
template<class ...U>
ostream& operator<<(ostream& out, const tuple<U...>& tup) { return print_tuple_utils<0, tuple<U...>>(out, tup); }
template<class, typename = void> struct has_const_iterator : false_type {};
template<class T> struct has_const_iterator<T, void_t<typename T::const_iterator>> : true_type {};
template<class T>
typename enable_if<has_const_iterator<T>::value && !is_same<T, string>::value, ostream&>::type
operator<<(ostream& out, const T& container) { 
    auto beg = container.begin(), end = container.end();
    out << "(" << container.size() << ") {";
    if (beg != end) out << *(beg++);
    while (beg != end) out << ", " << *(beg++);
    return out << "}";
}
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> $v(u a, u b) { return vector<ptrtype(u)>(a, b); }/*}}}*/
// ACTUAL SOLUTION BELOW ////////////////////////////////////////////////////////////

struct node_data {
    array<llong, 2> mx;
    array<llong, 2> mi;
    node_data(): mx{0, LLONG_MIN} {}
    node_data(llong num): mx{0, num}, mi{0, num} {}
    node_data(const node_data& u, const node_data& v) {
        if (u.mx[1] == LLONG_MIN) {
            mx = v.mx; mi = v.mi;
            return ;
        }
        if (v.mx[1] == LLONG_MIN) {
            mx = u.mx; mi = u.mi;
            return ;
        }
        DB("joining");
        clog << db(u.mx[0]) << db(u.mx[1]) << db(u.mi[0]) << db(u.mi[1]) << endl;
        clog << db(v.mx[0]) << db(v.mx[1]) << db(v.mi[0]) << db(v.mi[1]) << endl;
        
        mx[0] = max({
                u.mx[0], v.mx[0],
                u.mx[0] + v.mx[0],
                u.mx[1] - v.mi[1]
                });
        mx[1] = max({
                u.mx[1], v.mx[1],
                u.mx[0] + v.mx[1],
                u.mx[1] - v.mi[0]
                });
        mi[0] = min({
                u.mi[0], v.mi[0],
                u.mi[0] + v.mi[0],
                u.mi[1] - v.mx[1]
                });
        mi[1] = min({
                u.mi[1], v.mi[1],
                u.mi[0] + v.mi[1],
                u.mi[1] - v.mx[0]
                });
        clog << db(mx[0]) << db(mx[1]) << db(mi[0]) << db(mi[1]) << endl;
    }
    
    llong get_ans() const {
        return max(mx[0], mx[1]);
    }
};

const int maxn = 301010;

int n;
llong a[maxn];

node_data it[maxn * 2];
void build() {
    rep(i, n) it[i + n] = node_data(a[i]);
    for (int i = n - 1; i > 0; --i) {
        it[i] = node_data(it[2 * i], it[2 * i + 1]);
    }
}

void upd(int i) {
    for (it[i+ n] = node_data(a[i]), i+= n; i > 1; ) {
        i >>= 1;
        clog << db(i) << endl;
        it[i] = node_data(it[2 * i], it[2 * i + 1]);
    }
}

node_data get(int l, int r) {
    node_data head, tail;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
            clog << db(l) << endl;
            head = node_data(head, it[l++]);
        }
        if (r & 1) {
            clog << db(r - 1) << endl;
            tail = node_data(it[--r], tail);
        }
    }
    return node_data(head, tail);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        DB("test");
        int q; 
        cin >> n >> q;
        rep(i, n) cin >> a[i];
        build();
        cout << get(0, n).get_ans() << '\n';
        while (q--) {
            DB("query");
            int u, v; cin >> u >> v;
            --u; --v;
            swap(a[u], a[v]);
            upd(u);
            upd(v);
            cout << get(0, n).get_ans() << '\n';
        }
    }
    

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker