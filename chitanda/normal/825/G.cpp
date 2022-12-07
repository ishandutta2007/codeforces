#include<bits/stdc++.h>
using namespace std;
#define mkp make_pair
#define pb push_back
#define fi first
#define se second

const int maxn = 1000100;
int n, q;
vector<int> g[maxn];
int dep[maxn];
int fa[maxn][22], tmin[maxn][22];
bool black[maxn];

void dfs(int t){
	dep[t] = dep[fa[t][0]] + 1;
	for(int i = 1; fa[t][i - 1]; ++i){
		fa[t][i] = fa[fa[t][i - 1]][i - 1];
		tmin[t][i] = min(tmin[t][i - 1], tmin[fa[t][i - 1]][i - 1]);
	}
	for(auto v : g[t]){
		if(v == fa[t][0]) continue;
		fa[v][0] = t;
		tmin[v][0] = min(t, v);
		dfs(v);
	}
}

pair<int, int> lca(int u, int v){
	if(dep[u] > dep[v]) swap(u, v);
	int res = n;
	for(int i = 20; i >= 0; --i)
		if(dep[fa[v][i]] >= dep[u]) res = min(res, tmin[v][i]), v = fa[v][i];
	if(u == v) return mkp(u, res);
	for(int i = 20; i >= 0; --i)
		if(fa[u][i] != fa[v][i]){
			res = min(res, min(tmin[u][i], tmin[v][i]));
			u = fa[u][i], v = fa[v][i];
		}
	res = min(res,  min(tmin[u][0], tmin[v][0]));
	return mkp(fa[u][0], res);
}

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 1; i < n; ++i){
		static int u, v;
		scanf("%d%d", &u, &v);
		g[u].pb(v);
		g[v].pb(u);
	}
	memset(tmin, 127, sizeof(tmin));
	//tmin[1][0] = 1;
	dfs(1);
	
	int ty, x;
	scanf("%d%d", &ty, &x); x = x % n + 1;
	int now = x, rt = x;
	black[x] = 1;
	q--;
	int last = 0;
	while(q--){
		scanf("%d%d", &ty, &x);
		x = (x + last) % n + 1;
		if(ty == 1){
			auto t = lca(rt, x);
			if (t.fi == rt){
				while(!black[x]) now = min(now, x), black[x] = 1, x = fa[x][0];
			}else{
				while(x != t.fi) now = min(now, x), black[x] = 1, x = fa[x][0];
				while(rt != t.fi) now = min(now, rt), black[rt] = 1, rt = fa[rt][0];
				now = min(now, rt); black[rt] = 1;
			}
		}else{
			auto t = lca(rt, x);
			printf("%d\n", last = min(now, t.se));
		}
	}
	//system("pause");
	return 0;
}