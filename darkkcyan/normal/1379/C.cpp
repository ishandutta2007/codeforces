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

llong solve() {
    DB("test");
    int n, m; cin >> n >> m;
    vector<pair<int, int>> a(m);
    for (auto& i: a) cin >> i.first >> i.second;
    
    sort(a.rbegin(), a.rend());
    if (n == 1) return a[0].first;
    vector<llong> pref_sum(m + 1);
    rep(i, m) pref_sum[i + 1] = pref_sum[i] + a[i].first;
    
    auto find_bigger = [&](int l, int r, int what) -> int {
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (a[mid].first > what) l = mid;
            else r = mid - 1;
        }
        return l;
    };
    
    deb(a);
    llong ans = 0;
    rep(i, m) {
        DB(""; deb(i, a[i]));
        llong cur = a[i].first;
        int left = n - 1;
        if (i and a[0].first > a[i].second) {
            auto u = find_bigger(0, i - 1, a[i].second) + 1;
            u = min(u, left);
            cur += pref_sum[u];
            left -= u;
            deb(i, u, left);
        }
        
        if (i < m - 1 and a[i + 1].first > a[i].second) {
            auto v = find_bigger(i + 1, m - 1, a[i].second) + 1;
            int cnt = v - i - 1;
            cnt = min(cnt, left);
            v = i + cnt + 1;
            deb(i, cnt, v);
            cur += pref_sum[v] - pref_sum[i + 1];
            left -= cnt;
        }
        deb(cur);
        cur += 1ll * left * a[i].second;
        deb(left, cur);
        ans = max(ans, cur);
    }
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int ntest; cin >> ntest;
    while (ntest--) {
        cout << solve() << '\n';
    }
    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker