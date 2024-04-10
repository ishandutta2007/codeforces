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
using ans_type = int;
constexpr bool testing = 0;
constexpr bool print_brute = 0;
constexpr bool multitest = 1;

mt19937 rng(testing ? 177013 : chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
#define rand() (int)(rng() >> 1)

const int maxn = 201010;
int n;
int a[maxn];

void read() {
    if constexpr(!testing) {
        cin >> n;
        rep(i, n) cin >> a[i];
    } else {
        ofstream inp("main.inp");
        n = rand() % 10 + 5;
        rep(i, n) a[i] = rand() % 10 + 1;
        inp << 1 << '\n' << n << '\n';
        rep(i, n) inp << a[i] << ' ';
    }
}

void print_ans(ostream& cout, const ans_type& ans) {
    cout << ans << '\n';
}

ans_type solve() {
    vector<int> vals(a, a + n);
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    rep(i, n) a[i] = (int)(lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin());
    
    vector pos(n + 10, vector<int>());
    rep(i, n) pos[a[i]].push_back(i);
    
    vector<int> lowest(n + 10);
    lowest[0] = 0;
    rep1(i, len(vals) - 1) {
        if (pos[i][0] > pos[i - 1].back()) lowest[i] = lowest[i - 1];
        else lowest[i] = i;
    }
    
    clog << vector(a, a + n) << endl;
    rep(i, len(vals)) clog << db(i) << db(pos[i]) << endl;
    
    int max_rem = 0;
    for (int u = len(vals) - 1; u >= 0; u = lowest[u] - 1) {
        int cur = 0;
        int v = lowest[u];
        clog << db(u) << db(v) << endl;
        for (int i = v; i <= u; ++i) cur += len(pos[i]);
        cur += (int)(pos[u + 1].end() - upper_bound(pos[u + 1].begin(), pos[u + 1].end(), pos[u].back()));
        if (v) cur += (int)(upper_bound(pos[v - 1].begin(), pos[v - 1].end(), pos[v][0]) - pos[v - 1].begin());
        clog << db(cur) <<endl;
        max_rem = max(max_rem, cur);
    }
    
    rep1(i, len(vals) - 1) {
        rep(f, len(pos[i])) {
            int cur = len(pos[i]) - f;
            cur += (int)(upper_bound(pos[i - 1].begin(), pos[i - 1].end(), pos[i][f]) - pos[i - 1].begin());
            max_rem = max(max_rem, cur);
        }
    }
    
    return n - max_rem;
}

ans_type brute() {
    pair<int, int> max_rem = {0, 0};
    rep(i, (1 << n)) {
        vector<int> cur, rest;
        rep(f, n) {
            if ((i >> f) & 1) {
                cur.push_back(a[f]);
            } else rest.push_back(a[f]);
        }
        if (!len(cur)) continue;
        if (!is_sorted(cur.begin(), cur.end())) continue;
        sort(rest.begin(), rest.end());
        while (len(rest) and rest.back() >= cur.back()) rest.pop_back();
        while (len(rest) and rest.back() <= cur[0]) rest.pop_back();
        if (len(rest)) continue;
        
        max_rem = max(max_rem, {__builtin_popcount(i), i});
    }
    clog << bitset<20>(max_rem.second) << endl;
    clog << vector(a, a + n) << endl;
    rep(i, n) if ((max_rem.second >> i) & 1) clog << a[i];
    clog << endl;
    return n - max_rem.first;
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