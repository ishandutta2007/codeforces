#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 100005;
int T, n, m, f[N], p[N], fa[N], dep[N];
bool fail, o[N], g[N], vis[N];
vector<int> e[N];
void update(int &a, int &b, int x){
	if(dep[x]<dep[a]) b=a, a=x;
	else if(dep[x]<dep[b]) b=x;
}
pair<int,int> dfs(int u){
	vis[u]=1, o[u]=1;
	int m1=0, m2=0;
	for(int v:e[u])
		if(!vis[v]){
			dep[v]=dep[u]+1, fa[v]=u;
			auto x=dfs(v);
			update(m1, m2, x.first), update(m1, m2, x.second);
		}
		else if(o[v]) update(m1, m2, v);
		else fail=1;
	if(m2==u) m2=0;
	if(m1==u) m1=0;
	if(m1 && !m2) f[u]=m1;
	// printf("dfs: %d %d\n", u, f[u]);
	o[u]=0;
	return make_pair(m1, m2);
}
void dfs2(int u){
	g[u]|=g[f[u]];
	for(int v:e[u]) if(fa[v]==u) dfs2(v);
}
bool check(int x){
	// printf("check: %d\n", x);
	dep[0]=1e9;
	fa[x]=dep[x]=fail=0, memset(f+1, 0, n<<2), memset(vis+1, 0, n), dfs(x);
	if(fail) return 0;
	// printf(">> %d\n", fail);
	memset(g+1, 0, n), g[x]=1, dfs2(x);
	int ans=0;
	for(int i=1; i<=n; ++i) ans+=g[i];
	if(ans*5<n) puts("-1");
	else for(int i=1; i<=n; ++i) if(g[i]) printf("%d%c", i, " \n"[!--ans]);
	return 1;
}
int main() {
	mt19937 rng(chrono::system_clock().now().time_since_epoch().count());
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m);
		for(int i=1, x, y; i<=m; ++i) scanf("%d%d", &x, &y), e[x].push_back(y);
		for(int i=1; i<=n; ++i) p[i]=i;
		shuffle(p+1, p+n+1, rng);
		for(int i=1; i<=100 && i<=n; ++i) if(check(p[i])) break;
		if(fail) puts("-1");
		for(int i=1; i<=n; ++i) e[i].clear();
	}
	return 0;
}