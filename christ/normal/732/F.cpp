#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
using pll = pair<ll,ll>;
using pli = pair<ll,int>;
using pil = pair<int,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define mp make_pair
const int MN = 4e5+2, BASE = 131, MOD = 1e9+7;
int d[MN], low[MN], tt, wotbcc[MN], sz[MN]; bool vis[MN];
struct Edge {int to,a,b;};
vector<int> adj[MN], bcc[MN];vector<Edge> bccadj[MN]; set<int> dir[MN];
void dfs (int cur, int p = -1) {
	d[cur] = low[cur] = ++tt;
	for (int i : adj[cur]) if (i != p) {
		if (!d[i]) {
			dfs(i,cur);
			low[cur] = min(low[cur],low[i]);
			if (low[i] != d[i]) bcc[i].push_back(cur), bcc[cur].push_back(i);
		} else low[cur] = min(low[cur],d[i]), bcc[i].push_back(cur), bcc[cur].push_back(i);
	}	
}
void dfs2 (int cur) {
	vis[cur] = 1; sz[wotbcc[cur] = tt]++;
	for (int i : bcc[cur]) {
		if (!vis[i]) {
			dir[cur].insert(i);
			dfs2(i);
		} else if (!dir[i].count(cur) && !dir[cur].count(i)) {
			dir[cur].insert(i);
		}
	}
}
void dfs3 (int cur, int p = -1) {
	for (Edge &e : bccadj[cur]) if (e.to != p) {
		dir[e.b].insert(e.a);
		dfs3(e.to,cur);
	}
}
int main () { //answer is biggest edge-bcc, you can turn it into an scc, root the bcc tree here and direct all edges upwards
	int n,m;
	scanf ("%d %d",&n,&m); vector<pii> edges;
	while (m--) {
		int a,b; scanf ("%d %d",&a,&b);
		adj[a].push_back(b); adj[b].push_back(a); edges.emplace_back(a,b);
	}
	dfs(1);
	tt = 0;
	for (int i = 1; i <= n; i++) if (!vis[i]) {
		++tt; dfs2(i);
	}
	int mx = 0, wot = -1;
	for (int i = 1; i <= tt; i++) if (sz[i] > mx) {mx = sz[i]; wot = i;}
	printf ("%d\n",mx);
	for (pii p : edges) if (!dir[p.first].count(p.second) && !dir[p.second].count(p.first)) bccadj[wotbcc[p.first]].push_back({wotbcc[p.second],p.first,p.second}), bccadj[wotbcc[p.second]].push_back({wotbcc[p.first],p.second,p.first});
	dfs3(wot);
	for (pii &p : edges) {
		if (dir[p.first].count(p.second)) printf ("%d %d\n",p.first,p.second);
		else printf ("%d %d\n",p.second,p.first);
	}
    return 0;
}