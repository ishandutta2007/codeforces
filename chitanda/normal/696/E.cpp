//int!
#include <bits/stdc++.h>
using namespace std;
#define ll long long
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

const int maxn = 200100;
int n, m, q, tot;
int size[maxn], dep[maxn], top[maxn], son[maxn], fa[maxn], re[maxn], w[maxn], ed[maxn], c[maxn];
ll tag[maxn];
queue<int> girl[maxn];
vector<int> g[maxn], ans;
struct node{
	ll w;
	int p;
	node(ll w = 1LL << 60, int p = 0) : w(w), p(p) {}
	bool operator < (const node &a) const{
		return w < a.w || (w == a.w && p < a.p);
	}
}tr[maxn], tmp;

void dfs(int t){
	size[t] = 1, son[t] = 0;
	for(auto v : g[t])
		if(v != fa[t]){
			fa[v] = t, dep[v] = dep[t] + 1, dfs(v);
			if(size[v] > size[son[t]]) son[t] = v;
			size[t] += size[v];
		}
}

void dfs(int t, int ance){
	re[w[t] = ++tot] = t, top[t] = ance;
	if(son[t]) dfs(son[t], ance);
	for(auto v : g[t])
		if(v != fa[t] && v != son[t]) dfs(v, v);
	ed[t] = tot;
}

inline int getID(int l, int r){
	return (l + r) | (l < r);
}

void build(int l, int r){
	int t = getID(l, r);
	if(l == r){
		if(!girl[re[l]].empty()){
			int x = girl[re[l]].front();
			tr[t] = node(x, re[l]);
		}else tr[t] = node();
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid), build(mid + 1, r);
	tr[t] = min(tr[getID(l, mid)], tr[getID(mid + 1, r)]);
}

inline void push_down(int l, int r){
	int t = getID(l, r), mid = (l + r) >> 1, ls = getID(l, mid), rs = getID(mid + 1, r);
	tag[ls] += tag[t], tag[rs] += tag[t];
	tr[ls].w += tag[t], tr[rs].w += tag[t];
	tag[t] = 0;
}

void modify(int l, int r, int x, int y, int k){
	int t = getID(l, r);
	if(x <= l && y >= r){
		tag[t] += k;
		tr[t].w += k;
		return;
	}
	push_down(l, r);
	int mid = (l + r) >> 1;
	if(x <= mid) modify(l, mid, x, y, k);
	if(y > mid) modify(mid + 1, r, x, y, k);
	tr[t] = min(tr[getID(l, mid)], tr[getID(mid + 1, r)]);
}

void query(int l, int r, int x, int y){
	int t = getID(l, r);
	if(x <= l && y >= r){
		tmp = min(tmp, tr[t]);
		return;
	}
	push_down(l, r);
	int mid = (l + r) >> 1;
	if(x <= mid) query(l, mid, x, y);
	if(y > mid) query(mid + 1, r, x, y);
}

void del(int l, int r, int x){
	int t = getID(l, r);
	if(l == r){
		ans.pb(girl[re[l]].front());
		girl[re[l]].pop();
		if(!girl[re[l]].empty()){
			int x = girl[re[l]].front();
			tr[t] = node(x + tag[t], re[l]);
		}else tr[t] = node();
		return;
	}
	push_down(l, r);
	int mid = (l + r) >> 1;
	if(x <= mid) del(l, mid, x);
	else del(mid + 1, r, x);
	tr[t] = min(tr[getID(l, mid)], tr[getID(mid + 1, r)]);
}

bool solve(int u, int v){
	int f1 = top[u], f2 = top[v];
	tmp = node();
	while(f1 != f2){
		if(dep[f1] < dep[f2]) swap(f1, f2), swap(u, v);
		query(1, n, w[f1], w[u]);
		u = fa[f1], f1 = top[u];
	}
	if(dep[u] > dep[v]) swap(u, v);
	query(1, n, w[u], w[v]);
	if(tmp.w == 1LL << 60) return 0;
	del(1, n, w[tmp.p]);
	return 1;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &q);
	int ty, u, v, k;	
	for(int i = 1; i < n; ++i){
		scanf("%d%d", &u, &v);
		g[u].pb(v), g[v].pb(u);
	}
	for(int i = 1; i <= m; ++i){
		scanf("%d", c + i);
		girl[c[i]].push(i);
	}
	dfs(1);
	dfs(1, 1);
	build(1, n);
	
	for(int i = 1; i <= q; ++i){
		scanf("%d", &ty);
		if(ty == 1){
			scanf("%d%d%d", &u, &v, &k);
			ans.clear();
			while(k-- && solve(u, v));
			printf("%d", (int)ans.size());
			for(auto v : ans) printf(" %d", v);
			puts("");
		}else{
			scanf("%d%d", &v, &k);
			modify(1, n, w[v], ed[v], k);
		}
	}
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