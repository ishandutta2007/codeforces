#include <bits/stdc++.h>
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int) (x).size())
#define ALL(x) x.begin(), x.end()
 
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef unsigned long long u64;
 
template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
 
int read() {
    int x = 0, f = 1;char ch;
    for (ch = getchar(); !isdigit(ch); ch = getchar())
        if (ch == '-') f = -1;
    for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    return x * f;
}
 
const int MaxN = 201234, Logn = 18;
 
struct edge {
    int to, nxt;
}e[MaxN << 1];
 
int n, m, q, cnt, lst[MaxN];
 
void addEdge(int u, int v) {
    e[++cnt] = (edge) {v, lst[u]}; lst[u] = cnt;
    e[++cnt] = (edge) {u, lst[v]}; lst[v] = cnt;
}
 
const int M = 10001234;
 
int seg[M], lc[M], rc[M], rot[MaxN], segn;
 
void add(int &p, int q, int l, int r, int x) {
    seg[p = ++segn] = seg[q] + 1;
    lc[p] = lc[q]; rc[p] = rc[q];
    if(l == r) return;
    if(x <= (l + r >> 1))
        add(lc[p], lc[q], l, l + r >> 1, x);
    else   
        add(rc[p], rc[q], (l + r >> 1) + 1, r, x);
}
 
int sum(int p, int q, int l, int r, int qL, int qR) {
    if(qL > r || qR < l) return  0;
    if(qL <= l && r <= qR) 
        return seg[q] - seg[p];
    return sum(lc[p], lc[q], l, l + r >> 1, qL, qR) + sum(rc[p], rc[q], (l + r >> 1) + 1, r, qL, qR);
}
 
int in[MaxN], out[MaxN]; 
bool ok(int a, int b) {
    int cnt = sum(rot[in[a] - 1], rot[out[a]], 1, n, in[b], out[b]);
    return cnt > 0;
}
 
struct line {
    int u, v, w;
}l[MaxN];
 
int dep[MaxN], siz[MaxN], f[MaxN][Logn + 1], son[MaxN], par[MaxN];
 
void dfs1(int x, int fa = 0) {
    par[x] = fa;
    dep[x] = dep[fa] + 1; siz[x] = 1; 
    for (int i = lst[x]; i; i = e[i].nxt) {
        int y = e[i].to; if(y == fa) continue;
        dfs1(y, x); siz[x] += siz[y];
        if(siz[y] > siz[son[x]])
            son[x] = y;
    }
}
 
int pos[MaxN], top[MaxN], dn;
  
void dfs2(int x, int t = 1){
    top[x] = t; in[x] = ++dn; pos[dn] = x;
    if(son[x]) dfs2(son[x], t);
    for (int i = lst[x]; i; i = e[i].nxt) 
        if(e[i].to != par[x] && e[i].to != son[x])
            dfs2(e[i].to, e[i].to);
    out[x] = dn;
}
 
int lca(int x, int y) {
    while(top[x] != top[y]) {
        dep[top[x]] < dep[top[y]] ? y = par[top[y]] : x = par[top[x]];
    }
    return dep[x] > dep[y] ? y : x;
}
 
int jump(int x, int k) {
    for (;;) {
        int len = in[x] - in[top[x]];
        if(k <= len)
            return pos[in[x] - k];
        x = par[top[x]]; k -= len + 1;
    }
    return x;
}
 
int far(int x, int y) {
    if(x == y) return 0;
    if(dep[f[x][Logn]] > dep[y])
        return -1;
    int ans = 0;
    for (int i = Logn; i >= 0; i--)
        if(dep[f[x][i]] > dep[y]) 
            x = f[x][i], ans += 1 << i;
    return ans + 1; 
}
 
bool sub(int x, int y) {
    return in[y] <= in[x] && out[x] <= out[y];
}
 
int query(int u, int v) {
    int w = lca(u, v);
    if(dep[f[u][Logn]] > dep[w]) 
        return -1;
    int len = 0;
    for (int i = Logn; i >= 0; i--)
        if(dep[f[u][i]] > dep[w]) u = f[u][i], len += 1 << i;
    int L = 0, R = dep[v] - dep[w] - 1, ans = R + 1;
    while(L <= R) {
        int mid = L + R >> 1;
        if(ok(u, jump(v, mid)))
            ans = mid, R = mid - 1;
        else
            L = mid + 1;
    }
    ans = far(v, jump(v, ans));
    return ans < 0 ? -1 : len + ans +1;
}
 
vector <int> t[MaxN];
 
bool cmp(line a, line b) {
    return dep[a.w] < dep[b.w];
}
 
int fat[MaxN];
 
int find(int x) {
    return fat[x] == x ? x : fat[x] = find(fat[x]);
}
 
void work(int u, int v) {
    for (u = find(u); dep[u] >= dep[v]; u = find(u))
        f[u][0] = v, fat[u] = par[u];
}
 
int main() {
    n = read(); 
    for (int i = 2; i <= n; i++) {
        int u = read(), v = i;
        addEdge(u, v);
    }
	m = read(); 
    dfs1(1); dfs2(1); 
     
    for (int i = 1; i <= m; i++) {
        l[i].w = lca(l[i].u = read(), l[i].v = read()); 
        if(l[i].u != l[i].v) {
             
            t[in[l[i].u]].pb(in[l[i].v]), t[in[l[i].v]].pb(in[l[i].u]);
        }
    } 
     
    sort(l + 1, l + m + 1, cmp);
    for (int i = 1; i <= n; i++)
        f[i][0] = i, fat[i] = i;
    for (int i = 1; i <= m; i++) {
        work(l[i].u, l[i].w);
        work(l[i].v, l[i].w);
    }
    for (int i = 1; i <= Logn; i++)
        for (int j = 1; j <= n; j++)
            f[j][i] = f[f[j][i - 1]][i - 1];
    for (int i = 1; i <= n; i++) {
        rot[i] = rot[i - 1];
        for (int ti = 0; ti < SZ(t[i]); ti++) {
            int j = t[i][ti];
            add(rot[i], rot[i], 1, n, j);
        }
    }
	q = read();
    while(q--) {
        int u = read(), v = read(), ans;
        if(sub(v, u)) ans = far(v, u) ;
        else if(sub(u, v)) ans = far(u, v);
        else {
            ans = query(u,  v);
        }
        printf("%d\n", ans);
    }
    return 0;
}