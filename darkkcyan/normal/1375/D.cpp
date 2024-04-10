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
    int ntest; cin >> ntest;
    while (ntest--) {
        DB("");
        int n; cin >> n;
        vector<int> a(n);
        vector<int> cnt(n + 1);
        for (auto& i: a) {
            cin >> i;
            ++cnt[i];
        }
        
        deb(a);
        
        auto is_sorted = [&]() {
            rep(i, n - 1) if (a[i] > a[i + 1]) return false;
            return true;
        };
        
        if (is_sorted()) {
            clog << "sorted " << endl;
            cout << "0\n\n";
            continue;
        }
        
        
        auto get_mex = [&]() {
            rep(i, n) if (!cnt[i]) return i;
            return n;
        };
        
        vector<int> ans;
        
        auto add = [&](int pos) {
            int mx = get_mex();
            --cnt[a[pos]];
            a[pos] = mx;
            ++cnt[a[pos]];
            deb("add", pos);
            ans.push_back(pos);
        };
        
        auto assign_till_max_mex = [&]() {
            while (true) {
                deb(a);
                int mx = get_mex();
                deb(mx);
                if (mx == n) break;
                assert(mx != a[mx]);
                add(mx);
            }
        };
        
        assign_till_max_mex();
        
        while (!is_sorted()) {
            int diff_pos = 0;
            while (diff_pos < n and diff_pos == a[diff_pos]) ++diff_pos;
            assert(diff_pos < n);
            add(diff_pos);
            deb(diff_pos);
            assign_till_max_mex();
        }
        
        cout << len(ans) << '\n';
        for (auto i: ans) cout << i + 1 << ' ';
        cout << '\n';
        
    }

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker