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

const int maxn = 1010101;
int n, m;
vector<string> s;
int dp[maxn][1 << 3];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    if (n >= 4 and m >= 4) {
        cout << -1;
        return 0;
    }
    
    if (n == 1 or m == 1) {
        cout << 0;
        return 0;
    }
    
    s.resize(n);
    rep(i, n) cin >> s[i];
    
    auto get = (n < m) ? [](int i) {
        int ans = 0;
        rep(f, m) ans = ans << 1 | (s[f][i] == '1');
        return ans;
    } : [](int i) {
        int ans = 0;
        rep(f, m) ans = ans << 1 | (s[i][f] == '1');
        return ans;
    };
    
    if (n < m) swap(n, m);
    
    int mask = get(0);
    rep(i, (1 << m)) {
        dp[0][i] = __builtin_popcount(i ^ mask);
    }
    
    rep1(i, n - 1) {
        mask = get(i);
        rep(sm, (1 << m)) {
            dp[i][sm] = n * m + 10;
            rep(prev_m, (1 << m)) {
                bool ok = true;
                int new_mask = prev_m ^ sm;
                rep(f, m - 1) {
                    if (!__builtin_parity((new_mask >> f) & 3)) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) continue;
                
                dp[i][sm] = min(dp[i][sm], dp[i - 1][prev_m] + __builtin_popcount(sm ^ mask));
            }
        }
    }
    cout << *min_element(dp[n - 1], dp[n - 1] + (1 << m));

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker