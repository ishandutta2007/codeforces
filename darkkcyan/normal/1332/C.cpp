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

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest ;cin >> ntest;
    while (ntest--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        vector<int> dsu(n);
        vector<array<int, 26>> cnt(n);

        rep(i, n) {
            dsu[i] = i;
            cnt[i][s[i] - 'a'] ++;
        }

        function<int(int)> find_set = [&](int u) {
            return u == dsu[u] ? u : dsu[u] = find_set(dsu[u]);
        };

        auto join = [&](int u, int v) {
            u = find_set(u);
            v = find_set(v);
            if (u == v) return ;
            dsu[u] = v;
            rep(i, 26) cnt[v][i] += cnt[u][i];
        };

        for (int l = 0, r = n - 1; l < r; ++l, --r)
            join(l, r);

        for (int i = 0; i + k < n; ++i)
            join(i, i + k);

        int ans = 0;
        rep(i, n) {
            if (find_set(i) != i) continue;
            int sum = 0;
            int mx = 0;
            rep(f, 26)  {
                sum += cnt[i][f];
                mx = max(mx, cnt[i][f]);
            }
            ans += sum - mx;
        }
        cout << ans << '\n';
    }

    return 0;
}

// vim: foldmethod=marker