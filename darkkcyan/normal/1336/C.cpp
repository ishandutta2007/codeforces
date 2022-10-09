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

const int maxn = 3030;
const llong mod = 998244353;
string s, t;
llong dp[maxn][maxn * 2];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s >> t;

    llong ans = 0;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    rep1(length, len(s) - 1) {
        char cur_s = s[length];
        rep(built, len(t) + 1) {
            dp[length][built] = dp[length - 1][built];
            if (built) {
                if (cur_s == t[len(t) - built]) 
                (dp[length][built] += dp[length - 1][built - 1]) %= mod;
            } else {
                (dp[length][built] += dp[length - 1][built]) %= mod;
            }
        }
        deb(length, dp[length][len(t)]);
        (ans += dp[length][len(t)]) %= mod;
    }
    deb(ans);

    memset(dp, 0, sizeof(dp));
    rep(i, len(t)) if (s[0] == t[i]) dp[1][i] = 1;
    if (len(t) == 1) (ans += dp[1][0]) %= mod;

    for (int length = 2; length <= len(s); ++length) {
        int cur = s[length - 1];
        rep(left, len(t)) {
            int right = left + length - 1;
            if (t[left] == cur) dp[length][left] = dp[length - 1][left + 1];
            if (right >= len(t) or t[right] == cur)
                (dp[length][left] += dp[length - 1][left]) %= mod;
        }
        if (length >= len(t)) (ans += dp[length][0]) %= mod;
        if (length >= len(t))
            deb(length, dp[length][0]);
    }

    cout << (ans * 2) % mod;

    return 0;
}

// vim: foldmethod=marker