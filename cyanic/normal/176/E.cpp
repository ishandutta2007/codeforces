#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
#define per(i,a,b) for (int i=(a); i>=int(b); i--)
#define mp make_pair
#define pb push_back
#define x first
#define y second
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

const int maxn = 100005;
int id[maxn], fa[maxn][18], d[maxn], Q, n, u, v, w, clk; 
vector<pii> e[maxn]; char ch; LL dep[maxn], ans; 
struct Mycmp { 
	bool operator () (const int &a, const int &b) {
		return id[a] < id[b];
	} 
}; set<int, Mycmp> S; set<int, Mycmp>::iterator it, it2;

void dfs(int u) {
	id[u] = ++clk;
	for (pii v : e[u]) if (v.x != fa[u][0]) {
		dep[v.x] = dep[u] + v.y, d[v.x] = d[u] + 1;
		fa[v.x][0] = u, dfs(v.x);
	}
}

int lca(int u, int v) {
	if (d[u] < d[v]) swap(u, v);
	per (i, 17, 0) 
		if (d[fa[u][i]] >= d[v]) u = fa[u][i];
	if (u == v) return u;
	per (i, 17, 0) 
		if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}

LL dist(int u, int v) {
	return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

int main() {
	scanf("%d", &n);
	rep (i, 1, n-1) 
		scanf("%d%d%d", &u, &v, &w), e[u].pb(mp(v, w)), e[v].pb(mp(u, w));
	d[1] = 1; dfs(1); 
	rep (j, 1, 17) rep (i, 1, n)
		fa[i][j] = fa[fa[i][j-1]][j-1];
	scanf("%d", &Q);
	while (Q--) {
		ch = getchar();
		while (ch != '+' && ch != '-' && ch != '?') ch = getchar();
		if (ch == '+') {
			scanf("%d", &u);
			if (!S.empty()) { 
				it = S.lower_bound(u);
				if (it == S.end()) it = S.begin();
				if (it == S.begin()) it2 = --S.end();
				else it2 = it, it2--;
				ans += dist(u, *it) + dist(u, *it2) - dist(*it, *it2);
			}
			S.insert(u);
		}
		else if (ch == '-') {
			scanf("%d", &u);
			it = S.lower_bound(u); S.erase(it++);
			if (!S.empty()) {
				if (it == S.end()) it = S.begin();
				if (it == S.begin()) it2 = --S.end();
				else it2 = it, it2--;
				ans += dist(*it, *it2) - dist(u, *it) - dist(u, *it2);
			}
		}
		else printf("%I64d\n", ans / 2);
	}
	return 0;
}