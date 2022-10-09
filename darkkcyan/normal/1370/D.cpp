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

const int maxn = 201010;
const int inf = INT_MAX;
int n, k;
int a[maxn];

int max_len(int cost, int* from, int* to) {
    DB(""; deb(cost, from - a));
    int l = (int)(to - from);
    vector<int> dp(l + 1);
    dp[0] = 0;
    dp[1] = from[0] <= cost;
    rep1(i, l - 1) {
        dp[i + 1] = dp[i];
        if (from[i] <= cost) dp[i + 1] = max(dp[i + 1], dp[i - 1] + 1);
    }
    deb(dp);
    return dp.back();
}

bool ok(int cost) {
    if (k & 1) {
        return max_len(cost, a, a+ n) >= (k + 1)/ 2 or max_len(cost, a + 1, a + n - 1) >= k / 2;
    }
    else return max_len(cost, a, a + n - 1) >= k /2 or max_len(cost, a + 1, a + n) >= k / 2;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    rep(i, n) {
        cin >> a[i];
    }

    vector<int> cpy_a(a, a+ n);
    sort(cpy_a.begin(), cpy_a.end());

    int low = 0, high = n - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (ok(cpy_a[mid])) high = mid;
        else low = mid + 1;
    }
    cout << cpy_a[low];

    return 0;
}

// Remember:
// - Multitest? Refreshing data!!!
// vim: foldmethod=marker