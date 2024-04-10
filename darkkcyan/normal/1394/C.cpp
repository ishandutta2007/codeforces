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

const int maxn = 301010;
const int maxa = 501010;

struct range {
    int low, high;
    range(int l = INT_MAX, int h = INT_MIN): low(l), high(h) {}
    
    void extend(int p) {
        low = min(low, p);
        high = max(high, p);
    }
    
    friend range operator+(const range& u, const range& v) {
        return range(min(u.low, v.low), max(u.high, v.high));
    }
    
    range move(int delta)const  {
        return range(low + delta, high + delta);
    }
    
    int length() const {
        return high - low;
    }
    
    int mid() const {
        return low + (high - low) / 2;
    }
};

int n;
pair<int, int> points[maxn];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    
    rep(i, n) {
        string s; cin >> s;
        deb(s);
        int cntb = (int)count(s.begin(), s.end(), 'B');
        points[i] = {cntb, len(s) - cntb};
    }
    
    range diag_r, hor_r, ver_r;
    
    rep(i, n) {
        diag_r.extend(points[i].second - points[i].first);
        hor_r.extend(points[i].first);
        ver_r.extend(points[i].second);
    }
    
    tuple<int, int, int> ans(INT_MAX, -1, -1);
    for (int diff = -maxa; diff <= maxa; ++diff) {
        int base = max(abs(diff - diag_r.low), abs(diff - diag_r.high));
        auto comb = hor_r.move(diff) + ver_r;
        int r = max(base, (comb.length() + 1) / 2);
        rep(i, 2) {
            int y = comb.low + (comb.length() + i) / 2;
            int x = y - diff;
            if (x == 0 and y == 0) continue;
            ans = min(ans, {r, x, y});
        }
    }
    
    deb(ans);
    
    cout << get<0>(ans) << '\n';
    rep(i, get<1>(ans)) cout << 'B';
    rep(i, get<2>(ans)) cout << 'N';
    

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker