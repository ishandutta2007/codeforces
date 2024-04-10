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

const int maxn = 301010;
const int lg_maxn = 21;

struct it_node {
    it_node *left = NULL, *right = NULL;
    int val = 0, lz = 0;
    int l, r;
    it_node(int l_, int r_): l(l_), r(r_) {
        if (r == l + 1) return ;
        int mid = (l + r) / 2;
        left = new it_node(l, mid);
        right = new it_node(mid, r);
    }

    ~it_node() {
        if (left) delete left;
        if (right) delete right;
    }

    void propagate() {
        if (lz == 0) return ;
        val += lz;
        if (left) left->lz += lz;
        if (right) right->lz += lz;
        lz = 0;
    }

    void upd(int del, int ql, int qr) {
        propagate();
        if (ql >= r or l >= qr) return ;
        if (ql <= l and r <= qr) {
            lz += del;
            propagate();
            return ;
        }
        left->upd(del, ql, qr);
        right->upd(del, ql, qr);
        val = min(left->val, right->val);
    }

    int find_min(int ql, int qr) {
        propagate();
        if (ql >= r or l >= qr) return INT_MAX;
        if (ql <= l and r <= qr) return val;
        return min(left->find_min(ql, qr), right->find_min(ql, qr));
    }

};

int n;
int a[maxn];
int pos[maxn];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep1(i, n) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    it_node root(0, n + 1);
    int cur_ans = n;
    root.upd(1, pos[n], n + 1);

    cout << cur_ans << ' ';
    rep(cur_q, n - 1) {
        DB(""; deb(cur_q));
        int u; cin >> u;
        root.upd(-1, u, n + 1);
        while (true) {
            int left_min = root.find_min(0, pos[cur_ans]);
            int right_min = root.find_min(pos[cur_ans], n + 1);
            deb(cur_ans, left_min, right_min);
            if (right_min > left_min) break;
            --cur_ans;
            root.upd(1, pos[cur_ans], n + 1);
        }
        cout << cur_ans << ' ';
    }

    return 0;
}