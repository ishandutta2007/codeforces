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
const int maxm = maxn;
int n, m, k;
pair<int, int> edges[maxm];
vector<int> gr[maxn];

vector<int> roots;
int spec_id[10][10];
bool invalid[10][10];
int ans = 0;

bool incompatible[10][10][10][10];
void brute(int i) {
    DB(""; deb(i));
    if (i > k) {
        deb(roots);
        ++ans;
        return ;
    }
    
    rep(f, i) {
        bool ok = true;
        if (invalid[i][f]) continue;
        rep1(x, i - 1) {
            if (incompatible[i][f][x][roots[x - 1]]) {
                ok = false;
                break;
            }
        }
        deb(f);
        if (!ok) continue;
        roots.push_back(f);
        brute(i + 1);
        roots.pop_back();
    }
}

bitset<maxn> mark[10][10];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    rep(i, m) {
        int u, v, c; cin >> u >> v >> c;
        edges[c] = {u, v};
    }
    
    rep1(i, m) {
        auto [u, v] = edges[i];
        gr[u].push_back(v);
    }
    
    // rep1(i, n) deb(i, gr[i]); 
    
    rep1(i, n) {
        int u = len(gr[i]);
        rep(f, len(gr[i])) {
            int v = gr[i][f];
            deb(u, f, v);
            if (mark[u][f][v]) invalid[u][f] = true;
            else mark[u][f][v] = true;
        }
    }
    
    rep1(i, k) rep(f, i)
        for (int u = i + 1; u <= k; ++u) rep(v, u)
        if ((mark[i][f] & mark[u][v]).any()) {
            incompatible[i][f][u][v] = incompatible[u][v][i][f] = true;
            deb(i, f, u, v);
        }
    
    
    brute(1);
    cout << ans;

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker