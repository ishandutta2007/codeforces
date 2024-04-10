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
int qr_left;
template<class Container>
int ask(const Container& u) {
    if (!len(u)) return 1;
    --qr_left;
    cout << "? " << len(u) << ' ' ;
    for (auto i: u) {
        assert(1 <= i and i <= n);
        cout << i << ' ';
    }
    cout << endl;
    int ans; cin >> ans;
    return ans;
}

int ask_range(int l, int r) {
    vector<int> cont;
    for (int i = l; i <= r; ++i)  cont.push_back(i);
    return ask(cont);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        qr_left = 12;
        cin >> n  >> k;
        vector<vector<int>> s(k);
        rep(i, k) {
            int l; cin >> l;
            s[i].resize(l);
            rep(f, l) {
                cin >> s[i][f];
            }
        }
        
        int max_all = ask_range(1, n);
        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            if (ask_range(l, mid) == max_all) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        
        vector<int> ans;
        rep(i, k) {
            bool contains = false;
            for (auto x: s[i]) if (x == l) {
                contains = true;
                break;
            }
            if (!contains) {
                ans.push_back(max_all);
                continue;
            }
            set<int> inv;
            rep(x, n) inv.insert(x + 1);
            for (auto x: s[i]) inv.erase(x);
            ans.push_back(ask(inv));
        }
        cout << "! ";
        for (auto i: ans) cout << i << ' ' ;
        cout << endl;
        string ok; cin >> ok;
    }

    return 0;
}

// Remember:
// - Multitest? Refreshing data!!!
// vim: foldmethod=marker