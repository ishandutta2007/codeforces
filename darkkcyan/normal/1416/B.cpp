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
using ans_type = optional<vector<tuple<int, int, llong>>>;
constexpr bool testing = 0;
constexpr bool print_brute = 0;
constexpr bool multitest = 1;

mt19937 rng(testing ? 177014 : chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64

const int maxn = 10101;
int n;
llong a[maxn];

void read() {
    if constexpr(!testing) {
        cin >> n;
        rep1(i, n) cin >> a[i];
    } else {
        ofstream inp("main.inp");
        n = 10000;
        int dest = (int)(rng() % 100000) + 1;
        rep1(i, n) a[i] = dest;
        rep(t, n) {
            int u = int(rng() % n) + 1;
            int v = int(rng() % n) + 1;
            int mv = int(rng() % a[u]);
            a[u] -= mv;
            a[v] += mv;
        }
        inp << 1 << endl;
        inp << n << endl;
        rep1(i, n) inp << a[i] << ' ';
        inp << endl;
    }
}

void print_ans(ostream& cout, const ans_type& ans) {
    if (!ans) cout << "-1\n";
    else {
        cout << ans->size() << '\n';
        for (auto [i, j, x]: *ans) {
            cout << i << ' ' << j << ' ' << x << '\n';
        }
    }
}

ans_type solve() {
    llong sum = accumulate(a + 1, a + n + 1, 0ll);
    if (sum % n) return {};
    llong dest = (sum / n);
    vector<tuple<int, int, llong>> ans;
    auto give = [&](int i, int j, llong x) {
        assert(x >= 0);
        assert(x <= 1000000000);
        a[i] -= i * x;
        a[j] += i * x;
        assert(a[i] >= 0);
        ans.emplace_back(i, j, x);
    };
    for (int i = 2; i <= n; ++i) {
        if (a[i] % i) {
            give(1, i, i - (a[i] % i));
        }
        
        give(i, 1, a[i] / i);
    }
    
    for (int i = 2; i <= n; ++i) {
        if (a[i] >= dest) continue;
        llong cur_need = dest - a[i];
        give(1, i, cur_need);
    }
    rep1(i, n) assert(a[i] == dest);
    assert(len(ans) <= 3 * n);
    return {ans};
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
            cout << "test " << testcase << endl;
            auto u = solve();
            // auto v = brute(); 
            // assert(u == v); 
            cout << "OK" << endl;
        }
    }
    

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker