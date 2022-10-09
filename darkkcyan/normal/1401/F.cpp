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

const int maxn = 18;
const int maxrange = 1 << 18;
char buff[maxrange * 4 * 30];
char* ptr = buff;

struct node {
    void* operator new(size_t sz) {
        auto ans = ptr;
        ptr += sz;
        return ans;
    }
    
    llong val;
    int lv;
    int sw_mask;
    node *lchild, *rchild;
    
    node(int lv_, int l, int r, int *arr) : lv(lv_), lchild(nullptr), rchild(nullptr) {
        if (r - l == 1) {
            val = arr[l];
        } else val = 0;
        sw_mask = 0;
        
        if (r - l <= 1) return ;
        int mid = (l + r) / 2;
        lchild = new node(lv - 1, l, mid, arr);
        rchild = new node(lv - 1, mid, r, arr);
        val = lchild->val + rchild->val;
    }
    
    void propagate() {
        if ((sw_mask >> lv) & 1) {
            swap(lchild, rchild);
            sw_mask ^= 1 << lv;
        }
        
        if (lchild) lchild->sw_mask ^= sw_mask;
        if (rchild) rchild->sw_mask ^= sw_mask;
        sw_mask = 0;
    }
    
    void set_val(int pos, int new_val) {
        propagate();
        if (pos < 0 or pos >= (1 << lv)) return ;
        if (lv == 0) {
            val = new_val;
            return ;
        }
        
        int mid = (1 << (lv - 1));
        if (pos < mid) lchild->set_val(pos, new_val);
        else rchild->set_val(pos - mid, new_val);
        val = lchild->val + rchild->val;
    }
    
    llong get_sum(int l, int r) {
        propagate();
        if (r <= 0 or l >= (1 << lv)) return 0;
        if (l <= 0 and r >= (1 << lv)) return val;
        
        int mid = (1 << (lv - 1));
        return lchild->get_sum(l, r) + rchild->get_sum(l - mid, r - mid);
    }
};

int n, q;
int a[maxrange];
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    rep(i, (1 << n)) cin >> a[i];
    
    node* root = new node(n, 0, 1 << n, a);
    
    while (q--) {
        int tp; cin >> tp;
        if (tp == 1) {
            int pos, new_val; cin >> pos >> new_val;
            --pos;
            root->set_val(pos, new_val);
        } else if (tp == 2) {
            int k; cin >> k;
            int mask = ((1 << k) - 1) << 1;
            root->sw_mask ^= mask;
        } else if (tp == 3) {
            int k; cin >> k;
            int mask = (1 << (k + 1));
            root->sw_mask ^= mask;
        } else if (tp == 4) {
            int l, r; cin >> l >> r;
            --l;
            cout << root->get_sum(l, r) << '\n';
        }
    }

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker