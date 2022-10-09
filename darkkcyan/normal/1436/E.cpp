// #define multitest 
#ifdef LOCAL
// #define testing 
// #define print_brute 
#endif

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

using ans_type = int;

const int maxn = 101010;
int n;
int a[maxn];
void read() {
    cin >> n;
    rep(i, n) cin >> a[i];
}

void print_ans(ostream& cout, const ans_type& ans) {
    cout << ans << '\n';
}

const int blk_size = 333;
struct Mex {
    vector<int> blk_cnt;
    vector<int> cnt;
    Mex(): blk_cnt(maxn / blk_size + 1), cnt(maxn) {
    }
    
    void inc(int num) {
        clog << "inc " << num << endl;
        if (++cnt[num] == 1) blk_cnt[num / blk_size]++;
    }
    void dec(int num) {
        clog << "dec" << num << endl;
        if (cnt[num]-- == 1) blk_cnt[num / blk_size]--;
    }
    
    int get_mex() {
        rep(i, len(blk_cnt)) {
            if (blk_cnt[i] == blk_size) continue;
            int blk = i * blk_size;
            rep(f, blk_size) if (!cnt[blk + f]) return blk + f;
            assert(false);
        }
        assert(false);
        return -1;
    }
};

struct Query {
    int l, r;
    int check;
    Query() {}
    Query(int l_, int r_, int c): l(l_), r(r_), check(c) {}
    friend bool operator<(const Query& u, const Query& v) {
        int bu = u.l / blk_size;
        int bv = v.l / blk_size;
        if (bu != bv) return bu < bv;
        if (bu & 1) return u.r > v.r;
        else return u.r < v.r;
    }
};
ans_type solve() {
    vector<vector<int>> pos(n + 10);
    rep(i, n) pos[a[i] - 1].push_back(i);
    vector<Query> queries;
    rep(val, n + 10) {
        int prv = 0;
        for (auto p: pos[val]) {
            if (p - 1 >= prv) queries.emplace_back(prv, p - 1, val);
            prv = p + 1;
        }
        if (prv <= n - 1) queries.emplace_back(prv, n - 1, val);
    }
    sort(queries.begin(), queries.end());
    Mex overal_mex;
    Mex cur_mex;
    int l = 0, r = 0;
    cur_mex.inc(a[0] - 1);
    for (auto [ql, qr, val]: queries) {
        while (ql < l) cur_mex.inc(a[--l] - 1);
        while (qr > r) cur_mex.inc(a[++r] - 1);
        while (ql > l) cur_mex.dec(a[l++] - 1);
        while (qr < r) cur_mex.dec(a[r--] - 1);
        clog << l << ' ' << r << ' ' << val << ' ' << cur_mex.get_mex() << endl;
        if (cur_mex.get_mex() == val) overal_mex.inc(val);
    }
    int ans = overal_mex.get_mex();
    return ans + 1;
}

// ACUTAL SOLUTION END HERE //////////////////////////////////////////////////////////////////
// FOR HACKER/READER - you don't need to care about the part below
ans_type brute();
#ifndef testing
int main(void) {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest = 1;
#ifdef multitest
    cin >> ntest;
#endif
    rep1(testcase, ntest) {
        DB(testcase);
        read();
        auto ans = solve();
        print_ans(cout, ans);
#ifdef print_brute
        auto br = brute();
        print_ans(cout << endl << "====" << endl, br);
        cout << endl << "==============" << endl;
#endif
    }
    return 0;
}
#else
void gen_test(int cur_test) {
    ofstream inp("main.inp");
    
}
int main(void) {
    rep1(testcase, 10000) {
        gen_test(testcase);
        auto ans = solve();
        auto br = brute();
        assert(ans == br);
        cout << "OK " << testcase << endl;
    }
    return 0;
}
#endif

ans_type brute() {
    return ans_type();
}

// vim: foldmethod=marker