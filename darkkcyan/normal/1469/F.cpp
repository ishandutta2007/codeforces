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

const int max_val = (int)3e5;
llong it[max_val * 4], lazy[max_val * 4];

void propagate(int i, int l, int r) {
    it[i] += lazy[i] * (r - l);
    if (l < r - 1) {
        lazy[i << 1] += lazy[i];
        lazy[i << 1 | 1] += lazy[i];
    }
    lazy[i] = 0;
}

llong get(int pos, int i, int l, int r) {
    propagate(i, l, r);
    if (pos < l or pos >= r) return 0;
    if (l == r - 1) return it[i];
    int mid = (l + r) / 2;
    if (pos < mid) return get(pos, i << 1, l, mid);
    return get(pos, i << 1 | 1, mid, r);
}

void upd(int from, int to, llong delta, int i, int l, int r) {
    propagate(i, l, r);
    if (from >= r or l >= to) return ;
    if (from <= l and r <= to) {
        lazy[i] += delta;
        propagate(i, l, r);
        return ;
    }
    int mid = (l + r)/ 2;
    upd(from, to, delta, i << 1, l, mid);
    upd(from, to, delta, i << 1 | 1, mid, r);
    it[i] = it[i << 1]  + it[i << 1 | 1];
}

int find_pos(llong limit, int i, int l, int r) {
    propagate(i, l, r);
    int mid = (l + r) / 2;
    if (l == r - 1) return l;
    propagate(i << 1, l, mid);
    propagate(i << 1 | 1, mid, r);
    clog << db(i) << db(l) << db(r) << db(limit) << db(it[2 * i]) << endl;
    if (it[i * 2] >= limit) return find_pos(limit, i << 1, l, mid);
    return find_pos(limit - it[i * 2], 2 * i + 1, mid, r);
}

int main(void) {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto& i: a) cin >> i;
    sort(a.rbegin(), a.rend());
    
    int ans = INT_MAX;
    int cur_pos = 0;
    upd(0, 1, 1, 1, 0, max_val - 1);
    for (auto i: a) {
        while (get(cur_pos, 1, 0, max_val - 1) == 0) ++ cur_pos;
        upd(cur_pos, cur_pos + 1, -1, 1, 0, max_val - 1);
        --i;
        int half = i / 2;
        upd(cur_pos + 2, cur_pos + 2 + half, 2, 1, 0, max_val - 1);
        if (i & 1) 
            upd(cur_pos + 2 + half, cur_pos + 2 + half + 1, 1, 1, 0, max_val - 1);
        ans = min(ans, find_pos(k, 1, 0, max_val - 1));
        clog << db(i) << db(ans) << endl;
    }
    if (ans > (int)2e5 + 10) cout << "-1";
    else cout << ans;
    
    return 0;
}

// vim: foldmethod=marker