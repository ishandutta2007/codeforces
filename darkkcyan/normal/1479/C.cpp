#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#ifdef testing/*{{{*/
mt19937 rng(177013);
#else
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
#endif
#define rand() (int)(rng() >> 1)
#define CONCAT_(x, y) x##y
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
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////

int main(void) {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int l, r; cin >> l >> r;
    cout << "YES\n";
    
    --l;
    r -= l;
    
    if (r == 1) {
        cout << "2 1\n";
        cout << "1 2 " << l + 1;
        return 0;
    }
    if (r == 2) {
        cout << "3 3\n";
        cout << "1 2 " << l + 1 << endl;
        cout << "1 3 " << l + 1 << endl;
        cout << "2 3 " << 1 << endl;
        return 0;
    }
    if (r == 3) {
        cout << "4 5\n";
        cout << "1 2 " << l + 1 << endl;
        cout << "1 3 " << l + 1 << endl;
        cout << "2 3 " << 1 << endl;
        cout << "1 4 " << l + 1 << endl;
        cout << "3 4 " << 1;
        return 0;
    }
    
    vector<vector<pair<int, int>>> gr(1);
    auto new_node = [&] {
        gr.emplace_back();
        return len(gr) - 1;
    };
    
    auto clone = [&](int node_id) {
        gr.push_back(gr[node_id]);
        return len(gr) - 1;
    };
    
    function<int(int)> build = [&](int sz) {
        clog << db(sz) << endl;
        if (sz < 4) {
            int dst = new_node();
            int x = new_node();
            int temp1 = new_node();
            gr[x].emplace_back(dst, 1);
            gr[temp1].emplace_back(dst, 2);
            rep(_, sz - 1) {
                int y = new_node();
                gr[y].emplace_back(dst, 1);
                gr[y].emplace_back(x, 1);
                x = y;
            }
            return x;
        }
        
        int quad = sz / 4;
        int x = build(quad);
        int u, v, temp;
        int rem = sz % 4;
        if (rem) temp = new_node();
        u = clone(x);
        gr[u].emplace_back(x, quad);
        v = clone(u);
        gr[v].emplace_back(u, 2 * quad);
        if (!rem) return v;
        gr[v].emplace_back(temp, 2 * quad + 1);
        if (rem >= 1) gr[temp].emplace_back(1, 2 * quad);
        if (rem >= 2) gr[temp].emplace_back(2, 2 * quad);
        if (rem >= 3) gr[temp].emplace_back(3, 2 * quad);
        return v;
    };
    
    build(r);
    
    int cnt_edge = 0;
    for (auto& g: gr) cnt_edge += len(g);
    cout << len(gr) - 1 << ' ' << cnt_edge << '\n';
    rep1(i, len(gr) - 1) {
        for (auto [v, c]: gr[i]) {
            if (v == 1) c += l;
            cout << v << ' ' << i << ' ' << c << '\n';
        }
    }
    
    
    return 0;
}

// vim: foldmethod=marker