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

using ans_type = tuple<int, int, int, int>; 
constexpr bool print_case = false;

void print_ans(const ans_type& ans) {
    cout << get<0>(ans) << ' ' << get<1>(ans) << '\n';
    cout << get<2>(ans) << ' ' << get<3>(ans) << '\n';
}

ans_type solve() {
    int n; cin >> n;
    vector gr(n + 1, vector<int>());
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    if (n & 1) {
        int u = 1, v = gr[1][0];
        return {u, v, u, v};
    }
    
    vector<int> p(n + 1), cnt(n + 1);
    function<void(int)> dfs = [&](int u) {
        cnt[u] = 1;
        for (auto v: gr[u]) {
            if (v == p[u]) continue;
            p[v] = u;
            dfs(v);
            cnt[u] += cnt[v];
        }
    };
    
    p[1] = 1;
    dfs(1);
    
    auto is_centroid = [&](int u) {
        if (u != 1 and n - cnt[u] > n / 2) return false;
        for (auto v: gr[u]) 
            if (v != p[u] and cnt[v] > n / 2) return false;
        return true;
    };
    
    vector<int> cen;
    rep1(i, n) {
        if (is_centroid(i)) cen.push_back(i);
    }
    assert(len(cen) >= 1);
    if (len(cen) == 1) {
        int u = 1, v = gr[1][0];
        return {u, v, u, v};
    }
        
    int c1 = cen[0], c2 = cen[1];
    
    if (p[c1] == c2) swap(c1, c2);
    int u = c2;
    while (len(gr[u]) > 1) {
        for (auto v: gr[u]) if (v != p[u]) {
            u = v;
            break;
        }
    }
    
    return {u, p[u], u, c1};
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    rep1(testcase, ntest) {
        DB(""; deb(testcase));
        if (print_case) {
            cout << "Case #" << testcase << ": ";
            cerr << testcase << endl;
        }
        print_ans(solve());
    }

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker