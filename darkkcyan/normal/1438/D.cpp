#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#ifdef testing
mt19937 rng(177013);
#else
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
#endif
#define rand() (int)(rng() >> 1)
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
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////

const int maxn = 101010;
int n;
int a[maxn];

vector<tuple<int, int, int>> ans;
void apply(int x, int y, int z) {
    ans.emplace_back(x, y, z);
    int t = a[x] ^ a[y] ^ a[z];
    a[x] = a[y] = a[z] = t;
}

void tle_assert(bool expr) {
    if (expr) return ;
    while(true) {}
}

int main(void) {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, n) cin >> a[i];
    int xor_all = 0;
    rep(i, n) xor_all ^= a[i];
    if (!(n & 1) and xor_all) {
        cout << "NO\n";
        return 0;
    }
    
    vector<int> rest_pos;
    vector<pair<int, int>> eq_pairs;
    rep(i, n) rest_pos.push_back(i);
    while (len(rest_pos) > 4) {
        int u = rest_pos.back(); rest_pos.pop_back();
        int v = rest_pos.back(); rest_pos.pop_back();
        int t = rest_pos.back(); rest_pos.pop_back();
        apply(u, v, t);
        eq_pairs.emplace_back(u, v);
        rest_pos.push_back(t);
    }
    apply(rest_pos[0], rest_pos[1], rest_pos[2]);
    for (auto [u, v]: eq_pairs) apply(rest_pos[0], u, v);
    tle_assert(len(ans) <= n);
    rep(i, n - 1) {
        tle_assert(a[i] == a[i + 1]);
    }
    cout << "YES\n";
    cout << len(ans) << '\n';
    for (auto [u, v, t]: ans) cout << u + 1 << ' ' << v + 1 << ' ' << t + 1 << '\n';
    
    
    return 0;
}

// vim: foldmethod=marker