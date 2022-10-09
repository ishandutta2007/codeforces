#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
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

// Change these
using ans_type = llong;
constexpr bool testing = 0;
constexpr bool print_brute = 0;
constexpr bool multitest = 0;

mt19937 rng(testing ? 177013 : chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64

const int maxn = 101010;
int n, m;
llong a[maxn], b[maxn];
vector<int> contains[maxn];

void read() {
    if constexpr(!testing) {
        cin >> m >> n;
        rep(i, m) cin >> a[i];
        rep(i, n) cin >> b[i];
        rep(i, m) {
            int s; cin >> s;
            contains[i].resize(s);
            for (auto& f: contains[i]) {
                cin >> f;
                --f;
            }
        }
        
    } else {
        ofstream inp("main.inp");
        // generate test
    }
}

void print_ans(ostream& cout, const ans_type& ans) {
    cout << ans << '\n';
}

ans_type solve() {
    vector<int> dsu(n + m, -1);
    function<int(int)> find_set = [&](int u ) {
        return dsu[u ] < 0 ? u : dsu[u] = find_set(dsu[u]); 
    };
    
    auto join = [&](int u, int v) {
        u = find_set(u);
        v = find_set(v);
        if (u == v) return ;
        if (-dsu[u] < -dsu[v]) swap(u, v);
        dsu[u] += dsu[v];
        dsu[v] = u;
    };
    
    llong total = 0;
    vector<tuple<llong, int, int>> edges;
    rep(i, m) {
        for (auto f: contains[i]) {
            edges.emplace_back(a[i] + b[f], i, f + m);
            total += get<0>(edges.back());
        }
    }
    clog << total << endl;
    
    sort(edges.rbegin(), edges.rend());
    for (auto [cost, i, f]: edges) {
        if (find_set(i) == find_set(f)) continue;
        total -= cost;
        clog << db(cost) << db(i) << db(f) << endl;
        join(i, f);
    }
    return total;
}

ans_type brute() {
    return ans_type();
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest = testing ? 1000 : 1; 
    if (multitest and !testing) cin >> ntest;
    
    rep1(testcase, ntest) {
        DB(testcase);
        read();
        if constexpr (!testing) {
            print_ans(cout, solve());
            if (print_brute) print_ans(cout << endl << "====" << endl, brute());
        } else {
            auto u = solve();
            auto v = brute();
            assert(u == v);
        }
    }
    

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker