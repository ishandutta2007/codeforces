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

vector<int> brute(int n) {
    vector<int> ans(n - 1, 100);

    rep(i, (1 << n)) {
        if (__builtin_popcount(i) < 2) continue;
        vector<int> nums;
        rep(f, n) if ((i >> f) & 1) {
            nums.push_back(f + 1);
        }
        int cur_ans = 0;
        for (auto f: nums) for (auto g: nums) {
            if (f == g) continue;
            cur_ans = max(cur_ans, __gcd(f, g));
        }
        auto &temp = ans[__builtin_popcount(i) - 2];
        temp = min(temp, cur_ans);
    }
    return ans;
}

vector<int> solve(int n) {
    multiset<int> ans;
    vector<int> largest_div(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
        for (int f = i * 2; f <= n; f += i) largest_div[f] = i;
    }
    for (int i = 2; i <= n; ++i) ans.insert(largest_div[i]);
    return $v(ans);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef LOCAL
    int n;
    cin >> n;
    for (auto i: solve(n)) cout << i << ' ';
#else
    for (int i = 2; i < 20; ++i) {
        DB(""; deb(i));
        deb(brute(i));
        deb($v(solve(i)));
    }
    // for (int i = 2; i < 100; ++i) { 
        // deb(i, solve(i)); 
    // } 
#endif


    return 0;
}

// vim: foldmethod=marker