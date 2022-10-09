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

const int maxn = 2020;
int n, m;

string board[maxn];

int cnt_mj[maxn][maxn], cnt_mn[maxn][maxn];
int dp[maxn][maxn];

template<class Container2D>
int get(const Container2D& u, int i, int j, int def = 0) {
    if (i < 0 or j < 0 or i >= n or j >= m) return def;
    return u[i][j];
}


int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    rep(i, n) cin >> board[i];
    
    rep(i, n) rep(f, m) {
        cnt_mj[i][f] = 1 + (get(board, i - 1, f - 1) == board[i][f] ? get(cnt_mj, i - 1, f - 1) : 0);
        cnt_mn[i][f] = 1 + (get(board, i - 1, f + 1) == board[i][f] ? get(cnt_mn, i - 1, f + 1) : 0);
        
        int u = min(cnt_mj[i][f], cnt_mn[i][f]);
        int v = get(board, i - 1, f) == board[i][f] ? get(dp, i - 1, f) : 0;
        if (v + 1 <= u) {
            dp[i][f] = v;
            if (get(cnt_mn, i - v, f - v) >= v + 1 and get(cnt_mj, i - v, f + v) >= v + 1) 
                dp[i][f] ++;
        } else dp[i][f] = u;
        deb(i, f, cnt_mj[i][f], cnt_mn[i][f], dp[i][f]);
    }
    
    llong ans = 0;
    rep(i, n) rep(f, m) ans += dp[i][f];
    cout << ans;
    

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker