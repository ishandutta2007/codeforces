#include<bits/stdc++.h>
#define lc t[p].lchild
#define rc t[p].rchild
using namespace std;
const int maxn = 310000;
struct cao {
    int l, r, lchild, rchild;
    int set, val;
} t[maxn * 4];
int cur = 0, tmp, n, res, answer, root, L[maxn], R[maxn];
vector<int> A[maxn], B[maxn], seq;
void init() {
    cur = answer = res = 0;
    seq.clear(); seq.push_back(0);
    for (int i = 0; i <= n; ++i) {
        A[i].clear();
        B[i].clear();
    }
}
inline void maintain(int p) {
    t[p].val = max(t[lc].val, t[rc].val);
}
inline void mark(int p, int setv) {
    if (setv >= 0) {
        t[p].set = t[p].val = setv;
    }
}
inline void pushdown(int p) {
    mark(lc, t[p].set);
    mark(rc, t[p].set);
    t[p].set = -1;
}
int build(int L, int R) {
    int p = ++cur;
    t[p].l = L;
    t[p].r = R;
    t[p].set = -1;
    t[p].val = 0;
    if (t[p].l != t[p].r) {
        int mid = (t[p].l + t[p].r) >> 1;
        lc = build(L, mid);
        rc = build(mid + 1, R);
        maintain(p);
    }
    return p;
}
void update(int p, int L, int R, int v) {
    if (L <= t[p].l && R >= t[p].r) {
        mark(p, v);
    }
    else {
        pushdown(p);
        int mid = (t[p].l + t[p].r) >> 1;
        if (L <= mid)
            update(lc, L, R, v);
        if (R > mid)
            update(rc, L, R, v);
        maintain(p);
    }
}
inline void update(int L, int R, int v) {
    update(root, L, R, v);
}
void query(int p, int L, int R) {
    if (L <= t[p].l && R >= t[p].r) {
        tmp = max(tmp, t[p].val);
    }
    else {
        pushdown(p);
        int mid = (t[p].l + t[p].r) >> 1;
        if (L <= mid)
            query(lc, L, R);
        if (R > mid)
            query(rc, L, R);       
    }
}
inline int query(int L, int R) {
    ::tmp = 0;
    query(root, L, R);
    return tmp;
}
void dfs(int x, int fa) {
    L[x] = seq.size();
    seq.push_back(x);
    for (auto y : B[x]) if (y != fa) {
        dfs(y, x);
    }
    R[x] = seq.size() - 1;
}
void solve(int x, int fa) {
    int pos = query(L[x], L[x]);
    if (pos) {
        update(L[pos], R[pos], 0);
        res -= 1;
    }
    int val = query(L[x], R[x]);
    if (val == 0) {
        update(L[x], R[x], x);
        res += 1;
    }
    answer = max(answer, res);
    for (auto y : A[x]) if (y != fa) {
        solve(y, x);
    }
    if (val == 0) {
        update(L[x], R[x], 0);
        res -= 1;
    }
    if (pos) {
        update(L[pos], R[pos], pos);
        res += 1;
    }
}
int main() { //3 1 2
   // freopen("in", "r", stdin);
	int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        init();
        for (int i = 2; i <= n; ++i) {
            int x, y;
            scanf("%d", &y);
            A[i].push_back(y);
            A[y].push_back(i);
        }
        for (int i = 2; i <= n; ++i) {
            int x, y;
            scanf("%d", &y);
            B[i].push_back(y);
            B[y].push_back(i);
        }
        ::root = build(1, n);
        dfs(1, -1);
        solve(1, -1);
        printf("%d\n", answer);
    }
    return 0;
}