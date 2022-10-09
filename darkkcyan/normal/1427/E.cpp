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

using ans_type = vector<tuple<llong, char, llong>>;

llong n;
void read() {
    cin >> n;
}

void print_ans(ostream& cout, const ans_type& ans) {
    cout << len(ans) << '\n';
    for (auto [u, s, v]: ans) {
        cout << u << ' ' << s << ' ' << v << '\n';
    }
}

tuple<llong, llong, llong> ex_gcd(llong a, llong b) {
    if (a == 0) return {0, 1, b};
    if (b == 0) return {1, 0, a};
    auto [x, y, g] = ex_gcd(b, a % b);
    llong new_x = y;
    llong new_y = x - (a / b) * y;
    return {new_x, new_y, g};
}

ans_type solve() {
    set<llong> vals;
    vals.emplace(n);
    ans_type ans;
    auto add_op = [&](llong u, char s, llong v) {
        assert(vals.count(u));
        assert(vals.count(v));
        llong new_num = s == '+' ? u + v : u ^ v;
        if (!vals.count(new_num)) {
            vals.insert(new_num);
            ans.emplace_back(u, s, v);
        }
    };
    int big_bit = 63 - __builtin_clzll(n);
    llong a = n;
    llong b = (n << big_bit) ^ a;
    for (llong cur = n, i = 0; i < big_bit; cur <<= 1, ++i) {
        add_op(cur, '+', cur);
    }
    add_op(n << big_bit, '^', n);
    clog << db(a) << db(b) << endl;
    
    auto [x, y, g] = ex_gcd(a, b);
    clog << db(x) << db(y) << db(g) << endl;
    assert(g == 1);
    assert(y != 0);
    if (y > 0) {
        llong t = y / a + 1;
        y -= a * t;
        x += b * t;
    }
    assert(x > 0);
    if (y & 1) {
        y -= a;
        x += b;
    }
    clog << db(x) << db(y) << db(g) << endl;
    
    auto make_mul = [&](llong base, llong mul) {
        llong cur = 0;
        for (; mul > 0; mul >>= 1) {
            if (mul & 1) {
                if (cur) add_op(cur, '+', base);
                cur += base;
            }
            add_op(base, '+', base);
            base *= 2;
        }
    };
    make_mul(a, x);
    make_mul(b, -y);
    add_op(a * x, '^', b * -y);
    
#ifdef testing
    assert(vals.count(1));
    assert(len(vals) < 100'000);
#endif
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
    n = cur_test * 2 + 1;
    inp << n << endl;
}
int main(void) {
    rep1(testcase, 10000) {
        gen_test(testcase);
        solve();
        cout << "OK " << testcase << endl;
    }
    return 0;
}
#endif

ans_type brute() {
    return ans_type();
}

// vim: foldmethod=marker