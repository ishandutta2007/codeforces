#include <bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()
// #define rand __rand
// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
// template<class T = int> T rand(T range = numeric_limits<T>::max()) {
    // return (T)(rng() % range);
// }

template<typename TVal>
struct segtree_node {
    TVal val;
    int left, right;
    std::unique_ptr<segtree_node<TVal>> lchild, rchild;

    segtree_node(int left_, int right_) : left(left_), right(right_) {}

    void combine_children() {
        val.combine(*lchild.get(), *rchild.get());
    }

    inline bool expand() {
        if (right - left <= 1) return false;
        if (lchild) return true;
        int mid = left + (right - left) / 2;
        lchild.reset(new segtree_node(left, mid));
        rchild.reset(new segtree_node(mid, right));
        return true;
    }

    void propagate() {
        if (expand()) {
            lchild->val.add_lazy(*this, *lchild);
            rchild->val.add_lazy(*this, *rchild);
        }
        val.apply_lazy(*this);
    }

    void set_values(std::function<TVal(int)> const& get_val) {
        if (right - left == 1) val = get_val(left);
        if (!expand()) return ;
        lchild->set_values(get_val);
        rchild->set_values(get_val);
        combine_children();
    }

    bool inside(int l, int r) { return l <= left and right <= r; }
    bool outside(int l, int r) { return l >= right or left >= r; }

    operator TVal&() { return val; }
    operator bool() { return !lchild; }
};

struct Val {
    llong best[10];
    int min_val[10];
    Val(int num = 0) {
        int org = num;
        rep(i, 10) {
            best[i] = LLONG_MAX;
            if (num % 10 == 0) min_val[i] = INT_MAX; 
            else min_val[i] = org;
            num /= 10;
        }
    }

    Val(const Val& lchild, const Val& rchild) {
        combine(lchild, rchild);
    }
    void combine(const Val& lchild, const Val& rchild) {
        rep(i, 10) {
            best[i] = min(lchild.best[i], rchild.best[i]);
            min_val[i] = min(lchild.min_val[i], rchild.min_val[i]);
            if (lchild.min_val[i] == INT_MAX or rchild.min_val[i] == INT_MAX) continue;
            best[i] = min(best[i], (llong)lchild.min_val[i] + rchild.min_val[i]);
        }
    }

    void apply_lazy(bool) {}
    void add_lazy(bool, bool) {}

    llong min_best() {
        return *min_element(best, best + 10);
    }
};

void upd(segtree_node<Val>* root, int pos, int val) {
    root->propagate();
    if (root->outside(pos, pos + 1)) return ;
    if (root->inside(pos, pos + 1)) {
        root->val = Val(val);
        return ;
    }
    upd(root->lchild.get(), pos, val);
    upd(root->rchild.get(), pos, val);
    root->combine_children();
}

Val query(segtree_node<Val>* root, int l, int r) {
    root->propagate();
    if (root->outside(l, r)) return Val();
    if (root->inside(l, r)) return root->val;
    return Val(
        query(root->lchild.get(), l, r), 
        query(root->rchild.get(), l, r)
    );
}

#define maxn 201010
int n, q;
int a[maxn];
int main(void) {
    // clog << sizeof(segtree_node<Val>);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    rep(i, n) cin >> a[i];

    segtree_node<Val> root(0, n);
    root.set_values([](int pos) { return Val(a[pos]); } );

    rep(i, q) {
        int type; cin >> type;
        if (type == 1) {
            int pos, val; cin >> pos >> val;--pos;
            upd(&root, pos, val);
        } else {
            int l, r; cin >> l >> r; --l;
            auto ans = query(&root, l, r).min_best();
            if (ans == LLONG_MAX) cout << -1 << '\n';
            else cout << ans << '\n';
        }
    }

    return 0;
}