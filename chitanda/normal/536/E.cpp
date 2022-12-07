//int!
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)
#define all(a) a.begin(), a.end()
inline int ckmax(int &a, int b) { return a < b ? a = b, 1 : 0; }
inline int ckmin(int &a, int b) { return a > b ? a = b, 1 : 0; }
#define clean(a) memset(a, 0, sizeof(a))
typedef long long ll;
#define ls t << 1
#define rs (t << 1) | 1
#define lss ls, l, mid
#define rss rs, mid + 1, r

const int maxn = 100005;

struct edge{
	int u, v, w;
	void input(){
		scanf("%d%d%d", &u, &v, &w);
	}
	bool operator < (const edge &R) const{
		return w > R.w;
	}
}ed[maxn];

struct query{
	int u, v, l, id;
	void input(int _id){
		id = _id;
		scanf("%d%d%d", &u, &v, &l);
	}
	bool operator < (const query &R) const{
		return l > R.l;
	}
}que[maxn];

struct node{
	int L, R, len, s;
	node(){
		L = R = len = s = 0;
	}
}tr[maxn << 2];

int n, m;
int f[maxn];
vector<int> g[maxn];
int sz[maxn], son[maxn], dep[maxn], fa[maxn], top[maxn];
int tot;
int w[maxn];
int ans[maxn];

void dfs(int t){ //find the heavy edge
	sz[t] = 1;
	for(int v : g[t])
		if(v != fa[t]){
			fa[v] = t, dep[v] = dep[t] + 1;
			dfs(v);
			if(sz[v] > sz[son[t]]) son[t] = v;
			sz[t] += sz[v];
		}
}

void dfs(int t, int ance){
	w[t] = ++tot, top[t] = ance;
	if(son[t]) dfs(son[t], top[t]);
	for(int v : g[t])
		if(v != fa[t] && v != son[t]) dfs(v, v);
}

void build(int t, int l, int r){
	tr[t].len = r - l + 1;
	if(l == r) return;
	int mid = (l + r) >> 1;
	build(lss), build(rss);
}

node merge(node l, node r){
	node t;
	t.len = l.len + r.len;
	t.s = l.s + r.s;
	if(l.R != l.len && r.L != r.len) t.s += f[l.R + r.L];
	if(l.R == l.len) t.L = l.len + r.L; else t.L = l.L;
	if(r.L == r.len) t.R = r.len + l.R; else t.R = r.R;
	return t;
}

void modify(int t, int l, int r, int p){
	if(l == r){
		tr[t].L = tr[t].R = 1;
		return;
	}
	int mid = (l + r) >> 1;
	if(p <= mid) modify(lss, p);
	else modify(rss, p);
	tr[t] = merge(tr[ls], tr[rs]);
}

node ask(int t, int l, int r, int x, int y){
	if(x <= l && y >= r) return tr[t];
	int mid = (l + r) >> 1;
	if(y <= mid) return ask(lss, x, y);
	else if(x > mid) return ask(rss, x, y);
	else return merge(ask(lss, x, y), ask(rss, x, y));
}

int ask(int u, int v){
	node t1, t2;
	int f1 = top[u], f2 = top[v];
	while(f1 != f2){
		if(dep[f1] < dep[f2]) swap(f1, f2), swap(u, v), swap(t1, t2);
		t1 = merge(ask(1, 1, n, w[f1], w[u]), t1);
		u = fa[f1], f1 = top[u];
	}
	if(dep[u] > dep[v]) swap(u, v), swap(t1, t2);
	if(u != v) t2 = merge(ask(1, 1, n, w[u] + 1, w[v]), t2);
	swap(t1.L, t1.R);
	t1 = merge(t1, t2);
	return t1.s + f[t1.L] + (t1.L != t1.len ? f[t1.R] : 0);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for(int i = 1; i < n; ++i) scanf("%d", f + i);
	for(int i = 1; i < n; ++i){
		ed[i].input();
		g[ed[i].u].pb(ed[i].v);
		g[ed[i].v].pb(ed[i].u);
	}
	for(int i = 1; i <= m; ++i) que[i].input(i);
	
	sort(ed + 1, ed + n);
	sort(que + 1, que + m + 1);

	dfs(1);
	dfs(1, 1);
	build(1, 1, n);
	for(int i = 1, j = 1; i <= m; ++i){
		for(; j < n && ed[j].w >= que[i].l; ++j){
			if(dep[ed[j].u] > dep[ed[j].v]) swap(ed[j].u, ed[j].v);
			modify(1, 1, n, w[ed[j].v]);
		}
		ans[que[i].id] = ask(que[i].u, que[i].v);
	}
	for(int i = 1; i <= m; ++i)	printf("%d\n", ans[i]);
  return 0;
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                BUG
*/