#include<bits/stdc++.h>
#define pb push_back
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
#define x first
#define y second
using namespace std;
typedef pair<int,int> pii;
const int maxn = 100009;
int g[maxn], rt, _[maxn], s[maxn], v[maxn], n;
vector<int> e[maxn]; vector<pii> p, q;
pii f[maxn][2], ans; 
void dfs(int u) {
	f[u][0] = f[u][1] = pii(0, 0); g[u] = 0; v[u] = 1;
	for (int v : e[u]) {
		if (v == rt) continue;
		dfs(v); f[u][0].x += f[v][1].x; f[u][0].y += f[v][1].y;
		pii t(1 - f[v][1].x + f[v][0].x, (s[u] ^ s[v]) - f[v][1].y + f[v][0].y);
		if (f[u][1] < t) f[u][1] = t, g[u] = v;
	}
	f[u][1].x += f[u][0].x; f[u][1].y += f[u][0].y;
}
void update(int u, int b) {
	for (int v : e[u]) {
		if (v == rt) continue;
		if (!b || g[u] != v) update(v, 1);
		else p.pb(pii(u, v)), update(v, 0);
	} 
}
void solve(int u) {
	for (; !v[u]; u = _[u]) v[u] = 1;
	pii res(0, 0);
	rep (t, 0, 1) {
		rt = u; dfs(u);
		if (res < f[u][1]) res = f[u][1], p.clear(), update(u, 1);
		u = _[u];
	}
	for (pii v : p) q.pb(v);
	ans.x += res.x; ans.y += res.y;
}
int main() {
	scanf("%d", &n);
	rep (i, 1, n) scanf("%d%d", &_[i], &s[i]), --s[i], e[_[i]].pb(i);
	rep (i, 1, n) if (!v[i]) solve(i);
	printf("%d %d\n", ans.x, ans.y);
	for (pii v : q) printf("%d %d\n", v.x, v.y);
	return 0;
}