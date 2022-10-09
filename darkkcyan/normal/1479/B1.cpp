#ifdef LOCAL
#define testing     
#endif
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

int n;
vector<int> a;
int solve() {
    int prv[2] = {-1, -1};
    int ans = 0;
    vector<int> nxt(n, n);
    vector<int> pos(n + 1, n);
    for (int i = n; i --; ) {
        nxt[i] = pos[a[i]];
        pos[a[i]] = i;
    }
    
    auto get_next = [&](int u) {
        return u == -1 ? n : nxt[u];
    };
    
    auto get = [&](int u) { return u == -1 ? n + 1 : a[u]; };
    
    rep(i, n) {
        DB(i << db(a[i]));
        int p = get_next(prv[0]) < get_next(prv[1]) ? 0 : 1;
        clog << db(p) << endl;
        if (a[i] == get(prv[p])) p = !p;
        clog << db(p) << endl;
        if (a[i] != get(prv[p])) {
            ++ans;
        }
        prv[p] = i;
        clog << db(ans) << endl;
        clog << db(prv[0]) << db(prv[1]) << endl;
    }
    
    return ans;
}

int brute() {
    int ans = 0;
    rep(mask, (1 << n)) {
        int cur_ans = 0;
        int prv[2] = {-1, -1};
        rep(i, n) {
            auto& cur = prv[(mask >> i) & 1];
            if (cur == a[i]) continue;
            cur = a[i];
            ++cur_ans;
        }
        ans = max(ans, cur_ans);
    }
    return ans;
}
int main(void) {
#ifdef testing
    while (true) {
        n = rand() % 10 + 1;
        a.resize(n);
        rep(i, n) a[i] = rand() % n + 1;
            ofstream inp("main.inp");
            inp << n << endl;
            for (auto i: a ) inp << i << ' ';
            inp << endl;

        auto exp = brute();
        auto ans = solve();
        inp << exp << ' ' << ans << endl;
        if (exp == ans) {
            cout << "OK" << endl;
            continue;
        }
        cout << "FAILED" << endl;
        return 0;
    }
#endif
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    a.resize(n);
    rep(i, n) cin >> a[i];
    cout << solve() << endl;
    
    return 0;
}

// vim: foldmethod=marker