#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

int f[maxn];
int n, q;

vector<int> neigh[maxn];
int sz[maxn];
int par[maxn];
int depth[maxn];

int pos_in_path[maxn];
int path_id[maxn];
int top_node[maxn];
int path_cnt = 0;

struct Info {
    int val, total, left, right;
};

Info Merge(Info L, Info R)
{
    Info c;
    c.val = L.val + R.val + (L.right < L.total && R.left < R.total ? f[L.right + R.left] : 0);
    c.total = L.total + R.total;
    c.left = L.total == L.left ? R.left + L.total : L.left;
    c.right = R.total == R.right ? L.right + R.total : R.right;
    return c;
}

struct {
    int L, R;
    int pl, pr;
    Info info;
} T[2 * maxn];

int roots[maxn];

int buildTree(int L, int R)
{
    static int sz = 1;
    int cur = sz++;
    T[cur].L = L;
    T[cur].R = R;
    T[cur].info.total = R - L + 1;
    if (L < R) {
        T[cur].pl = buildTree(L, (L+R)/2);
        T[cur].pr = buildTree((L+R)/2+1, R);
    }
    return cur;
}

void toggle(int i, int cur)
{
    if (T[cur].L == T[cur].R) {
        T[cur].info.left = T[cur].info.right = 1;
        return;
    }

    if (i <= T[ T[cur].pl ].R)
        toggle(i, T[cur].pl);
    else
        toggle(i, T[cur].pr);

    T[cur].info = Merge(T[ T[cur].pl ].info, T[ T[cur].pr ].info);
}

Info get(int l, int r, int cur)
{
    if (l <= T[cur].L && r >= T[cur].R)
        return T[cur].info;

    Info tmp = {0, 0, 0, 0};
    if (l <= T[ T[cur].pl ].R && T[ T[cur].pl ].L <= r)
        tmp = Merge(get(l, r, T[cur].pl), tmp);
    if (l <= T[ T[cur].pr ].R && T[ T[cur].pr ].L <= r)
        tmp = Merge(tmp, get(l, r, T[cur].pr));
    return tmp;
}

void dfs1(int v, int p)
{
    par[v] = p;
    sz[v] = 1;
    for (int u : neigh[v]) {
        if (u == p) continue;
        depth[u] = depth[v] + 1;
        dfs1(u, v);
        sz[v] += sz[u];
    }
}

void makeHLD(int v, int p, bool start)
{
    int to = -1;
    for (int u : neigh[v]) {
        if (u == p) continue;
        if (to == -1 || sz[u] > sz[to])
            to = u;
    }

    if (to == -1) {
        pos_in_path[v] = 1;
        path_cnt++;
        path_id[v] = path_cnt;
    }
    else {
        for (int u : neigh[v]) {
            if (u == p) continue;
            if (u != to)
                makeHLD(u, v, true);
        }
        makeHLD(to, v, false);
        path_id[v] = path_id[to];
        pos_in_path[v] = pos_in_path[to] + 1;
    }

    if (start) {
        roots[path_id[v]] = buildTree(1, pos_in_path[v]);
        top_node[path_id[v]] = v;
    }
}

pair<int, int> w[maxn];

int u_in[maxn], v_in[maxn], w_in[maxn];

struct Query {
    int ind;
    int u, v;
    int l;
} Q[maxn];

bool operator< (Query a, Query b) {
    return a.l > b.l;
}

int ans[maxn];

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n - 1; i++) scanf("%d", f + i);

    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d %d", u_in + i, v_in + i, w_in + i);
        neigh[u_in[i]].push_back(v_in[i]);
        neigh[v_in[i]].push_back(u_in[i]);
    }

    dfs1(1, 0);
    makeHLD(1, 0, true);

    for (int i = 0; i < n - 1; i++) {
        if (sz[u_in[i]] < sz[v_in[i]])
            w[i] = {w_in[i], u_in[i]};
        else
            w[i] = {w_in[i], v_in[i]};
    }

    sort(w, w + n - 1);
    for (int i = 0, j = n - 2; i < j; i++, j--) swap(w[i], w[j]);

    for (int i = 0; i < q; i++) {
        scanf("%d %d %d", &Q[i].u, &Q[i].v, &Q[i].l);
        Q[i].ind = i;
    }
    sort(Q, Q + q);

    for (int i = 0, j = 0; i < q; i++) {
        while (j < n - 1 && w[j].first >= Q[i].l) {
            toggle(pos_in_path[w[j].second], roots[path_id[w[j].second]]);
            j++;
        }

        int u = Q[i].u;
        int v = Q[i].v;

        Info info_u = {0, 0, 0, 0};
        Info info_v = {0, 0, 0, 0};

        while (path_id[u] != path_id[v]) {
            if (depth[top_node[path_id[u]]] < depth[top_node[path_id[v]]]) {
                swap(u, v);
                swap(info_u, info_v);
            }

            info_u = Merge(info_u, get(pos_in_path[u], 1000000000, roots[path_id[u]]));
            u = par[top_node[path_id[u]]];
        }

        if (u != v) {
            if (pos_in_path[u] > pos_in_path[v]) {
                swap(u, v);
                swap(info_u, info_v);
            }
            info_u = Merge(info_u, get(pos_in_path[u], pos_in_path[v] - 1, roots[path_id[u]]));
            u = v;
        }

        swap(info_v.left, info_v.right);
        Info a = Merge(info_u, info_v);
        ans[Q[i].ind] = a.val + f[a.left] + (a.right < a.total ? f[a.right] : 0);
    }

    for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
}