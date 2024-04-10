#include <bits/stdc++.h>
using namespace std;
const int MN = 1e5 + 5;
vector<array<int,2>> adj[MN];
int v[MN], c[MN], par[MN], parid[MN];
set<int> path;
long long s[2], ret[MN];
array<long long,2> tmp[MN], sofar[MN]; //a+bx
bool vis[MN], seen[MN];
int a,b,idx;
void dfs (int cur) {
	vis[cur] = true;
	s[c[cur]] += v[cur];
	for (auto [i,id] : adj[cur]) {
		if (!vis[i]) {
			par[i] = cur;
			parid[i] = id;
			c[i] = c[cur] ^ 1;
			dfs(i);
		} else if (c[i] == c[cur]) {
			a = cur; b = i; idx = id;
		}
	}
}
//v[b] <- v[b] - x, v[a] = v[a] - x = x + c, solve for x...
void solveOdd (int cur) {
	vis[cur] = true;
	for (auto [i,id] : adj[cur]) if (path.count(id) && id != idx && !vis[i]) {
		solveOdd(i);
		seen[id] = true;
		tmp[id] = {v[i] - sofar[i][0],-sofar[i][1]};
		if (i == b) tmp[id][1]--;
		sofar[cur][0] += tmp[id][0];
		sofar[cur][1] += tmp[id][1];
	}
	for (auto [i,id] : adj[cur]) if (id != idx && !vis[i]) {
		solveOdd(i);
		seen[id] = true;
		tmp[id] = {v[i] - sofar[i][0],-sofar[i][1]};
		if (i == b) tmp[id][1]--;
		sofar[cur][0] += tmp[id][0];
		sofar[cur][1] += tmp[id][1];
	}
}
int main () {
	int n,m; scanf ("%d %d",&n,&m);
	for (int i = 1; i <= n; i++) scanf ("%d",&v[i]);
	vector<array<int,2>> edges(m);
	for (int i = 0; i < m; i++) {
		auto &[_a,_b] = edges[i];
		scanf ("%d %d",&_a,&_b);
		adj[_a].push_back({_b,i});
		adj[_b].push_back({_a,i});
	}
	dfs(1);
	memset(vis,false,sizeof vis);
	if (a > 0) { //not bipartite, a -> ... -> b is an odd cycle
		
		{
			int cur = a; vis[a] = true;
			while (cur != 1) {
				cur = par[cur];
				vis[cur] = true;
			}
			cur = b;
			while (!vis[cur]) {
				path.insert(parid[cur]);
				cur = par[cur];
			}
			int cc = a;
			while (cc != cur) {
				path.insert(parid[cc]);
				cc = par[cc];
			}
			memset(vis,false,sizeof vis);
		}
		solveOdd(a);
		assert(sofar[a][1] == 1);
		long long x = (v[a] - sofar[a][0]) / 2;
		printf ("YES\n");
		for (int i = 0; i < m; i++) {
			if (i == idx) printf ("%lld\n",x);
			else if (seen[i]) printf ("%lld\n",tmp[i][0] + x * tmp[i][1]);
			else printf ("0\n");
		}
	} else if (s[0] != s[1]) {
		printf ("NO\n");
	} else {
		idx = -1;
		solveOdd(1);
		printf ("YES\n");
		for (int i = 0; i < m; i++) {
			if (seen[i]) printf ("%lld\n",tmp[i][0]);
			else printf ("0\n");
		}
	}
	return 0;
}