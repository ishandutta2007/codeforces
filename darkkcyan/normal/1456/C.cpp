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

const int maxn = 501010;
int n, k;
int a[maxn];
void read() {
    cin >> n >> k;
    rep(i, n) cin >> a[i];
}

llong solve() {
    vector<llong> b(a, a + n);
    sort(b.begin(), b.end());
    int cnt_neg = (int)(upper_bound(b.begin(), b.end(), -1) - b.begin());
    llong sum_pos = 0, acc_pos = 0;
    for (int i = cnt_neg; i < n; ++i) {
        sum_pos += b[i];
        acc_pos += (i - cnt_neg) * b[i];
    }
    vector<int> neg_id(cnt_neg);
    llong acc_neg = 0;
    rep(i, cnt_neg) {
        neg_id[i] = i / (k + 1);
        acc_neg += neg_id[i] * b[i];
    }
    clog << db(neg_id) << endl;
    clog << db(cnt_neg) << db(sum_pos) << db(acc_pos) << db(acc_neg) << endl;
    llong ans = acc_pos + acc_neg;
    int total_neg = cnt_neg;
    rep(need_below, total_neg) {
        int max_stack = cnt_neg ? neg_id[cnt_neg - 1] + 1: 0;
        llong cur_acc_pos = acc_pos + sum_pos * max_stack;
        ans = max(cur_acc_pos + acc_neg, ans);
        clog << db(need_below) << db(acc_pos) << db(sum_pos) << db(acc_neg) << db(ans) << db(acc_pos + acc_neg) << db(b[cnt_neg]) << endl;
        clog << db(max_stack) << db(cur_acc_pos) << endl;
        --cnt_neg;
        acc_neg -= neg_id[cnt_neg] * b[cnt_neg];
        acc_pos += sum_pos;
        sum_pos += b[cnt_neg];
        clog << db(need_below) << db(acc_pos) << db(sum_pos) << db(acc_neg) << db(ans) << db(b[cnt_neg]) << endl;
    }
    return ans;
}

int main(void) {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    read();
    llong ans = solve();
    cout << ans << '\n';
    
    return 0;
}

// vim: foldmethod=marker