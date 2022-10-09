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
int n;
int a[maxn], b[maxn];
vector<int> pos[maxn];

int dsu[maxn * 2], cnt[maxn * 2];
int find_set(int u) { return dsu[u] == u ? u : dsu[u] = find_set(dsu[u]); }
void join(int u, int v) {
    clog << "Unite " << u / 2 << ':' << u % 2  << ' ' << v / 2 << ':' << v % 2 << endl;
    u = find_set(u);
    v = find_set(v);
    if (u == v) return ;
    dsu[u] = v;
    cnt[v] += cnt[u];
}

optional<vector<int>> solve() {
    DB("test");
    cin >> n;
    
    rep1(i, n) {
        pos[i].clear();
    }
    rep(i, n) {
        dsu[i * 2] = i * 2;
        dsu[i * 2 + 1] = i * 2 + 1;
        cnt[i * 2] = 0;
        cnt[i * 2 + 1] = 1;
    }
    
    rep(i, n) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    
    rep(i, n) {
        cin >> b[i];
        pos[b[i]].push_back(i);
    }
    deb($v(a, a + n));
    deb($v(b, b + n));
    
    rep1(i, n) {
        DB(""; deb(i));
        if (len(pos[i]) != 2) {
            deb(i, pos[i]);
            clog << "len pos != 2" << endl;
            return {};
        }
        int u = pos[i][0], v = pos[i][1];
        if (u == v) continue;
        if ((a[u] == i) == (a[v] == i)) {
            join(u * 2 + 1, v * 2);
            join(u * 2, v * 2 + 1);
        } else {
            join(u * 2, v * 2);
            join(u * 2 + 1, v * 2 + 1);
        }
    }
    
    vector<bool> considered(2 * n);
    vector<bool> picked(2 * n);
    rep(i, n) {
        int u = find_set(2 * i), v = find_set(2 * i + 1);
        if (u == v) {
            deb(i, u / 2, u % 2, v / 2, v % 2);
            clog << "conflict" << endl;
            return {};
        }
        if (considered[u]) {
            assert(considered[v]);
            continue;
        }
        assert(!considered[v]);
        if (cnt[u] < cnt[v]) picked[u] = true;
        else picked[v] = true;
        considered[u] = true;
        considered[v] = true;
    }
    
    vector<int> ans;
    rep(i, n) {
        if (picked[find_set(2 * i + 1)]) ans.push_back(i);
    }
    
    return {ans};
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        if (auto ans = solve()) {
            cout << ans->size() << '\n';
            for (auto i: *ans) {
                cout << i + 1 << ' ';
            }
            cout << '\n';
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker