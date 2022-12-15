#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define pb push_back
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()

const int INF = 1e9;
int dis[200005], seg[800005], pw[200005], idx[200005], n;
vector<int> stk[800005];

void build(int l, int r, int rt) {
    stk[rt].clear();
    if (l == r) {
        return seg[rt] = pw[l], void();
    }
    int mid = (l + r) >> 1;
    build(l, mid, rt << 1), build(mid + 1, r, rt << 1 | 1);
    seg[rt] = max(seg[rt << 1], seg[rt << 1 | 1]);
}

void add(int L, int R, int l, int r, int rt, int v) {
    if (L <= l && R >= r)
        return stk[rt].pb(v);
    int mid = (l + r) >> 1;
    if (L <= mid)
        add(L, R, l, mid, rt << 1, v);
    if (R > mid)
        add(L, R, mid + 1, r, rt << 1 | 1, v);
}

void modify(int x, int l, int r, int rt) {
    if (l == r)
        return seg[rt] = 0, void();
    int mid = (l + r) >> 1;
    if (x <= mid) modify(x, l, mid, rt << 1);
    else modify(x, mid + 1, r, rt << 1 | 1);
    seg[rt] = max(seg[rt << 1], seg[rt << 1 | 1]);
}

void relax(int x, int d, queue<int> &q) {
    modify(x, 1, n, 1);
    dis[x] = d;
    q.push(x);
}

void single(int x, int l, int r, int rt, queue<int> &q) {
    while (!stk[rt].empty()) {
        if (pw[stk[rt].back()] > pw[x]) break;
        if (dis[stk[rt].back()] == INF)
            relax(stk[rt].back(), dis[x] + 1, q);
        stk[rt].pop_back();
    }
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    if (x <= mid)
        single(x, l, mid, rt << 1, q);
    else
        single(x, mid + 1, r, rt << 1 | 1, q);
}

void range(int L, int R, int l, int r, int rt, int v, queue<int> &q) {
    if (seg[rt] <= pw[v]) return;
    if (l == r)
        return relax(l, dis[v] + 1, q);
    if (L <= l && R >= r) {
        int mid = (l + r) >> 1;
        range(L, R, l, mid, rt << 1, v, q);
        range(L, R, mid + 1, r, rt << 1 | 1, v, q);
    }
    int mid = (l + r) >> 1;
    if (L <= mid)
        range(L, R, l, mid, rt << 1, v, q);
    if (R > mid)
        range(L, R, mid + 1, r, rt << 1 | 1, v, q);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int st, ed;
        cin >> n >> st >> ed;
        for (int i = 1; i <= n; ++i)
            cin >> pw[i], dis[i] = INF;
        iota(idx + 1, idx + n + 1, 1);
        sort(idx + 1, idx + n + 1, [&](int a, int b) {
            return pw[a] > pw[b]; 
        });
        build(1, n, 1);
        for (int i = 1; i <= n; ++i) {
            int u = idx[i];
            add(max(1, u - pw[u]), min(n, u + pw[u]), 1, n, 1, u);
        }
        queue<int> q;
        relax(st, 0, q);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            single(u, 1, n, 1, q);
            range(max(1, u - pw[u]), min(n, u + pw[u]), 1, n, 1, u, q);
        }
        cout << dis[ed] << "\n";
    }
}