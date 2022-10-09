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

using ans_type = vector<vector<int>>;

int n;
vector<int> a;
void read() {
    cin >> n;
    a.resize(n);
    rep(i, n) cin >> a[i];
}

void print_ans(ostream& cout, const ans_type& ans) {
    cout << len(ans) << '\n';
    for (auto& blk_sz: ans) {
        cout << len(blk_sz) << ' ';
        for (auto i: blk_sz) cout << i << ' ';
        cout << '\n';
    }
}

ans_type solve() {
    auto b = a;
    auto find_pos = [&](int x) {
        return (int)(find(b.begin(), b.end(), x) - b.begin());
    };
    vector<vector<int>> ans;
    auto change = [&](const vector<int>& blk_sz) {
        DB("change");
        clog << db(blk_sz) << endl;
        vector<vector<int>> vals;
        int cur = 0;
        for (auto i: blk_sz) {
            assert(i > 0);
            assert(i + cur <= n);
            clog << i << ' ' << cur << endl;
            vals.emplace_back(b.begin() + cur, b.begin() + cur + i);
            cur += i;
        }
        assert(cur == len(b));
        reverse(vals.begin(), vals.end());
        cur = 0;
        for (auto& blk: vals)  {
            for (auto i: blk) b[cur++] = i;
        }
        ans.push_back(blk_sz);
        clog << db(b) << endl;
    };
    int cur = 0;
    if (n & 1) {
        int pos_mid = find_pos(n / 2 + 1);
        if (pos_mid != 0) {
            change({pos_mid, len(b) - pos_mid});
        }
        cur = 1;
    } else {
        int mid1 = find_pos(n / 2);
        if (mid1 != len(b) - 1) change({mid1 + 1, len(b) - mid1 - 1});
        
        int mid2 = find_pos(n / 2 + 1);
        if (mid2 == 0) change({len(b) - 1, 1});
        else change({mid2, len(b) - mid2 - 1, 1});
        cur = 2;
    }
    while (cur < len(b)) {
        clog << db(cur) << endl;
        int prv = b[0] - 1;
        assert(prv > 0);
        int pos_prv = find_pos(prv);
        clog << db(prv) << db(pos_prv) << endl;
        if (pos_prv == len(b) - 1) change({cur, len(b) - cur});
        else change({cur, pos_prv + 1 - cur, len(b) - pos_prv - 1});
        
        ++cur;
        int nxt = b.back() + 1;
        assert(nxt <= len(b));
        int pos_nxt = find_pos(nxt);
        clog << db(nxt) << ' ' << db(pos_nxt) << endl;
        if (pos_nxt == 0) change({len(b) - cur, cur});
        else change({pos_nxt, len(b) - cur - pos_nxt, cur});
        ++cur;
    }
    assert(is_sorted(b.begin(), b.end()));
    assert(len(ans) <= n);
    return ans;
}

// ACUTAL SOLUTION END HERE //////////////////////////////////////////////////////////////////
// FOR HACKER/READER - you don't need to care about the part below
ans_type brute();
#ifndef testing
int main(void) {
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
    n = rand() % 10 + 1;
    a.resize(n);
    rep1(i, n) a[i - 1] = i;
    shuffle(a.begin(), a.end(), rng);
    inp << n << '\n';
    for (auto i: a) inp << i << ' ';
}
int main(void) {
    rep1(testcase, 10000) {
        gen_test(testcase);
        solve();
        // auto ans = solve(); 
        // auto br = brute(); 
        // assert(ans == br); 
        cout << "OK " << testcase << endl;
    }
    return 0;
}
#endif

ans_type brute() {
    return ans_type();
}

// vim: foldmethod=marker