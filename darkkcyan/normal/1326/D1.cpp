// vim: foldmethod=marker
#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define rand __rand
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
template<class T = int> T rand(T range = numeric_limits<T>::max()) { return (T)(rng() % range); }

#define CONCAT_(x, y) x##y/*{{{*/
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
int __db_level = 0;
bool __db_same_line = false;
#define clog cerr << string(!__db_same_line ? __db_level * 2 : 0, ' ')
struct debug_block {
    function<void()> fn;
    void print_name() { __db_same_line = true; fn(); clog << endl; __db_same_line = false;  }
    debug_block(function<void()> fn_): fn(fn_) { clog << "{ "; print_name(); ++__db_level; }
    ~debug_block() { --__db_level; clog << "} "; print_name(); }
};
#define DB(args...) debug_block CONCAT(dbbl, __LINE__)([=]{ clog << args; })
#define deb(...)  if (1) { (clog << "[" #__VA_ARGS__ "] = [" << __VA_ARGS__) << "]"; if (!__db_same_line) clog << endl; }
#else
#define clog if (0) cerr
#define DB(...)
#define deb(...)
#endif
template<class T>
ostream& operator,(ostream& out, const T& thing) { return out << ", " << thing; }
template<class U, class V>
ostream& operator<<(ostream& out, const pair<U, V>& p) { return (out << "(" << p.first, p.second) << ")"; }
template<class A, class B>
ostream& operator<<(ostream& out, const tuple<A, B>& t) { return (out << "(" << get<0>(t), get<1>(t)) << ")"; }
template<class A, class B, class C>
ostream& operator<<(ostream& out, const tuple<A, B, C>& t) { return (out << "(" << get<0>(t), get<1>(t), get<2>(t)) << ")"; }
template<class T> ostream& operator<<(ostream& out, const vector<T>& container) { 
    out << "{";
    if (len(container)) out << container[0];
    rep1(i, len(container) - 1) out, container[i];
    return out << "}";
}
template<class x> vector<typename x::value_type> $v(const x& a) { return vector<typename x::value_type>(a.begin(), a.end()); }
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> $v(u a, u b) { return vector<ptrtype(u)>(a, b); }/*}}}*/
// ACTUAL SOLUTION BELOW ////////////////////////////////////////////////////////////

const llong mod = (llong)(1e9 + 8181);
const llong base = 29;

template<class siter>
int longest_pref_palin(siter beg, siter end) {
    int ans = 0;
    llong hs1 = 0, rhs1 = 0;
    unsigned llong hs2 = 0, rhs2 = 0;
    
    llong pw  = 1;
    llong upw = 1;

    for (int i = 1; beg != end; ++beg, ++i, (pw *= base) %= mod, upw *= base) {
        int val = *beg - 'a' + 1;

        (hs1 = (hs1 * base) + val) %= mod;
        hs2 = (hs2 * base) + val;
        (rhs1 += val * pw) %= mod;
        rhs2 += val * upw;

        if (hs1 == rhs1 and hs2 == rhs2) {
            ans = i;
        }
    }
    return ans;
}

string solve(const string& s) {
    int l = 0, r = len(s) - 1;
    while (l < r and s[l] == s[r]) {
        ++l;
        --r;
    }

    int max_front_palin = longest_pref_palin(s.begin() + l, s.begin() + r + 1);
    int max_back_palin = longest_pref_palin(s.rbegin() + l, s.rbegin() + r + 1);
    string mid = (max_front_palin < max_back_palin) ? s.substr(r - max_back_palin + 1, max_back_palin) : s.substr(l, max_front_palin);
    return s.substr(0, l) + mid + s.substr(r + 1);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        cout << solve(s) << '\n';
    }

    return 0;
}