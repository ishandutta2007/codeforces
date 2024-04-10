// note: the range is [l; r)

#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()
#define satisfy_ratio(u, v) ((u) * 3 <= (v) * 5 and (u) * 5 >= (v) * 3)
#define rand __rand
mt19937 rand(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64

struct treapnode;
typedef shared_ptr<treapnode> treapnode_ptr;

struct treapnode {
    treapnode_ptr lchild, rchild;
    int val, size, height;

    treapnode() {}
    treapnode(int val_) : val(val_), size(1), height(1) {}
    treapnode(int val_, const treapnode_ptr& l, const treapnode_ptr& r) : lchild(l), rchild(r), val(val_)
    {
        upd_size();
    }

    int get(int pos) {
        int lsize = lchild ? lchild->size : 0;
        return 
            pos == lsize ? val : 
            pos < lsize ? lchild->get(pos) :
            rchild->get(pos - lsize - 1);
    }

    void upd_size() {
        size = 1 + (lchild ? lchild->size : 0) + (rchild ? rchild->size : 0);
        height = 1 + max(lchild? lchild->height : 0, rchild ? rchild->height : 0);
    }
};

int lv = 0;
treapnode_ptr join(const treapnode_ptr& u, const treapnode_ptr& v) {
    ++lv;
    if (!u and !v) return nullptr;
    if (!u) return v;
    if (!v) return u;
    if ((llong)rand() % (u->size + v->size) < (llong)u->size) 
        return move(make_shared<treapnode>(u->val, u->lchild, join(u->rchild, v)));
    else 
        return move(make_shared<treapnode>(v->val, join(u, v->lchild), v->rchild));
}

treapnode_ptr yank_firsthalf(const treapnode_ptr& u, int cut_size) {
    if (!u) return nullptr;

    int lsize = u->lchild ? u->lchild->size : 0;
    if (cut_size <= lsize) {
        return yank_firsthalf(u->lchild, cut_size);
    } else {
        return make_shared<treapnode>(u->val, u->lchild, 
                yank_firsthalf(u->rchild, cut_size - lsize - 1
        ));
    }
}

treapnode_ptr yank_secondhalf(const treapnode_ptr& u, int cut_size) {
    if (!u) return nullptr;

    int lsize = u->lchild ? u->lchild->size : 0;
    if (cut_size <= lsize) {
        return make_shared<treapnode>(u->val, yank_secondhalf(u->lchild, cut_size), u->rchild);
    } else {
        return yank_secondhalf(u->rchild, cut_size - lsize - 1);
    }
}

treapnode_ptr safe_slice(const treapnode_ptr& u, int offset, int size) {
    offset = (offset + u->size) % u->size;
    if (offset + size <= u->size)
        return move(yank_firsthalf(yank_secondhalf(u, offset), size));
    int lsize = u->size - offset;
    return move(join(yank_secondhalf(u, offset), yank_firsthalf(u, size - lsize)));
}

treapnode_ptr build(int l, int r, const function<int(int)>& get_info) {
    if (l >= r) return nullptr;
    int mid = l + (r - l) / 2;
    auto res = make_shared<treapnode>(get_info(mid));
    if (r - l <= 1) return move(res);
    res->lchild = build(l, mid, get_info);
    res->rchild = build(mid + 1, r, get_info);
    res->upd_size();
    return move(res);
}

vector<int> vals;
void tranversal(const treapnode_ptr& root) {
    if (!root) return ;
    tranversal(root->lchild);
    vals.push_back(root->val);
    tranversal(root->rchild);
}

treapnode_ptr rebuild(const treapnode_ptr& root) {
    vals.clear();
    tranversal(root);
    return move(build(0, root->size, [&](int id) { return vals[id]; }));
}

int n, m, s;
llong t;
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> s >> t;
    --s;
    treapnode_ptr root = build(0, n, [&](int id) { return id; });

    rep1(step, n - 1) {
        lv = 0;
        root = move(join(safe_slice(root, step, m), safe_slice(root, m - step, n - m)));
        if (root->height > 100) {
            root = move(rebuild(root));
        }
    }

    for (int i = (int) (t % n); i > 0; i--) {
        s += (s < m ? i : -i);
        s = (s + n) % n;
    }

    vector<int> dis(n, -1);
    dis[s] = 0;

    bool reduced = 0;
    for (llong i = t / n; i--; ) {
        int nxt = root->get(s);
        if (dis[nxt] == -1) {
            dis[nxt] = dis[s] + 1;
        } else if (!reduced) {
            i %= dis[s] + 1 - dis[nxt];
            reduced = 1;
        }
        s = nxt;
    }
    cout << s + 1;

    return 0;
}