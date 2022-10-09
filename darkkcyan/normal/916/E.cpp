#include <bits/stdc++.h>
using namespace std;

#define llong long long /*{{{*/
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()
#define _pt(x) typename iterator_traits<x>::value_type
template<class u> vector<_pt(u)> tovec(u a, u b) { return vector<_pt(u)>(a, b); }
template<class x> ostream& operator<<(ostream& cout, const vector<x>& a) {
    cout << "[";
    rep(i, len(a)) cout << a[i] << (i == len(a) - 1 ? "" : ", ");
    return cout << "]";
}
template<class u, class v> ostream& operator<<(ostream& cout, const pair<u, v>& a) {
    return cout << a.xx << ": " << a.yy;
}/*}}}*/

struct it {
    int left, right;
    int nAvaliable;
    it *lchild, *rchild;
    llong dp, lz;
    it(): lchild(0), rchild(0) {}

    it(int l, int r, llong initVal[], bool avaliable[])
            : left(l), right(r), lchild(0), rchild(0), dp(0), lz(0)
    {
        if (l == r) {
            dp = initVal[l];
            nAvaliable = avaliable[l];
        }
        if (l >= r) return;
        int mid = (l + r) / 2;
        lchild = new it(l, mid, initVal, avaliable);
        rchild = new it(mid + 1, r, initVal, avaliable);
        dp = lchild->dp + rchild->dp;
        nAvaliable = lchild->nAvaliable + rchild->nAvaliable;
    }

    ~it() {
        if (lchild) delete lchild;
        if (rchild) delete rchild;
    }

    void dolz() {
        dp += nAvaliable * lz;
        if (lchild) lchild->lz += lz;
        if (rchild) rchild->lz += lz;
        lz = 0;
    }

    void upd(int l, int r, llong val) {
        dolz();
        if (l> this->right or this->left > r) return ;
        if (l <= this->left and this->right <= r) {
            lz += val;
            dolz();
            return ;
        }
        lchild->upd(l, r, val);
        rchild->upd(l, r, val);
        dp = lchild->dp + rchild->dp;
    }

    llong get(int l, int r) {
        dolz();
        if (l > this->right or this->left > r) return 0;
        if (l <= this->left and this->right <= r) return dp;
        return lchild->get(l, r) + rchild->get(l, r);
    }

    void boundedUpd(int l, int r, llong val) {
        if (l <= r) return upd(l, r, val);
        upd(left, right, val);
        upd(r + 1, l - 1, -val);
    }

    llong boundedGet(int l, int r) {
        if (l <= r) return get(l, r);
        return get(left, right) - get(r + 1, l - 1);
    }

    void print() {
        dolz();
        if (left == right) clog << dp << ' ';
        if (lchild) lchild->print();
        if (rchild) rchild->print();
    }
};

#define maxn 101010
#define maxlg 18
int n;
int a[maxn];
vector<int> gr[maxn];

vector<int> etPos[maxn];
vector<llong> et;
int up[maxlg][maxn];
int depth[maxn];
bool isFirstPos[maxn * 3];
void dfs(int u, int p) {
    depth[u] = depth[p] + 1;
    up[0][u] = p;
    rep(i, maxlg - 1) up[i + 1][u] = up[i][up[i][u]];

    etPos[u].push_back(len(et));
    isFirstPos[len(et)] = 1;
    et.push_back(a[u]);
    for (auto v: gr[u]) {
        if (v == p) continue;
        dfs(v, u);
        etPos[u].push_back(len(et));
        et.push_back(0);
    }
}

int lift(int u, int distance) {
    for (int i = 0; distance; i++, distance >>= 1) if (distance & 1) u = up[i][u];
    return u;
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    u = lift(u, depth[u] - depth[v]);
    if (u == v) return u;
    for (int i = maxlg; i--; ){
        if (up[i][u] == up[i][v]) continue;
        u = up[i][u];
        v = up[i][v];
    }
    return up[0][u];
}

int lca(int currentRoot, int u, int v) {
    int x = lca(u, v), y = lca(u, currentRoot), z = lca(v, currentRoot);
    if (depth[x] < depth[y]) x = y;
    if (depth[x] < depth[z]) x = z;
    return x;
}

pair<int, int> findRange(int curRoot, int u) {
    int etRootPos = curRoot == 1 ? etPos[curRoot][0] : etPos[curRoot].back();
    if (etRootPos < etPos[u][0] || etRootPos > etPos[u].back()) return {etPos[u][0], etPos[u].back()};
    auto p = upper_bound(all(etPos[u]), etRootPos);
    return {*p, *prev(p)};
}

it *myIt;
int root = 1;
function<void()> queryProcessor[] = {
        []() {
//            etPos[root].pop_back();
            cin >> root;
//            etPos[root].push_back(len(et) - 1);
        },

        []() {
            int u, v; llong x; cin >> u >> v >> x;
            int l = lca(root, u, v);
            if (l == root) myIt->upd(0, len(et) - 1, x);
            else {
                pair<int, int> range = findRange(root, l);
                myIt->boundedUpd(range.xx, range.yy, x);
            }
//            myIt->print();
        },

        []() {
            int u; cin >> u;
            llong ans = 0;
            if (u == root) ans = myIt->get(0, len(et) - 1);
            else {
                pair<int, int> range = findRange(root, u);
                ans = myIt->boundedGet(range.xx, range.yy);
            }
            cout << ans << '\n';
        },
};

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin >> n >> q;
    rep1(i, n) cin >> a[i];
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    dfs(1, 1);
    myIt = new it(0, len(et) - 1, et.data(), isFirstPos);
    while (q--) {
        int t; cin >> t;
        queryProcessor[--t]();
    }

    delete myIt;

    return 0;
}