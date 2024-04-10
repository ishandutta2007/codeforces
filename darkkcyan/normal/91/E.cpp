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
// mt19937 rand(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64

struct line {
    int id;
    llong a, b;

    line(int id_ = 0, llong a_ = 0, llong b_ = 0) : id(id_), a(a_), b(b_) {}
    llong cal(llong x) { return a * x + b; }
};

bool check(line const& l1, line const& l2, line const& l3) {
    return (l3.b - l2.b) * (l2.a - l1.a) >= (l3.a - l2.a) * (l2.b - l1.b);
}

bool operator< (line const& u, line const& v) {
    if (u.a == v.a) return u.b < v.b;
    return u.a < v.a;
}

// [l; r)
struct itnode {
    vector<line> data;
    int l, r;
    unique_ptr<itnode> lchild, rchild;
    itnode(int l_, int r_, function<line(int)> const& getdata): l(l_), r(r_) {
        if (r - l == 1) data.push_back(getdata(l));
        if (r - l <= 1) return;
        int mid = l + (r - l) / 2;
        lchild.reset(new itnode(l, mid, getdata));
        rchild.reset(new itnode(mid, r, getdata));

        int u = 0, v = 0;
        while (u < len(lchild->data) and v < len(rchild->data)) {
            if (lchild->data[u] < rchild->data[v]) push_line(lchild->data[u++]);
            else push_line(rchild->data[v++]);
        }
        while (u < len(lchild->data)) push_line(lchild->data[u++]);
        while (v < len(rchild->data)) push_line(rchild->data[v++]);
// 
        // clog << l << ' ' << r << endl;
        // for (auto i: data) clog << "(" << i.a << ' ' << i.b << ") ";
        // clog << endl;
    }

    void push_line(line const& ln) {
        while (len(data) > 1 and check(data[len(data) - 2], data.back(), ln))
            data.pop_back();
        while (len(data) and data.back().a == ln.a and data.back().b < ln.b)
            data.pop_back();
        if (!len(data) or data.back().a != ln.a)
            data.push_back(ln);
    }
};

pair<llong, int> query(itnode* root, int l, int r, llong t) {
    if (root->l >= r or l >= root->r) return {0, -1};
    if (l <= root->l and root->r <= r) {
        int bl = 0, br = len(root->data) - 1;
        while (bl < br) {
            int mid = bl + (br - bl) / 2;
            if (root->data[mid].cal(t) >= root->data[mid + 1].cal(t))
                br = mid;
            else
                bl = mid + 1;
        }
        return max(
                make_pair(root->data[br].cal(t), root->data[br].id),
                make_pair(root->data.back().cal(t), root->data.back().id)
        );
    }
    
    return max(query(root->lchild.get(), l, r, t), query(root->rchild.get(), l, r, t));
}

int n, q;
vector<line> a;
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    rep1(i, n) {
        int u, v; cin >> u >> v;
        a.emplace_back(i, v, u);
    }
    unique_ptr<itnode> root(new itnode(0, n, [](int i) { return a[i]; }));
    while (q--) {
        int l, r, t; cin >> l >> r >> t;
        cout << query(root.get(), l - 1, r, t).yy << '\n';
    }

    return 0;
}