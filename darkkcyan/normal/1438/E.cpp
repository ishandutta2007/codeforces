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

const int maxn = 202020;
const int bit_limit = 30;
int n;
int a[maxn];
int max_bit[maxn];
llong prev_sum[maxn];

inline llong get_sum(int l, int r) { // [l; r)
    return prev_sum[r] - prev_sum[l];
}
vector<pair<int, int>> ans;
inline void add_ans(int l, int r) {
    if (r - l + 1 < 3) return ;
    if ((a[l] ^ a[r]) != get_sum(l + 1, r)) return ;
    ans.emplace_back(l, r);
}

inline void cal_res(int pos) {
    int cnt = 0;
    int bit = max_bit[pos];
    for (int i = pos - 1; i >= 0; --i) {
        add_ans(i, pos);
        if (max_bit[i] > bit) break;
        cnt += max_bit[i] == bit;
        if (cnt >= 2) break;
    }
    cnt = 0;
    for (int i = pos + 1; i < n; ++i) {
        add_ans(pos, i);
        if (max_bit[i] > bit) break;
        cnt += max_bit[i] == bit;
        if (cnt >= 2) break;
    }
    clog << db(bit) << db(pos) << db(ans) << endl;
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
    rep(i, n) {
        max_bit[i] = 31 - __builtin_clz(a[i]);
    }
    prev_sum[0] = 0;
    rep(i, n) {
        prev_sum[i + 1] = prev_sum[i] + a[i];
    }
    rep(i, n) cal_res(i);
    sort(ans.begin(), ans.end());
    llong nans = unique(ans.begin(), ans.end()) - ans.begin();
    cout << nans;
    return 0;
}

// vim: foldmethod=marker