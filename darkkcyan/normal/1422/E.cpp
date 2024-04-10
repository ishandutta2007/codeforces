// #define multitest 
// #define testing 
// #define print_brute 

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

using ans_type = vector<pair<int, string>>;

string s;
void read() {
    cin >> s;
}

void print_ans(ostream& cout, const ans_type& ans) {
    for (auto& [l, cur]: ans) {
        cout << l << ' ' << cur << '\n';
    }
}

ans_type solve() {
    string cur_rev_ans;
    vector<char> last_diff;
    auto add_char = [&](char ch) {
        int pos = len(cur_rev_ans);
        last_diff.emplace_back();
        if (!len(cur_rev_ans)) {
            last_diff[pos] = 0;
        } else if (cur_rev_ans.back() == ch) last_diff[pos] = last_diff[pos - 1];
        else last_diff[pos] = cur_rev_ans.back();
        cur_rev_ans += ch;
    };
    
    auto pop_char = [&] {
        last_diff.pop_back();
        cur_rev_ans.pop_back();
    };
    
    ans_type ans;
    auto add_ans = [&] {
        ans.emplace_back(len(cur_rev_ans), "");
        if (len(cur_rev_ans) <= 10) {
            ans.back().second = cur_rev_ans;
        } else {
            ans.back().second = cur_rev_ans.substr(0, 2) + "..." + cur_rev_ans.substr(len(cur_rev_ans) - 5);
        }
        reverse(ans.back().second.begin(), ans.back().second.end());
    };
    
    vector<pair<char, int>> groups;
    for (auto ch: s) {
        if (!len(groups) or groups.back().first != ch)
            groups.emplace_back(ch, 0);
        ++groups.back().second;
    }
    
    reverse(groups.begin(), groups.end());
    for (auto [ch, le]: groups) {
        add_char(ch);
        add_ans();
        rep(i, le - 1) {
            if (i & 1) add_char(ch);
            else if (last_diff.back() > ch) add_char(ch);
            else pop_char();
            add_ans();
        }
    }
    
    reverse(ans.begin(), ans.end());
    
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
#endif
    }
    return 0;
}
#else
void gen_test() {
    ofstream inp("main.inp");
    
}
int main(void) {
    rep1(testcase, 10000) {
        gen_test();
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