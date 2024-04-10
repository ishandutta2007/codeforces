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

int n, k;
const int maxn = 1010;
bitset<maxn> unmask;

bitset<maxn> rotate(bitset<maxn> temp, int num) {
    temp <<= num;
    temp |= (temp & unmask >> num);
    return temp;
}

bitset<maxn> dp[2];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    unmask.set();
    rep(i, k) unmask[i] = 0;

    dp[1][0] = 1;
    
    llong sum = 0;
    rep(i, n) {
        bool s = i & 1;
        DB(""; deb(i, s));
        llong r, b; cin >> r >> b;
        deb(r, b);
        llong cur = r + b;
        sum += cur;

        dp[s].reset();
        rep(red, min(k, (int)r + 1)) {
            llong blue = (cur - red) % k;
            deb(cur, red, blue);
            if (blue > b) continue;
            
            int f = red;
            rep(prev_red, k) {
                if (dp[!s][prev_red])  {
                    deb(prev_red, f);
                    dp[s][f] = 1;
                }
                ++f;
                if ( f== k) f = 0;
            }
        }
    }

    llong ans = 0;
    bool s = ~n & 1;
    deb(s);
    rep(red, k) {
        if (!dp[s][red]) continue;
        deb(red);
        ans = max(ans, (sum - red) / k);
    }
    cout << ans;

    return 0;
}

// vim: foldmethod=marker