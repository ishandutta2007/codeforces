// vim: foldmethod=marker
#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define rand __rand
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
template<class T = int> T rand(T range = numeric_limits<T>::max()) { return (T)(rng() % range); }

/*{{{*/
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
int debug = 1;
#define DB(...) stringstream CONCAT(ss, __LINE__); CONCAT(ss, __LINE__) << __VA_ARGS__; debug_block CONCAT(dbbl, __LINE__)(CONCAT(ss, __LINE__).str())
#else
int debug = 0;
#define DB(...)
#endif
int db_level = 0;
#define clog if (debug) cerr << string(db_level * 2, ' ')
struct debug_block {
    string name;
    debug_block(const string& name_): name(name_) { clog << "{ " << name << endl; ++db_level; }
    ~debug_block() { --db_level; clog << "} " << name << endl; }
};
#define deb(...) "[" << #__VA_ARGS__ << "] = [" << __VA_ARGS__ << "]"
#define debln(...)  clog << "[" << #__VA_ARGS__ << "] = [" << __VA_ARGS__ << "]" << endl
#define _ << ", " <<
template<class U, class V>
auto& operator<<(ostream& out, const pair<U, V>& p) { return out << "(" << p.first _ p.second << ")"; }
template<class A, class B>
auto& operator<<(ostream& out, const tuple<A, B>& t) { return out << "(" << get<0>(t) _ get<1>(t) << ")"; }
template<class A, class B, class C>
auto& operator<<(ostream& out, const tuple<A, B, C>& t) { return out << "(" << get<0>(t) _ get<1>(t) _ get<2>(t) << ")"; }
template<class T> auto& operator<<(ostream& out, const vector<T>& container) { 
    out << "{";
    if (len(container)) out << container[0];
    rep1(i, len(container) - 1) out _ container[i];
    return out << "}";
}
template<class x> vector<typename x::value_type> $v(const x& a) { return vector<typename x::value_type>(a.begin(), a.end()); }
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> $v(u a, u b) { return vector<ptrtype(u)>(a, b); }
/*}}}*/

typedef multiset<char> str;

struct cmp_str {
    bool operator()(const str& u, const str& v) const {
        if (len(u) == len(v)) return u < v;
        return len(u) < len(v);
    }
};

multiset<str, cmp_str> ask(int l, int r) { // [l, r)
    cout << "? " << l + 1 << ' ' << r << endl;
    multiset<str, cmp_str> ans;
    int cnt = r - l;
    rep(i, cnt * (cnt + 1) / 2) {
        string s; cin >> s;
        ans.emplace(s.begin(), s.end());
    }
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    auto all = ask(0, n);
    if (n == 1) {
        cout << "! " << *all.begin()->begin() << endl;
        return 0;
    }
    for (auto i: ask(1, n)) all.erase(all.find(i));

    for (auto i: all) debln(string(i.begin(), i.end()));

    string ans;
    for (auto u = all.rbegin(), v = next(u); v != all.rend(); ++u, ++v) {
        auto x = *u, y = *v;
        debln(string(x.begin(), x.end()) _ string(y.begin(), y.end()));
        for (auto i: y) x.erase(x.find(i));
        ans += *x.begin();
    }
    ans += *all.begin()->begin();
    reverse(ans.begin(), ans.end());
    cout << "! " << ans << endl;

    return 0;
}