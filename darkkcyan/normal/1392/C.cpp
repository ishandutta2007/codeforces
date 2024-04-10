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

using ans_type = llong; 
constexpr bool print_case = false;

void print_ans(const ans_type& ans) {
    cout << ans << '\n';
}

int l2(int x) {
    return 31 - __builtin_clz(x);
}

ans_type solve() {
    int n;
    cin >> n;
    vector<llong> a(n);
    for (auto& i: a) cin >> i;
    
    vector sp(l2(n) + 1, vector<pair<llong, int>>(n));
    rep(i, n) sp[0][i] = {a[i], i};
    for (int i = 0; (2 << i) <= n; ++i) {
        for (int f = 0; f + (2 << i) <= n; ++f) {
            sp[i + 1][f] = max(sp[i][f], sp[i][f + (1 << i)]);
        }
    }
    
    auto get_mx = [&](int l, int r) {
        int lv = l2(r - l);
        return max(sp[lv][l], sp[lv][r - (1 << lv)]);
    };
    
    function<llong(int, int)> process = [&](int l, int r) {
        deb(l, r);
        if (l >= r - 1) return 0ll;
        llong ans = 0ll;
        auto mx = get_mx(l, r);
        // deb(mx); 
        if (mx.second > l) {
            auto mx2 = get_mx(l, mx.second);
            ans += mx.first - mx2.first;
            ans += process(l, mx.second);
        }
        if (mx.second < r - 1) {
            auto mx2 = get_mx(mx.second + 1, r);
            ans += mx.first - mx2.first;
            ans += process(mx.second + 1, r);
        }
        deb(l, r, ans);
        return ans;
    };
    
    vector<int> st(1, n);
    for (int i = n; i--; ) {
        while (len(st) > 1 and a[st.back()] < a[i]) st.pop_back();
        st.push_back(i);
    }
    
    deb(st);
    llong ans = 0;
    for (int i = len(st) - 1; i > 0; --i) {
        deb(st[i], st[i - 1]);
        ans += process(st[i], st[i - 1]);
    }
    
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    rep1(testcase, ntest) {
        DB(""; deb(testcase));
        if (print_case) {
            cout << "Case #" << testcase << ": ";
            cerr << testcase << endl;
        }
        print_ans(solve());
    }

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker