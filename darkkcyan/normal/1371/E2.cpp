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

int n, p;
map<llong, int> cnt;

template<bool need_check_div>
bool valid_x(llong x) {
    rep(i, n) {
        auto it = cnt.upper_bound(x + i);
        if (it == cnt.begin()) return false;
        --it;
        deb(x, i,  *it);
        if (it->second - i < 1) return false;
        if (need_check_div and (it->second - i) % p == 0) return false;
    }
    return true;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> p;
    llong max_a = 0;
    rep(i, n) {
        llong u; cin >> u;
        cnt[u] ++;
        max_a = max(max_a, u);
    }

    cnt[0] = 0;

    for (auto it = cnt.begin(), nxt = next(it); nxt != cnt.end(); ++it, ++nxt)
        nxt->second += it->second;

    deb($v(cnt));

    llong lower_x, upper_x;
    {
        llong l = 1, r = max_a * 2;
        while (l < r) {
            llong mid = (l + r) / 2;
            if (valid_x<false>(mid)) r = mid;
            else l = mid + 1;
        }
        deb(l, r);
        lower_x = l;
    }

    {
        llong l = lower_x - 1, r = max_a;
        while (l < r) {
            llong mid = (l + r + 1) / 2;
            if (valid_x<true>(mid)) l = mid;
            else r = mid - 1;
        }
        upper_x = l;
    }

    cout << upper_x - lower_x + 1 << '\n';
    for (llong x = lower_x; x <= upper_x; ++x) cout << x << ' ';

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker