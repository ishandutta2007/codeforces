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
int n, m, k;

int val[maxn * 8], lz[maxn * 8];
void propagate(int i) {
    if (!lz[i]) return ;
    val[i] += lz[i];
    if (2 * i < maxn * 8) lz[2 * i] += lz[i];
    if (2 * i + 1 < maxn * 8) lz[2 * i + 1] += lz[i];
    lz[i] = 0;
}

void add(int ql, int qr, int delta, int i = 1, int l = 0, int r = 2 * n + 10) { 
    propagate(i);
    if (l >= r) return ;
    if (ql >= r or l >= qr) return ;
    if (ql <= l and r <= qr) {
        lz[i] += delta;
        propagate(i);
        return ;
    }
    int mid = (l + r) / 2;
    add(ql, qr, delta, i * 2, l, mid);
    add(ql, qr, delta, i * 2 + 1, mid, r);
    val[i] = max(val[i * 2], val[2 * i + 1]);
}

void build(int i = 1, int l = 0, int r = 2 * n + 10) {
    if (l >= r) return ;
    lz[i] = 0;
    if (r - l == 1) {
        val[i] = l - n;
        return ;
    }
    int mid = (l + r) / 2;
    build(i * 2, l, mid);
    build(i * 2 + 1, mid, r);
    val[i] = max(val[2 * i], val[2 * i + 1]);
}

int query(int ql, int qr, int i = 1, int l = 0, int r = 2 * n + 10) {
    propagate(i);
    if (l >= r) return 0;
    if (ql >= r or l >= qr) return 0;
    if (ql <= l and r <= qr) return val[i];
    int mid = (l + r) / 2;
    return max(query(ql, qr, i * 2, l, mid), query(ql, qr, 2 * i + 1, mid, r));
}

int pos(const pair<int, int>& u) {
    return u.first + abs(u.second - k);
}
struct cmp {
    bool operator()(const pair<int, int>& u, const pair<int, int>& v) const {
        int pu = pos(u);
        int pv = pos(v);
        if (pu == pv) return u < v;
        return pu < pv;
    }
};
set<pair<int, int>, cmp> has;
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k >> m;
    build();
    deb(val[1]);
    rep(_, m) {
        int r, c; cin >> c >> r;
        int ps = pos({r, c});
        DB(""; deb(r, c, ps));
        if (has.count({r, c})) {
            clog << "removing" << endl;
            add(0, ps, - 1);
            has.erase({r, c});
        } else {
            clog << "inserting" << endl;
            add(0, ps, 1);
            has.emplace(r, c);
        }
        if (!has.size()) cout << "0\n";
        else cout << max(0, query(0, pos(*--has.end()))) << '\n';
    }

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker