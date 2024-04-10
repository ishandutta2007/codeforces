#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 2e5+3, MOD = 1e9+7;
int q (char t, int u) {
	printf ("%c %d\n",t,u);
	fflush(stdout);
	scanf ("%d",&u);
	return u;
}
int par[MN], depth[MN], sz[MN],dx; bool done[MN];
vector<int> adj[MN];
void dfs2 (int cur) {
	for (int i : adj[cur]) if (i != par[cur]) {
		par[i] = cur;
		depth[i] = depth[cur] + 1;
		dfs2(i);
	}
}
void dfs (int cur, int p = -1) {
	sz[cur] = 1;
	for (int i : adj[cur]) if (i != p && !done[i]) {
		dfs(i,cur);
		sz[cur] += sz[i];
	}
}
int findcent (int cur, int tsz, int p = -1) {
	for (int i : adj[cur]) if (i != p && !done[i] && sz[i] > (tsz>>1))
		return findcent(i,tsz,cur);
	return cur;
}
void solve (int cur) {
	dfs(cur);
	int cent = findcent(cur,sz[cur]);
	done[cent] = 1;
	int dist = q('d',cent);
	if (dist == 0) return (void) printf ("! %d\n",cent);
	if (depth[cent] + dist != dx) solve(par[cent]);
	else solve(q('s',cent));
}
int main() {
	int n;
	scanf ("%d",&n);
	for (int i = 1; i < n; i++) {
		int a,b;
		scanf ("%d %d",&a,&b);
		adj[a].push_back(b); adj[b].push_back(a);
	}
	dx = q('d',1);
	dfs2(1);
	solve(1);
    return 0;
}