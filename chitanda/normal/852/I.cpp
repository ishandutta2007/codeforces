#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 100005;
const int B = 333;

struct query{
	int l, r, id, tag;
	query(int l = 0, int r = 0, int id = 0, int tag = 0) : l(l), r(r), id(id), tag(tag) {}
	bool operator < (const query &R) const{
		return l / B != R.l / B ? l < R.l : r < R.r;
	}
}que[maxn];
int n, m;
int c[maxn], f[maxn];
int bak[maxn << 1], pre[maxn], suf[maxn], tot;
int dep[maxn];
int fa[maxn][17];
vector<int> g[maxn];
ll ans[maxn];
int cnt[maxn][2];
ll now;
int vis[maxn];

void dfs(int d, int fat){
	bak[pre[d] = ++tot] = d, fa[d][0] = fat, dep[d] = dep[fat] + 1;
	for(int i = 1; i <= 16; ++i)
		if((fa[d][i] = fa[fa[d][i - 1]][i - 1]) == 0) break;
	for(int v : g[d])
		if(v != fat) dfs(v, d);
	bak[suf[d] = ++tot] = d;
}

inline int lca(int x, int y){
	if(dep[x] > dep[y]) swap(x, y);
	for(int i = 16; i >= 0; --i)
		if(dep[fa[y][i]] >= dep[x]) y = fa[y][i];
	if(x == y) return x;
	for(int i = 16; i >= 0; --i)
		if(fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}

inline void add(int l, int r, int k){
	for(int i = l; i <= r; ++i){
		int v = bak[i];
		vis[v] += k;
		if(vis[v] == 1 || vis[v] == 1 + k){
			now -= (ll)cnt[f[v]][0] * cnt[f[v]][1];
			cnt[f[v]][c[v]] += vis[v] == 1 ? 1 : -1;
			now += (ll)cnt[f[v]][0] * cnt[f[v]][1];
		}
	}
}

void work(){
	sort(que + 1, que + m + 1);
	add(que[1].l, que[1].r, 1);
	int fa = lca(bak[que[1].l], bak[que[1].r]);
	ans[que[1].id] = now + (que[1].tag ? (c[fa] ? cnt[f[fa]][0] : cnt[f[fa]][1]) : 0); //
	
	for(int i = 2; i <= m; ++i){
		if(que[i].r > que[i - 1].r) add(que[i - 1].r + 1, que[i].r, 1);
		else add(que[i].r + 1, que[i - 1].r, -1);
		if(que[i].l < que[i - 1].l) add(que[i].l, que[i - 1].l - 1, 1);
		else add(que[i - 1].l, que[i].l - 1, -1);
		int fa = lca(bak[que[i].l], bak[que[i].r]);
		ans[que[i].id] = now + (que[i].tag ? (c[fa] ? cnt[f[fa]][0] : cnt[f[fa]][1]) : 0);
	}
}

int main(){
	scanf("%d", &n);
	vector<int> q;
	for(int i = 1; i <= n; ++i) scanf("%d", c + i);
	for(int i = 1; i <= n; ++i) scanf("%d", f + i), q.pb(f[i]);
	sort(q.begin(), q.end());
	q.erase(unique(q.begin(), q.end()), q.end());
	for(int i = 1; i <= n; ++i) 
		f[i] = lower_bound(q.begin(), q.end(), f[i]) - q.begin();
	for(int i = 1, x, y; i < n; ++i){
		scanf("%d%d", &x, &y);
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1, 0);
	scanf("%d", &m);
	for(int i = 1, u, v; i <= m; ++i){
		scanf("%d%d", &u, &v);
		if(pre[u] > pre[v]) swap(u, v);
		if(suf[u] < pre[v]) que[i] = query(suf[u], pre[v], i, 1);
		else que[i] = query(pre[u], pre[v], i);
	}
	work();
	for(int i = 1; i <= m; ++i)
		printf("%lld\n", ans[i]);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}