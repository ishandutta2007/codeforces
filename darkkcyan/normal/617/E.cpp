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

using ans_type = vector<llong>;

const int maxn = 101010;
const int maxm = 101010;
const int max_val = 1 << 21;
const int blk_size = 333;
struct Query {
    int l, r;
    llong ans;
    Query() {}
};

int n, m, k;
int a[maxn];
Query qr[maxm];
void read() {
    cin >> n >> m >> k;
    rep(i, n) cin >> a[i];
    rep(i, m) {
        cin >> qr[i].l >> qr[i].r;
        --qr[i].l;
    }
}

void print_ans(ostream& cout, const ans_type& ans) {
    for (auto i: ans) cout << i << '\n';
}

ans_type solve() {
    vector<int> pref_xor(n + 1);
    rep(i, n) pref_xor[i + 1] = pref_xor[i] ^ a[i];
    
    llong cur_ans = 0;
    vector<llong> cnt(max_val);
    auto modify = [&](int val, int delta) {
        if (k == 0) {
            cur_ans -= cnt[val] * (cnt[val] - 1) / 2;
        } else {
            cur_ans -= cnt[val] * cnt[val ^ k];
        }
        
        cnt[val] += delta;
        
        if (k == 0) {
            cur_ans += cnt[val] * (cnt[val] - 1) / 2;
        } else {
            cur_ans += cnt[val] * cnt[val ^ k];
        }
    };
    
    vector<Query*> sorted_queries;
    rep(i, m) sorted_queries.push_back(qr + i);
    sort(sorted_queries.begin(), sorted_queries.end(), [&](Query* u, Query* v) {
            int blk_u = u->l / blk_size;
            int blk_v = v->l / blk_size;
            if (blk_u != blk_v) return blk_u < blk_v;
            if (blk_u & 1) return u->r > v->r;
            return u->r < v->r;
    });
    
    int l = 0, r = 0;
    modify(0, 1);
    for (auto cur_qr: sorted_queries) {
        while (l > cur_qr->l) modify(pref_xor[--l], 1);
        while (r < cur_qr->r) modify(pref_xor[++r], 1);
        while (l < cur_qr->l) modify(pref_xor[l++], -1);
        while (r > cur_qr->r) modify(pref_xor[r--], -1);
        cur_qr->ans = cur_ans;
    }
    
    vector<llong> ans;
    rep(i, m) ans.push_back(qr[i].ans);
    return ans;
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