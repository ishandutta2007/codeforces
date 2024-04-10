#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 2e5 + 5, MOD = 1e9 + 7;
int w[MN], st[MN], low[MN], wotbcc[MN], sz[MN], tt;
ll val[MN], dp[MN][2]; //i^{th} node, do you go back?
bool can[MN]; //ree w_i = 0
vector<int> adj[MN], tadj[MN];
set<pii> bridges;
void bridge (int cur, int p = -1) {
	st[cur] = low[cur] = ++tt; vector<int> ree;
	for (int i : adj[cur]) if (i != p) {
		if (!st[i]) {
			bridge(i,cur); ree.push_back(i);
			low[cur] = min(low[cur],low[i]);
		} else low[cur] = min(low[cur],st[i]);
	}
	for (int i : ree) if (low[i] >= st[i]) {
		bridges.insert({cur,i});
	}
}
void getbcc (int cur) {
	val[wotbcc[cur] = tt] += w[cur]; sz[tt]++;
	for (int i : adj[cur]) if (!wotbcc[i] && !bridges.count({cur,i}) && !bridges.count({i,cur})) {
		getbcc(i);
	}
}
void dfs (int cur, int p = -1) {
	for (int i : tadj[cur]) if (i != p) {
		dfs(i,cur);
		dp[cur][1] += dp[i][1];
		can[cur] |= can[i];
	}
	for (int i : tadj[cur]) if (i != p) {
		dp[cur][0] = max(dp[cur][0],dp[cur][1] - dp[i][1] + dp[i][0]);
	}
	can[cur] |= sz[cur] > 1;
	dp[cur][0] += val[cur];
	if (can[cur]) dp[cur][1] += val[cur];
}
int main () { 
	int n,m;
	scanf ("%d %d",&n,&m);
	for (int i = 1; i <= n; i++) scanf ("%d",w+i);
	while (m--) {
		int a,b;
		scanf ("%d %d",&a,&b);
		adj[a].push_back(b); adj[b].push_back(a);
	}
	int s; scanf ("%d",&s);
	bridge(s); tt = 0;
	for (int i = 1; i <= n; i++) if (!wotbcc[i]) {
		++tt;
		getbcc(i);
	}
	for (pii p : bridges) {
		assert(wotbcc[p.first] != wotbcc[p.second]);
		tadj[wotbcc[p.first]].push_back(wotbcc[p.second]);
		tadj[wotbcc[p.second]].push_back(wotbcc[p.first]);
	}
	dfs(wotbcc[s]);
	printf ("%lld\n",dp[wotbcc[s]][0]);
	return 0;
}