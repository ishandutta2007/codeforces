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

template<int ofs = 1>
struct BIT {
    vector<int> val;
    BIT(int n_) : val(n_ + ofs) {
    }
    
    void upd(int i, int del) {
        for (i += ofs; i < len(val); i += i & -i) val[i] += del;
    }
    
    int get(int i) {
        int ans = 0;
        for (i += ofs; i > 0; i -= i & -i) ans += val[i];
        return ans;
    }
    
    int find(int k) {
        int ans = 0;
        for (int i = 20; i--; ) {
            int d = ans + (1 << i);
            if (d >= len(val)) continue;
            if (val[d] > k) continue;
            k -= val[d];
            ans = d;
        }
        return ans - ofs;
    }
};

const int maxn = 301010;
const int maxq = maxn;

struct node {
    node *lchild, *rchild;
    pair<llong, int> val;
    llong lz;
    int length;
    
    node(int l, int r, int* num = nullptr): lchild(0), rchild(0), lz(0), length(r - l) {
        if (l == r - 1) {
            val = {num[l], -l};
        }
        if (l >= r - 1) return ;
        int mid = (l + r) / 2;
        lchild = new node(l, mid, num);
        rchild = new node(mid, r, num);
        val = min(lchild->val, rchild->val);
    }
    
    ~node() {
        if (lchild) delete lchild;
        if (rchild) delete rchild;
    }
    
    void propagate() {
        if (!lz) return ;
        val.first -= lz;
        if (lchild) lchild->lz += lz;
        if (rchild) rchild->lz += lz;
        lz = 0;
    }
    
    void upd(int ul, int ur) {
        propagate();
        if (ur < 0 or ul >= length) return ;
        if (ul <= 0 and length <= ur) {
            lz ++;
            propagate();
            return ;
        }
        lchild->upd(ul, ur);
        rchild->upd(ul - lchild->length, ur - lchild->length);
        val = min(lchild->val, rchild->val);
    }
    
    void set(int pos, llong new_val) {
        propagate();
        if (pos < 0 or pos >= length) return ;
        if (length == 1) {
            val.first = new_val;
            return ;
        }
        lchild->set(pos, new_val);
        rchild->set(pos - lchild->length, new_val);
        val = min(lchild->val, rchild->val);
    }
};

int n, q;
int a[maxn];
vector<pair<int, int>> queries[maxq];
vector<int> gr[maxn];
int ans[maxq];
int rem_at[maxn];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    rep1(i, n) {
        cin >> a[i];
        a[i] = i - a[i];
    }
    node it(1, n + 1, a);
    set<int> events;
    events.insert(0);
    
    
    deb($v(a + 1, a + n + 1));
    while (true) {
        auto [val, pos] = it.val;
        pos = -pos;
        // deb(val, pos); 
        if (val < 0) {
            it.set(pos - 1, INT_MAX);
            continue;
        }
        if (val != 0) break;
        if (val >= 0) {
            auto p = events.upper_bound(pos);
            --p;
            int rem = *p == 0 ? pos : rem_at[*p];
            rem_at[pos] = rem;
            gr[rem].push_back(pos);
            deb(pos, *p);
            it.upd(pos, n + 10);
            while (len(events) > 1 and *--events.end() > pos) events.erase(--events.end());
            events.insert(pos);
        }
        it.set(pos - 1, INT_MAX);
    }
    
    rep(i, q) {
        int l, r; cin >> l >> r;
        queries[l + 1].emplace_back(i, r);
    }
    
    BIT sum(n + 10);
    for (int i = n; i > 0; i--) {
        DB(i);
        for (auto pos: gr[i]) {
            sum.upd(pos, 1);
            deb(pos);
        }
        
        for (int f = 0; f < n; ++f) deb(f, sum.get(f));  
        for (auto [id, r]: queries[i]) {
            ans[id] = sum.get(n - r);
        }
    }
    rep(i, q) cout << ans[i] << '\n';
    

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker