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

struct IT {
    int lower, upper, n;
    vector<int> it, lz;
    IT(int lower_, int upper_): lower(lower_), upper(upper_), n(upper - lower + 1), it(4 * n, 0), lz(4 * n, 0) {}
    
    void propagate(int i, int l, int r) {
        if (l < r) {
            lz[2 * i] += lz[i];
            lz[2 * i + 1] += lz[i];
        }
        it[i] += lz[i];
        lz[i] = 0;
    }
    
    void add(int al, int ar, int val, int i, int l, int r) {
        propagate(i, l, r);
        if (al > r or l > ar) return ;
        if (al <= l and r <= ar) {
            lz[i] += val;
            propagate(i, l, r);
            return ;
        }
        int mid = l + (r - l) / 2;
        add(al, ar, val, 2 * i, l, mid);
        add(al, ar, val, 2 * i + 1, mid + 1, r);
        it[i] = max(it[2 * i], it[2 * i + 1]);
    }
    
    void upd(int pos, int val, int i, int l, int r) {
        propagate(i, l, r);
        if (pos < l or pos > r) return ;
        if (l == r) {
            it[i] = val;
            return ;
        }
        int mid = l + (r - l) / 2;
        upd(pos, val, 2 * i, l, mid);
        upd(pos, val, 2 * i + 1, mid + 1, r);
        it[i] = max(it[2 * i], it[2 * i + 1]);
    }
    
    int get(int gl, int gr, int i, int l, int r) { 
        propagate(i, l, r);
        if (l > gr or gl > r) return 0;
        if (gl <= l and r <= gr) return it[i];
        int mid = l + (r - l) / 2;
        return max(get(gl, gr, 2 * i, l, mid), get(gl, gr, 2 * i + 1, mid + 1, r));
    }
    
    void add(int al, int ar, int val) { add(al, ar, val, 1, lower, upper); }
    void upd(int pos, int val) { upd(pos, val, 1, lower, upper); }
    int get(int l, int r) { return get(l, r, 1, lower, upper); }
};

int n;
vector<pair<int, int>> seg[2];

bool cmp_seg_r(const pair<int, int>& u, const pair<int, int>& v) {
    if (u.second == v.second) return u.first < v.first;
    return u.second < v.second;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, n) {
        int l, r, color; cin >> l >> r >> color;
        seg[--color].emplace_back(l, r);
    }
    
    rep(i, 2) sort(seg[i].begin(), seg[i].end(), cmp_seg_r);
    
    IT it[2] {IT(-1, len(seg[0])), IT(-1, len(seg[1]))};
    
    
    int ans = 0;
    auto upd = [&](int side, int v) {
        int prev_u = (int)(upper_bound(seg[!side].begin(), seg[!side].end(), pair(INT_MAX, seg[side][v].first - 1), cmp_seg_r) - seg[!side].begin()) - 1;
        int cur_ans = it[!side].get(-1, prev_u) + 1;
        deb(side, v, prev_u, cur_ans);
        ans = max(ans, cur_ans);
        it[side].upd(v, cur_ans);
        it[!side].add(-1, prev_u, 1);
    };
    int u = 0, v = 0;
    
    for (; u < len(seg[0]); ++u) {
        for (; v < len(seg[1]) and seg[1][v].second < seg[0][u].second; ++v) {
            upd(1, v);
        }
        upd(0, u);
    }
    
    for (; v < len(seg[1]); ++v) upd(1, v);
    cout << ans;

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.