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
int __db_level = 0;
#define clog if (debug) cerr << string(__db_level * 2, ' ')
struct debug_block {
    string name;
    debug_block(const string& name_): name(name_) { clog << "{ " << name << endl; ++__db_level; }
    ~debug_block() { --__db_level; clog << "} " << name << endl; }
};
#define deb(...) "[" << #__VA_ARGS__ << "] = [" << __VA_ARGS__ << "]"
#define debln(...)  clog << "[" << #__VA_ARGS__ << "] = [" << __VA_ARGS__ << "]" << endl
#define _ << ", " <<
template<class U, class V>
ostream& operator<<(ostream& out, const pair<U, V>& p) { return out << "(" << p.first _ p.second << ")"; }
template<class A, class B>
ostream& operator<<(ostream& out, const tuple<A, B>& t) { return out << "(" << get<0>(t) _ get<1>(t) << ")"; }
template<class A, class B, class C>
ostream& operator<<(ostream& out, const tuple<A, B, C>& t) { return out << "(" << get<0>(t) _ get<1>(t) _ get<2>(t) << ")"; }
template<class T> ostream& operator<<(ostream& out, const vector<T>& container) { 
    out << "{";
    if (len(container)) out << container[0];
    rep1(i, len(container) - 1) out _ container[i];
    return out << "}";
}
template<class x> vector<typename x::value_type> $v(const x& a) { return vector<typename x::value_type>(a.begin(), a.end()); }
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> $v(u a, u b) { return vector<ptrtype(u)>(a, b); }
/*}}}*/
// ACTUAL SOLUTION BELOW ////////////////////////////////////////////////////////////

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    rep1(testcase, ntest) {
        string s; cin >> s;
        if (len(s) == 1) {
            cout << "YES\n";
            rep(i, 26) cout << char(i + 'a');
            cout << '\n';
            continue;
        }
        set<int> adj[26];
        bool ok = true;
        rep1(i, len(s) - 1) {
            int u = s[i  -1] - 'a';
            int v = s[i] - 'a';
            if (adj[u].count(v)) continue;
            if (u == v or len(adj[u]) == 2 or len(adj[v]) == 2) {
                ok = false;
                break;
            }
            adj[u].insert(v);
            adj[v].insert(u);
        }
        if (!ok) {
            cout << "NO\n";
            continue;
        }

        int start = 0;
        while (start < 26 and len(adj[start]) != 1) ++start;
        if (start == 26) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";

        set<int> has;
        while (1) {
            cout << char('a' + start);
            has.insert(start);
            if (len(adj[start]) == 0) break;
            int nxt = *adj[start].begin();
            adj[nxt].erase(start);
            start = nxt;
        }
        rep(i, 26)
            if (!has.count(i)) cout << char(i + 'a');
        cout << '\n';
    }

    return 0;
}