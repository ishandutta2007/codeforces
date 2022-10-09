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

struct hole {
    int lcnt, rcnt;
    hole(int l = 0, int r = 0) : lcnt(l), rcnt(r) {}

    int sum() {
        return lcnt + rcnt;
    }
};

struct node_data {
    int inner_max;
    hole head, tail;

    node_data() {}

    node_data(const hole& single_hole)
        : inner_max(-1)
        , head(single_hole)
        , tail(single_hole) {}

    node_data(int inner_max_, const hole& u, const hole& v)
        : inner_max(inner_max_)
        , head(u), tail(v) {}

    node_data(const hole& h, const hole& t)
        : node_data(0, h, t) {}

    bool is_single() {
        return inner_max == -1;
    }

    int overall_max() {
        return max({inner_max, head.sum(), tail.sum()});
    }
};

node_data operator+(const hole& u, const hole& v) {
    if (u.rcnt == 0 or v.lcnt == 0) {
        return node_data(hole(u.lcnt + v.lcnt, u.rcnt + v.rcnt));
    }

    return node_data(u, v);
}

node_data operator+(node_data u, node_data v) {
    auto temp = u.tail + v.head;
    if (u.is_single() and v.is_single()) {
        return temp;
    }

    if (u.is_single()) {
        if (!temp.is_single()) {
            v.inner_max = max(v.inner_max, temp.tail.sum());
        }
        v.head = temp.head;
        return v;
    }
    if (v.is_single()) {
        if (!temp.is_single()) {
            u.inner_max = max(u.inner_max, temp.head.sum());
        }
        u.tail = temp.tail;
        return u;
    }

    u.inner_max = max({u.inner_max, v.inner_max, temp.overall_max()});
    u.tail = v.tail;
    return u;
}

const int maxn = 500010;
node_data it[maxn * 4][2];
bool need_swap[maxn * 4];

int n;
string s;

void refresh(int i) {
    it[i][0] = it[i * 2][0] + it[i * 2 + 1][0];
    it[i][1] = it[i * 2][1] + it[i * 2 + 1][1];
}

void build(int i = 1, int l = 0, int r = n) {
    if (l >= r) return ;
    need_swap[i] = 0;
    if (r - l == 1) {
        it[i][0] = node_data(hole(s[l] == '>', s[l] == '<'));
        it[i][1] = node_data(hole(s[l] == '<', s[l] == '>'));
        return ;
    }

    int mid = (l + r) / 2;
    build(i* 2, l, mid);
    build(i * 2 + 1, mid, r);
    refresh(i);
}

void propagate(int i) {
    if (!need_swap[i]) return ;
    swap(it[i][0], it[i][1]);
    if (2 * i < maxn * 4) need_swap[2 * i] ^= 1;
    if (2 * i + 1 < maxn * 4) need_swap[2 * i + 1] ^= 1;
    need_swap[i] = 0;
}

void inverse(int il, int ir, int i = 1, int l = 0, int r = n) {
    propagate(i);
    if (l >= r or il >= r or l >= ir) return ;
    if (il <= l and r <= ir) {
        need_swap[i] = 1;
        propagate(i);
        return ;
    }

    int mid = (l + r) / 2;
    inverse(il, ir, i * 2, l, mid);
    inverse(il, ir, i * 2 + 1, mid, r);
    refresh(i);
}

node_data get(int gl, int gr, int i = 1, int l = 0, int r = n) {
    propagate(i);
    if (l >= r or gl >= r or l >= gr) return node_data(hole());
    if (gl <= l and r <= gr) return it[i][0];
    int mid = (l + r) / 2;
    return get(gl, gr, i * 2, l, mid) + get(gl, gr, i * 2 + 1, mid, r);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin >> n >> q;
    cin >> s;
    build();
    while (q--) {
        int l, r; cin >> l >> r;
        --l;
        inverse(l, r);
        cout << get(l, r).overall_max() << '\n';
    }

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker